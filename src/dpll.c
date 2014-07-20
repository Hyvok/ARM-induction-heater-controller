#include <stdint.h>
#include <stdbool.h>
#include "stm32f30x_new.h"
#include "macros.h"
#include "dpll.h"
#include "pwm.h"
#include "hw.h"

// Global variables related to digital PLL
typedef enum
{
    REF_LEAD,
    SIG_LEAD,
    NONE_LEAD
} LEAD_t;

volatile bool isCounting = false;
volatile bool isProcessed = true;
volatile uint16_t count = 0;
volatile LEAD_t leading = NONE_LEAD; 
int16_t error = 0;
int16_t lastError = 0;
int16_t filteredError = 0;
uint16_t derivMult = DERIV_TERM;
float propMult = PROP_TERM;

void startIcTimer()
{
    // Enable counter
    SET_MASK(IC_TIM.CR1, AC_TIM_CR1_CEN_bm, AC_TIM_CR1_CEN_EN_gc);
    isCounting = true;
}
uint16_t stopIcTimer()
{
    uint16_t res = 0;

    // Stop counter
    SET_MASK(IC_TIM.CR1, AC_TIM_CR1_CEN_bm, AC_TIM_CR1_CEN_DIS_gc);

    // If the UIF bit is on, the counter has gone over MAX_PERIOD, discard and
    // do not process the result because it is incorrect
    if((IC_TIM.SR & AC_TIM_SR_UIF_bm) == AC_TIM_SR_UIF_EN_gc)
    {
        // Clear flag
        SET_MASK(IC_TIM.SR, AC_TIM_SR_UIF_bm, AC_TIM_SR_UIF_DIS_gc);
        // Set flag so that the erroneous result will not be processed
        isProcessed = true;
        res = 0;
    }
    else
    {
        // Read result
        res = IC_TIM.CNT;
        isProcessed = false;
    }
    // Re-init/null counter
    SET_MASK(IC_TIM.EGR, AC_TIM_EGR_UG_bm, AC_TIM_EGR_UG_REINIT_gc);
    // Clear update flag
    SET_MASK(IC_TIM.SR, AC_TIM_SR_UIF_bm, AC_TIM_SR_UIF_DIS_gc);
    isCounting = false;
    return res;
} 
void computeDpll()
{
    if(!isProcessed)
    {
        if(leading == SIG_LEAD)
        {
            error = count * (-1);
        }
        else if(leading == REF_LEAD)
        {
            error = count;
        }
        filteredError = (error + (error - lastError) * derivMult) * propMult;
        lastError = error;

        uint16_t freq = PWM_TIM.ARR + filteredError;

        setFreq(&PWM_TIM, freq);
        // TODO: fix pulse width!! remember division by zero...
        setPulseWidth(&PWM_TIM, 100);
        isProcessed = true;
    }
}
// Interrupt functions
// Interrupt that fires when we get a capture/compare match from TIM1
void PWM_TIM_IRQH()
{
    // Clear interrupt flag from status register
    // TODO: not sure if needed
    SET_MASK(PWM_TIM.SR, AC_TIM_SR_CC1IF_bm, AC_TIM_SR_CC1IF_DIS_gc);

    if(isCounting)
    {
        // Stop timer only if leading edge is the feedback signal
        if(leading == REF_LEAD)
        {
            count = stopIcTimer();
        }
    }
    else
    {
        startIcTimer();
        leading = SIG_LEAD;
    }
}
// Feedback comparator interrupt
void FB_COMP_IRQH()
{
    // Clear pending interrupt bit
    //EXTI->PR &= ~(0x01 << EXTI_21n);
    //EXTI->PR = 0xFFFFFFFF; 
    EXTI->PR = 0x200000;

    if(isCounting)
    {
        // Stop timer only if leading edge is the PWM signal
        if(leading == SIG_LEAD)
        {
            count = stopIcTimer();
        }
    }
    else
    {
        startIcTimer();
        leading = REF_LEAD;
    }
}
