#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>
#include "enable_disable_enum.h"
#include "stm32f30x_new.h"

/*--------------------------------------------------------------------*/
// Interrupt related functions
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Initialize interrupt
//
/* @param irq           Specifies the IRQ channel number in question
 * @param preEmptPrio   Specifies the pre-emption priority for the IRQ channel 
 *                      specified in NVIC_IRQChannel. This parameter can be a 
 *                      value between 0 and 15. A lower priority value 
 *                      indicates a higher priority.
 * @param state         Enable or disable interrupt in question.
 * @param subPrio       Specifies the subpriority level for the IRQ channel 
 *                      specified. This parameter can be a value between 0 and 
 *                      15. A lower priority value indicates a higher priority.
 */
void initInterrupt(IRQn_t irq, uint8_t preEmptPrio, uint8_t subPrio, EN_t state);

/*--------------------------------------------------------------------*/
// Global interrupt enable
//
void enableInterrupts();

/*--------------------------------------------------------------------*/
// Global interrupt disable
//
void disableInterrupts();

#endif // Include guard
