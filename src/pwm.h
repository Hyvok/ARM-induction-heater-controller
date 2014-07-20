#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include "stm32f30x_new.h"

void setFreq(AC_TIM_t* tim, uint16_t val);
void setPulseWidth(AC_TIM_t* tim, uint16_t val);

#endif // Include guard
