#include "flow_meter.h"

uint16_t getRpm(uint32_t sysTick)
{
    uint16_t count = FLOW_TIM.CNT;
    uint16_t result = 0;

    result = count / (((sysTick - resetTime) / SYSTICKS_IN_SEC) * 60);
    resetFlowMeter(sysTick);

    return result;
}
float getFlow(uint32_t sysTick)
{
    uint16_t count = FLOW_TIM.CNT;
    float result = 0;
    
    result =    TICKS_PER_L / count / (((sysTick - resetTime) / 
                SYSTICKS_IN_SEC) * 60); 
    resetFlowMeter(sysTick);

    return result;
}
void initFlowMeter(uint32_t sysTick)
{
    // Enable clock
    enableApb1PeriphClk(RCC_APB2ENR_TIM3EN_gc, ENABLE);
    FLOW_TIM.ARR = 0xFFFF;
    SET_MASK(FLOW_TIM.CR1, TIM_CR1_CEN_bm, TIM_CR1_CEN_EN_gc);
    resetTime = sysTick;
}
void resetFlowMeter(uint32_t sysTick)
{
    SET_MASK(FLOW_TIM.CR1, TIM_CR1_CEN_bm, TIM_CR1_CEN_DIS_gc);
    SET_MASK(FLOW_TIM.EGR, TIM_EGR_UG_bm, TIM_EGR_UG_REINIT_gc);
    SET_MASK(FLOW_TIM.CR1, TIM_CR1_CEN_bm, TIM_CR1_CEN_EN_gc);
    resetTime = sysTick;
}
