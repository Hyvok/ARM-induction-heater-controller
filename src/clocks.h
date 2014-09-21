#ifndef CLOCKS_H
#define CLOCKS_H

#include "stm32f30x_new.h"
#include "enable_disable_enum.h"

/*--------------------------------------------------------------------*/
// Clock system related functions 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Enable clock for peripheral in AHB bus
//
void enableAhbPeriphClk(RCC_AHBENR_t periph, EN_t state);

/*--------------------------------------------------------------------*/
// Enable clock for peripheral in APB1 bus
//
void enableApb1PeriphClk(RCC_APB1ENR_t periph, EN_t state);

/*--------------------------------------------------------------------*/
// Enable clock for peripheral in APB2 bus
//
void enableApb2PeriphClk(RCC_APB2ENR_t periph, EN_t state);

#endif // Include guard
