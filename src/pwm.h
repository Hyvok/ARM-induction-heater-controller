#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include "stm32f30x_new.h"

/*--------------------------------------------------------------------*/
// PWM related functions
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Set PWM frequency
//
void setFreq(AC_TIM_t* tim, uint16_t val);

/*--------------------------------------------------------------------*/
// Set PWM pulse-width
//
void setPulseWidth(AC_TIM_t* tim, uint16_t val);

#endif // Include guard
