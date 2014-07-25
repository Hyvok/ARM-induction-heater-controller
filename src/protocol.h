#ifndef PROTOCOL_H
#define PROTOCOL_H

/*-----------------------------------------------------------------*/

#include "usart.h"

/*-----------------------------------------------------------------*/

// Parse data received
int8_t parse(struct Usart *usart, void *ptr);

// Process interface
void process(struct Usart *usart, void *ptr);

// Change value that will be sent the next time process() is called
// ch is channel value that will be changed
// 1 = pan, 2 = tilt, 3 = zoom, 4 and 5 are currently unused
void setValueToSend(int32_t val, uint8_t ch);

// Send continuous data packet the next time process() is called
void sendContinuousData(void);

#endif // PROTOCOL_H
