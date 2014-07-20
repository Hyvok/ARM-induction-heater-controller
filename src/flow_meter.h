#ifndef FLOW_METER_H
#define FLOW_METER_H

// Global variables
// Variable for storing the last SysTick when the counter was reset
uint32_t resetTime = 0;

// All functions take the current SysTick as an argument
// Returns revolutions per minute, period between last time counter was reset
// (=read with getRpm or getFlow or resetFlowMeter)
uint16_t getRpm(uint32_t sysTick);
// Returns flow in liters per minute, period between last time counter was reset
// (=read with getRpm or getFlow or resetFlowMeter)
float getFlow(uint32_t sysTick);
// Initialize flow-meter, starts measuring right away
void initFlowMeter(uint32_t sysTick);
// Reset flow-meter, resets pulse counter
void resetFlowMeter(uint32_t sysTick);

#endif // Include guard
