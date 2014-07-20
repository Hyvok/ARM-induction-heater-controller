#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h> 

// Init systick timer to give off interrupts
// @param cycles how many clock cycles per tick (clock is HCLK/8), max. 24bit
// @param functPtr Pointer to function to be run in the systick interrupt
void initSystick(uint32_t cycles, void (* functPtr)(void));

#endif // Include guard
