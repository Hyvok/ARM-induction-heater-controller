#include "clocks.h"
#include "enable_disable_enum.h"
#include "stm32f30x_new.h"

void enableAhbPeriphClk(RCC_AHBENR_t periph, EN_t state)
{
    if(state == ENABLE)
    {
        RCC->AHBENR |= periph;
    }
    else
    {
        RCC->AHBENR &= ~periph;
    }
}
void enableApb1PeriphClk(RCC_APB1ENR_t periph, EN_t state)
{
    if(state == ENABLE)
    {
        RCC->APB1ENR |= periph;
    }
    else
    {
        RCC->APB1ENR &= ~periph;
    }
}
void enableApb2PeriphClk(RCC_APB2ENR_t periph, EN_t state)
{
    if(state == ENABLE)
    {
        RCC->APB2ENR |= periph;
    }
    else
    {
        RCC->APB2ENR &= ~periph;
    }
}
