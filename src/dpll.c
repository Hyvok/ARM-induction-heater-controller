#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "stm32f30x_new.h"
#include "macros.h"
#include "dpll.h"
#include "exti.h"
#include "pid_controller.h"
#include "pwm.h"
#include "hw.h"

// Global variables related to digital PLL
typedef enum
{
    REF_LEAD,
    SIG_LEAD,
    NONE_LEAD
} LEAD_t;

#define PREDIV

struct DpllStruct
{
    struct PidController *pid;
    volatile bool isCounting;
    volatile bool isProcessed;
    volatile uint16_t count;
    volatile LEAD_t leading;
    volatile uint32_t sigCount;
    volatile uint32_t refCount;
};

struct DpllStruct dpll = {  NULL, false, true, 0, NONE_LEAD, 0, 0 };

void initDpll()
{
    dpll.pid = initPid(PROP_TERM, DERIV_TERM, INTEG_TERM, 1.0, -1.0);
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
        uint16_t freq = PWM_TIM.ARR;
        float normCount = (float)dpll.count * (float)IN_NORM_FACTOR;

        if(dpll.leading == REF_LEAD)
        {
            normCount *= (-1.0);
        }

        // TODO: float cast? rounding?
        freq += (int16_t)(computePid(normCount) * (float)PWM_STEPS);

        setFreq(&PWM_TIM, freq);
        setPulseWidth(&PWM_TIM, freq/2);
        dpll.isProcessed = true;
    }
}
// Interrupt functions
// Interrupt that fires when we get a capture/compare match from TIM1
void PWM_TIM_IRQH()
{
    // Clear interrupt flag from status register
    // TODO: not sure if needed
    SET_MASK(PWM_TIM.SR, AC_TIM_SR_CC1IF_bm, AC_TIM_SR_CC1IF_DIS_gc);
    SET_MASK(PWM_TIM.SR, AC_TIM_SR_UIF_bm, AC_TIM_SR_UIF_DIS_gc);

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
// Feedback comparator interrupt
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
