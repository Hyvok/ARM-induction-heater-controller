#ifndef EXTI_H
#define EXTI_H

#include "stm32f30x_new.h"

typedef enum
{
    RISING_EDGE,
    FALLING_EDGE,
    BOTH_EDGES
} EDGE_t;

void initExtiLine(EXTIn_t exti, EDGE_t edge);
void clearExtiLine(EXTIn_t exti);

#endif // Include guard
