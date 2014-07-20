#include "stm32f30x_new.h"
#include "macros.h"
#include "systick.h"

void (* scheduler)(void);

void initSystick(uint32_t cycles, void (* functPtr)(void))
{
   STK->LOAD = cycles; 
   STK->VAL = 0;

   uint32_t ctrlReg = STK->CTRL;
   SET_MASK(ctrlReg, STK_CTRL_TICKINT_bm, STK_CTRL_TICKINT_EN_gc);
   SET_MASK(ctrlReg, STK_CTRL_ENABLE_bm, STK_CTRL_ENABLE_EN_gc);
   STK->CTRL = ctrlReg;

   scheduler = functPtr;
}
// Interrupt handlers
void SysTick_Handler()
{
    (* scheduler)();
}
