#include <stdint.h>
#include "stm32f30x_new.h"
#include "enable_disable_enum.h"
#include "interrupts.h"

// TODO: get rid of ugly magic number code
void initInterrupt(IRQn_t irq, uint8_t preEmptPrio, uint8_t subPrio, EN_t state)
{
    uint32_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;

    if(state == ENABLE)
    {
        tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t)0x700))>> 0x08;
        tmppre = (0x4 - tmppriority);
        tmpsub = tmpsub >> tmppriority;

        tmppriority = (uint32_t)preEmptPrio << tmppre;
        tmppriority |=  subPrio & tmpsub;
        tmppriority = tmppriority << 0x04;

        NVIC->IP[irq] = tmppriority;

        // Enable the Selected IRQ Channels
        NVIC->ISER[irq >> 0x05] = (uint32_t)0x01 << (irq & (uint8_t)0x1F);
    }
    else
    {
        // Disable the Selected IRQ Channels
        NVIC->ICER[irq >> 0x05] = (uint32_t)0x01 << (irq & (uint8_t)0x1F);
    }
}
void enableInterrupts()
{
    __asm("CPSIE I");
}
void disableInterrupts()
{
    __asm("CPSID I");
    // Barrier to prevent interrupt to fire on next line due to pipeline
    __asm("ISB");
}
