#include "usart.h"
#include "hw.h"
#include "ring_buffer.h"

/*-----------------------------------------------------------------*/

// Define error flags: Framing, Buffer overflow, Parity
#define ANY_ERROR_bm	(USART_FERR_bm | USART_BUFOVF_bm | USART_PERR_bm)

/*-----------------------------------------------------------------*/
// Macro for initializing USART data structures
//
#define DECLARE(x,name,size) struct Usart x = 	\
{												\
	&name, &name##_PORT, size##_RX, size##_TX,	\
	0,0, 0,0,0,0, 0,0,0							\
}

// Declare usart data
DECLARE(sensorsUsart,    SENSORS_USART,     SENSORS_USART);

/*-----------------------------------------------------------------*/
// Define USART receive and transmit buffers
//
uint8_t usartRx[SENSORS_USART_RX];

uint8_t usartTx[SENSORS_USART_TX];

// Pointers to allocate the space
uint8_t *usartRxPtr = usartRx;
uint8_t *usartTxPtr = usartTx;

/*-----------------------------------------------------------------*/
// Initialize USART
//
void initUsart(struct Usart *usart, const uint16_t bsel, const int8_t bscale, const uint8_t parity)
{
	// Set pointers
	usart->rx = usartRxPtr;
	usart->tx = usartTxPtr;
	usartRxPtr += usart->rxSize;
	usartTxPtr += usart->txSize;
	
	// Clear data
	usart->error = 0;
	usart->received = 0;
	usart->txWrite = 0;
	usart->txRead = 0;
	usart->crc = 0;
	usart->timeout = 0;
	usart->driverEnable = 0;
	
	// Change settings
	changeUsart(usart, bsel, bscale, parity);
	
	// Enable usart
	enableUsart(usart->usart);
}

/*-----------------------------------------------------------------*/
// Changes USART settings
//
void changeUsart(struct Usart *usart, const uint16_t bsel, const int8_t bscale, const uint8_t parity)
{
	// Disable interrupts
	uint8_t sreg = CPU_SREG;
	cli();
	
	// Set baud rate
	usart->usart->BAUDCTRLA = (uint8_t)bsel;
	usart->usart->BAUDCTRLB = ((uint8_t)bscale << 4) | (bsel >> 8);
	
	// Set USART format to asynchronous, 8bit, requested parity, 1 stop bit
	usart->usart->CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_CHSIZE_8BIT_gc | parity;
	
	// Restore interrupts
	CPU_SREG = sreg;
}

/*-----------------------------------------------------------------*/
// Enables usart
//
void enableUsart(volatile USART_t *usart)
{
	// Enable receive interrupt
	usart->CTRLA = USART_RXCINTLVL_LO_gc;
	
	// Enable transmitter and receiver
	usart->CTRLB = USART_RXEN_bm | USART_TXEN_bm;
}

/*-----------------------------------------------------------------*/
// Disables usart
//
void disableUsart(volatile USART_t *usart)
{
	// Disable interrupts
	usart->CTRLA = 0;
	
	// Disable transmitter and receiver
	usart->CTRLB = 0;
}

/*-----------------------------------------------------------------*/
// Sets usart to work as half duplex
//
void setHalfDuplex(struct Usart *usart, const uint8_t driverEnable)
{
	// Store driver enable bitmask
	usart->driverEnable = driverEnable;
	
	// Enable TX complete interrupt
	usart->usart->CTRLA |= USART_TXCINTLVL_HI_gc;
	
	// Set DE to output low
	usart->port->OUTCLR = driverEnable;
	usart->port->DIRSET = driverEnable;
}

/*-----------------------------------------------------------------*/
// Returns true if usart is sending data
//
uint8_t isSending(struct Usart *usart)
{
	if (RING_BUFFER_EMPTY(usart->tx) && (usart->usart->STATUS & USART_DREIF_bm))
		return 0;
	return 1;
}

/*-----------------------------------------------------------------*/
// Send data to USART
//
void send(struct Usart *usart, const uint8_t data)
{
	// Enable driver if needed and it is disabled
	if (usart->driverEnable && !(usart->port->OUT & usart->driverEnable))
		usart->port->OUTSET = usart->driverEnable;
	
	// Prevent interrupts during checking usart values
	cli();
	
	// We can send more data data if:
	//  ring buffer is empty and 
	//  data register empty flag (DREIF) is set 
	if (RING_BUFFER_EMPTY(usart->tx) && (usart->usart->STATUS & USART_DREIF_bm))
	{
		// Just send new data
		usart->usart->DATA = data;
	}
	else
	{
		// Enable DRE interrupt
		usart->usart->CTRLA |= USART_DREINTLVL_LO_gc;
		
		// Wait until ring buffer has room
		while ( RING_BUFFER_FULL(usart->tx) )
			sei();
		// Store data to ring buffer
		RING_BUFFER_WRITE( usart->tx, data );
	}
	sei();
	
	// Update send CRC
	usart->crc += data;
}

/*-----------------------------------------------------------------*/
// Removes received data from beginning of array
//
void removeData(struct Usart *usart, const uint8_t count)
{
	cli();
	
	// Move data in queue
	for (uint8_t c=count; c<usart->received; c++)
		usart->rx[c-count] = usart->rx[c];
	
	// Update received count
	usart->received -= count;
	if (usart->received >= usart->rxSize)
		usart->received = 0;
	
	sei();
}

/*-----------------------------------------------------------------*/
// Calculates CRC
//
uint8_t calculateCrc(struct Usart *usart, uint8_t size)
{
	uint8_t crc = 0;
	for (uint8_t c=0; c<size; c++)
		crc += usart->rx[c];
	return 255-crc;
}

/*-----------------------------------------------------------------*/
// USART interrupts
/*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/
// Receive interrupt handler
//
#define USART_RX_ISR(data)								\
	/* Read status flag	*/								\
	uint8_t err = data.usart->STATUS & ANY_ERROR_bm;	\
	if (err)											\
	{													\
		/* Store last error */							\
		data.error = err;								\
		/* Clear the input buffer */					\
		while (data.usart->STATUS & USART_RXCIF_bm)		\
			err = data.usart->DATA;						\
		return;											\
	}													\
	/* Read received data from usart */					\
	data.rx[data.received++] = data.usart->DATA;		\
	if (data.received >= data.rxSize)					\
		data.received = 0

/*-----------------------------------------------------------------*/
// (transmit) Data register empty interrupt handler
//
#define USART_DRE_ISR(data)								\
	/* Check is there more data to send */				\
	if (data.txWrite == data.txRead)					\
	{													\
		/* Disable DRE interrupt */						\
		data.usart->CTRLA &= ~USART_DREINTLVL_gm;		\
		return;											\
	}													\
	/* Send next byte from ring buffer */				\
	data.usart->DATA = RING_BUFFER_READ(data.tx)

/*-----------------------------------------------------------------*/
// Transmit complete interrupt handler
// For half duplex only
//
#define USART_TX_ISR(name)								\
	/* Disable transmitter, enable receiver */			\
	name##_PORT.OUTCLR = name##_DE_bm

/*-----------------------------------------------------------------*/
// Actual interrupts
//
ISR(SENSORS_USART_RXC_vect)	{	USART_RX_ISR(sensorsUsart);	}
ISR(SENSORS_USART_DRE_vect)	{	USART_DRE_ISR(sensorsUsart);	}

