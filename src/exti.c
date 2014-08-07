#include <stdint.h>
#include "stm32f30x_new.h"
#include "exti.h"

void initExtiLine(EXTIn_t exti, EDGE_t edge)
{
    uint32_t extiNum = exti;
    volatile uint32_t *rtsrReg;
    volatile uint32_t *ftsrReg;
    
    if(extiNum <= 31)
    {
        clearExtiLine(extiNum);
        EXTI->IMR1 = 0x01 << extiNum;
        rtsrReg = &EXTI->RTSR1;
        ftsrReg = &EXTI->FTSR1;
    }
    else if(extiNum <= 33 && extiNum > 31)
    {
        extiNum -= 31;
        clearExtiLine(extiNum);
        EXTI->IMR2 = 0x01 << (extiNum - 31);
        rtsrReg = &EXTI->RTSR2;
        ftsrReg = &EXTI->FTSR2;
    }
    else
    {
        return;
    }
    switch(edge)
    {
        case RISING_EDGE:
            (*rtsrReg) = (0x01 << extiNum);
            break;
        case FALLING_EDGE:
            (*ftsrReg) = (0x01 << extiNum);
            break;
        case BOTH_EDGES:
            (*rtsrReg) = (0x01 << extiNum);
            (*ftsrReg) = (0x01 << extiNum);
            break;
    }
}
inline void clearExtiLine(EXTIn_t exti)
{
    // Clear pending bit by writing 1 the the line in question
    if(exti <= 31)
    {
        EXTI->PR1 = 0x01 << exti;
    }
    else if(exti <= 33)
    {
        EXTI->PR2 = 0x01 << (exti - 31);
    }
}
