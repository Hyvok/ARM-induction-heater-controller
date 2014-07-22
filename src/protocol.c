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
//  File:   thoma_protocol.c
//
//  Author: Kalle Hyvonen, Seppo Raisanen
//
//  Desc:   Thoma communication protocol functions
//
//  ---------------------------------------------------------------------------

#include "thoma_protocol.h"
#include "thoma_commands.h"
#include "usart.h"
#include "quadrature.h"

// Thoma data
const uint8_t thomaId = 2;	// Found Thoma ID number
uint8_t continuousRunning = 0;	// Is continuous measurement running
uint8_t continuousSend = 0;     // Do we need to send a cont data packet
uint8_t continuousAckSent = 0;  // Have we replied to cont. command
uint8_t thomaTan = 0;	        // Command transaction number
uint8_t resetCounter = 0;       // Have we reset the counters
uint8_t channelToReset = 0;     // Which channel we need to reset
uint8_t pingReply = 0;          // Non-zero if we need to reply to ping
uint8_t dataRequested = 0;      // Do we need to reply with data
int32_t panValue = 0;           // Pan value to be sent
int32_t tiltValue = 0;          // Tilt value to be sent
int32_t zoomValue = 0;          // Zoom value to be sent

/*-----------------------------------------------------------------*/
// Function for calculating CRC for the packet

uint8_t thomaCrc(uint8_t *data, uint8_t len)
{
    uint8_t crc = 0;

    for(uint8_t c = 0; c < len; c++)
    {
        crc += data[c];
    }

    return crc - 0x02;

}


/*-----------------------------------------------------------------*/
// Change value to be sent
//
void setValueToSend(int32_t val, uint8_t ch)
{
    switch(ch)
    {
        case 1:
            panValue = val;
            break;
        case 2:
            tiltValue = val;
            break;
        case 3:
            zoomValue = val;
            break;
    }
}

/*-----------------------------------------------------------------*/
// Validate Thoma buffer
//
int8_t validateThomaBuffer(struct Usart *usart)
{
	// Check start byte
	if (usart->rx[0] != START_CMD)
		return -1;		// Start is missing
	
	// Make sure that header is present
	if (usart->received <= HEADER_SIZE)
		return 0;
	
	// Check that we are the one who this packet was supposed to go
	if (!(usart->rx[3] == ADDRESS || usart->rx[3] == 0xFF))
		return -1;		// Target device is wrong

       	if (usart->rx[4] != HOST_ADDR)
        	return -1;		// Host device is wron

	// Check that lenght is valid
	uint8_t len = usart->rx[1] + 2;
	if (len >= SENSORS_USART_RX)
		return -1;
	if (len < HEADER_SIZE)
		return -1;
	
	// Wait that we have received everything
	if (usart->received < len)
		return 0;
	
	// Check CRC
	uint8_t crc = thomaCrc(usart->rx, len-1);
	if (crc != usart->rx[len-1])
		return -1;
	
	// Len bytes of data OK
	return len;
}
/*-----------------------------------------------------------------*/
// Send stored data values
//
void sendThomaData(struct Usart *usart) 
{
		// TODO remove this multiplication after a proper profile has been added to dbrlive
		int32_t panTemp = panValue;
		
		int32_t tiltTemp = tiltValue;
        send(usart, 0);                     // Sync rate, not used
        send(usart, (panTemp>>16)&0xFF);   // Pan data
        send(usart, (panTemp>>8)&0xFF);    // Pan data
        send(usart, (panTemp>>0)&0xFF);    // Pan data
        send(usart, (tiltTemp>>16)&0xFF);  // Tilt data
        send(usart, (tiltTemp>>8)&0xFF);   // Tilt data
        send(usart, (tiltTemp>>0)&0xFF);   // Tilt data
        send(usart, (zoomValue>>16)&0xFF);  // Zoom data
        send(usart, (zoomValue>>8)&0xFF);   // Zoom data
        send(usart, (zoomValue>>0)&0xFF);   // Zoom data
        send(usart, 0);                     // Axis 4 not used
        send(usart, 0);                     // Axis 4 not used
        send(usart, 0);                     // Axis 4 not used
        send(usart, 0);                     // Axis 5 not used
        send(usart, 0);                     // Axis 5 not used
        send(usart, 0);                     // Axis 5 not used
        send(usart, usart->crc);

}

/*-----------------------------------------------------------------*/
// Sends Thoma command with CRC
//
void sendThomaCommand(struct Usart *usart, uint8_t command, uint8_t dataCount, 
                        uint8_t data[], uint8_t tan)
{
    // Get new transaction number
    thomaTan = tan;

    // Calculate data length
    uint8_t sendCount = DATA_OFFS + dataCount;

    // Send command
    send(usart, START_CMD);				// Start command
    usart->crc = 0;					// Thoma CRC does not include start command
    send(usart, sendCount-1);			// Data length
    send(usart, thomaTan);				// Transaction number
    send(usart, HOST_ADDR);				// To
    send(usart, thomaId);				// From
    send(usart, command);				// Command
    for(uint8_t i = 0; i < dataCount; ++i)
    {
        send(usart, data[i]);              // Data, if any
    }
    send(usart, usart->crc);			// CRC
}

/*-----------------------------------------------------------------*/
// Sends Thoma command with CRC
//
void sendThomaCommandHeader(struct Usart *usart, uint8_t command, 
                            uint8_t dataCount, uint8_t to, uint8_t tan)
{
    // Calculate data length
    uint8_t sendCount = DATA_OFFS + dataCount;

    // Send command
    send(usart, START_CMD);    // Start command
    usart->crc = 0;      // Thoma CRC does not include start command
    send(usart, sendCount-1);   // Data length
    send(usart, tan);                   // Transaction number
    send(usart, to);                  // To
    send(usart, ADDRESS);    // From
    send(usart, command);    // Command

}

// Parse data received from Thoma interface
int8_t parseThoma(struct Usart *usart, void *ptr)
{
    // Validate buffer
    int8_t used = validateThomaBuffer( usart );
    if (used <= 0)
        return used;

    // Parse received data
    uint8_t command = usart->rx[5];
    switch (command)
    {
        case REQ_SW_VER:                    // Ping reply
            pingReply = 1;
            thomaTan = usart->rx[2];        // Save TAN 
            break;

        case START_CONTINUOUS:		    // Start continuous measurement
            continuousRunning = 1;
            thomaTan = usart->rx[2];        // Save TAN 
            break;

        case STOP_CONTINUOUS:		    // Stop continuous measurement	
            continuousRunning = 0;
            thomaTan = usart->rx[2];        // Save TAN 
            break;

        case REQ_COUNTERS:		    // Measurement data
            dataRequested = 1;
            thomaTan = usart->rx[2];        // Save TAN 
            break;

        case RESET_COUNTER:		    // Counter reset
            resetCounter = 1;
            thomaTan = usart->rx[2];        // Save TAN 
            channelToReset = usart->rx[6];  // Which channel we need to reset
            break;

        default:
            // Unknown reply
            break;
    }

    // Return used bytes
    return used;

}

void sendContinuousData()
{
    continuousSend = 1;
}
// Process Thoma interface
void processThoma(struct Usart *usart, void *ptr)
{

    // If we need to reply to a ping
    if(pingReply) 
    {
        sendThomaCommandHeader(usart, REQ_SW_VER, 7, HOST_ADDR, thomaTan);
        // TODO: Agree on version info
        send(usart, 1);
        send(usart, 1);
        send(usart, 1);
        send(usart, 0);
        send(usart, 0x32);
        send(usart, 0x01);
        send(usart, 0xF5);
        send(usart, usart->crc);        
        pingReply = 0;
        return;
    }
    // If we are in continuous mode and have not sent and ack, send ack
    if(continuousRunning && !continuousAckSent) 
    {
        sendThomaCommandHeader(usart, START_CONTINUOUS, 1, HOST_ADDR, thomaTan);
        send(usart, 0);
        send(usart, usart->crc);
        continuousAckSent = 1;
        return;
    }
    // If we have replied with an ack, after that reply with data in cont. mode
    if(continuousRunning && continuousAckSent && continuousSend)
    {
        sendThomaCommandHeader(usart, CONTINUOUS_DATA, 16, HOST_ADDR, thomaTan);
        sendThomaData(usart);
        continuousSend = 0;
        return;
    }
    // If data has been requested
    if(dataRequested)
    {
        sendThomaCommandHeader(usart, REQ_COUNTERS, 16, HOST_ADDR, thomaTan);
        sendThomaData(usart);
        dataRequested = 0;
        return;
    }
    if(resetCounter)
    {
        switch(channelToReset)
        {
            case 1:
                panValue = 0;
                rotaryPan.position = 0;
                break;
            case 2:
                tiltValue = 0;
                rotaryTilt.position = 0;
                break;
            case 3:
                zoomValue = 0;
                rotaryZoom.position = 0;
                break;
        }
        sendThomaCommandHeader(usart, RESET_COUNTER, 1, HOST_ADDR, thomaTan);
        send(usart, 0);
        send(usart, usart->crc);
        resetCounter = 0;
    }
}
