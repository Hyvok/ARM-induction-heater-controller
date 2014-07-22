#ifndef CLOCKS_H
#define CLOCKS_H

#include "stm32f30x_new.h"
#include "enable_disable_enum.h"

void enableAhbPeriphClk(RCC_AHBENR_t periph, EN_t state);
void enableApb1PeriphClk(RCC_APB1ENR_t periph, EN_t state);
void enableApb2PeriphClk(RCC_APB2ENR_t periph, EN_t state);

#endif // Include guard
