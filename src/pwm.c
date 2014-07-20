#include <stdint.h>
#include "stm32f30x_new.h"
#include "pwm.h" 

void setFreq(AC_TIM_t* tim, uint16_t val)
{
    tim->ARR = val;
}
void setPulseWidth(AC_TIM_t* tim, uint16_t val)
{
    tim->CCR1 = val;
}
