//  ---------------------------------------------------------------------------
//
//  Copyright (c) 2008-2013 Supponor Oy
//
//  All rights reserved.
//
//  This source code may not be published, copied or redistributed in any
//  form without prior written permission from the owner.
//
//  ---------------------------------------------------------------------------
//
//  File:   thoma_protocol.h
//
//  Author: Kalle Hyvonen, Seppo Raisanen
//
//  Desc:   Thoma communication protocol definitions
//
//  ---------------------------------------------------------------------------

#ifndef THOMA_PROTOCOL_H
#define THOMA_PROTOCOL_H

/*-----------------------------------------------------------------*/

#include "usart.h"

/*-----------------------------------------------------------------*/

// Parse data received from Thoma interface
int8_t parseThoma(struct Usart *usart, void *ptr);

// Process Thoma interface
void processThoma(struct Usart *usart, void *ptr);

// Change value that will be sent the next time processThoma() is called
// ch is channel value that will be changed
// 1 = pan, 2 = tilt, 3 = zoom, 4 and 5 are currently unused
void setValueToSend(int32_t val, uint8_t ch);

// Send continuous data packet the next time processThoma() is called
void sendContinuousData(void);

#endif // THOMA_PROTOCOL_H
