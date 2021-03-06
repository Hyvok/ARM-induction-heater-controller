#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "stm32f30x_new.h"
#include "macros.h"
#include "dpll.h"
#include "exti.h"
#include "iir_filter.h"
#include "pwm.h"
#include "hw.h"

/*--------------------------------------------------------------------*/
// Digital phase-locked loop 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Global variables related to digital PLL
//
typedef enum
{
    REF_LEAD,
    SIG_LEAD,
    NONE_LEAD
} LEAD_t;

struct DpllStruct
{
    struct IirFilter* iir;
    volatile bool isCounting;
    volatile bool isProcessed;
    volatile uint16_t count;
    volatile LEAD_t leading;
    volatile uint32_t sigCount;
    volatile uint32_t refCount;
    volatile bool requestUpdate;
    volatile int16_t frequency;
    float lastCount;
};

struct DpllStruct dpll = { NULL, false, true, 0, NONE_LEAD, 0, 0, false, 0, 0 };

void initDpll()
{
    dpll.iir = initIirFilter(B0F_TERM, B1F_TERM, A1F_TERM);
    dpll.frequency = PWM_TIM.ARR;
}
void startIcTimer()
{
    // Enable dpll.counter
    SET_MASK(IC_TIM.CR1, AC_TIM_CR1_CEN_bm, AC_TIM_CR1_CEN_EN_gc);
}
uint16_t stopIcTimer()
{
    uint16_t res = 0;

    // Stop dpll.counter
    SET_MASK(IC_TIM.CR1, AC_TIM_CR1_CEN_bm, AC_TIM_CR1_CEN_DIS_gc);

    // If the UIF bit is on, the dpll.counter has gone over MAX_PERIOD, discard and
    // do not process the result because it is incorrect
    if((IC_TIM.SR & AC_TIM_SR_UIF_bm) == AC_TIM_SR_UIF_EN_gc)
    {
        // Clear flag
        SET_MASK(IC_TIM.SR, AC_TIM_SR_UIF_bm, AC_TIM_SR_UIF_DIS_gc);
        // Set flag so that the erroneous result will not be processed
        dpll.isProcessed = true;
        res = 0;
    }
    else
    {
        // Read result
        res = IC_TIM.CNT;
        dpll.isProcessed = false;
    }
    // Re-init/null dpll.counter
    SET_MASK(IC_TIM.EGR, AC_TIM_EGR_UG_bm, AC_TIM_EGR_UG_REINIT_gc);
    // Clear update flag
    SET_MASK(IC_TIM.SR, AC_TIM_SR_UIF_bm, AC_TIM_SR_UIF_DIS_gc);
    return res;
} 
void computeDpll()
{
    if(!dpll.isProcessed)
    {
        float normCount = (float)dpll.count;

#ifdef LOWPASS
        normCount += dpll.lastCount;
        dpll.lastCount = normCount;
#endif

        if(dpll.leading == REF_LEAD)
        {
            normCount *= (-1.0);
        }

        // TODO: rounding?
        dpll.frequency = (int)(computeIirFilter(normCount) + PWM_STEPS);

        if(dpll.frequency > MAX_PERIOD)
            dpll.frequency = MAX_PERIOD;
        else if(dpll.frequency < MIN_PERIOD)
            dpll.frequency = MIN_PERIOD;

        dpll.isProcessed = true;
        dpll.requestUpdate = true;
    }
}
/*--------------------------------------------------------------------*/
// Interrupts 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Interrupt that fires when we get a capture/compare match from PWM_TIM 
//
void PWM_TIM_IRQH()
{
    // Clear interrupt flag from status register
    // TODO: not sure if needed
    SET_MASK(PWM_TIM.SR, AC_TIM_SR_CC1IF_bm, AC_TIM_SR_CC1IF_DIS_gc);

    #ifdef PREDIV
    if(dpll.refCount < FREQ_DIVIDE)
    {
        ++dpll.refCount;
        return;
    }

    dpll.refCount = 0;
#endif

    if(dpll.isCounting)
    {
        // Stop timer only if dpll.leading edge is the feedback signal
        if(dpll.leading == REF_LEAD)
        {
            dpll.count = stopIcTimer();
            dpll.isCounting = false;
        }
    }
    else
    {
        startIcTimer();
        dpll.isCounting = true;
        dpll.leading = SIG_LEAD;
    }
}
/*--------------------------------------------------------------------*/
// Interrupt that fires when we get an update event from PWM_TIM
//
void PWM_TIM_UP_IRQH()
{
    // Clear flag
    SET_MASK(PWM_TIM.SR, AC_TIM_SR_UIF_bm, AC_TIM_SR_UIF_DIS_gc);

    if(!dpll.requestUpdate)
        return;

    //uint16_t newPeriod = PWM_TIM.ARR + dpll.frequency;
    uint16_t newPeriod = dpll.frequency;

    // Set new values
    setFreq(&PWM_TIM, newPeriod);
    setPulseWidth(&PWM_TIM, newPeriod/2);

    dpll.frequency = newPeriod;

    // Clear update request
    dpll.requestUpdate = false;
}
/*--------------------------------------------------------------------*/
// Feedback comparator interrupt
//
void FB_COMP_IRQH()
{
    // Clear pending interrupt bit
    clearExtiLine(FB_COMP_EXTIN);

    #ifdef PREDIV
    if(dpll.sigCount < FREQ_DIVIDE)
    {
        ++dpll.sigCount;
        return;
    }

    dpll.sigCount = 0;
#endif

    if(dpll.isCounting)
    {
        // Stop timer only if dpll.leading edge is the PWM signal
        if(dpll.leading == SIG_LEAD)
        {
            dpll.count = stopIcTimer();
            dpll.isCounting = false;
        }
    }
    else
    {
        startIcTimer();
        dpll.isCounting = true;
        dpll.leading = REF_LEAD;
    }
}
