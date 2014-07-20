#ifndef USART_H
#define USART_H

// Macro to setup USART pins by doing following:
// - Set RxD pin as input
// - Set RxD pin to have pullup (it is high when idle)
// - Set the TxD pin value high
// - Set the TxD pin as output
// TODO: fix
#define SETUP_USART( x )						\
	x##_PORT.DIRCLR = x##_RXD_bm;				\
	x##_PORT.x##_RXD_CTRL = PORT_OPC_PULLUP_gc;	\
	x##_PORT.OUTSET = x##_TXD_bm;				\
	x##_PORT.DIRSET = x##_TXD_bm

// Define some usart speeds that are given for initUsart() call
// Calculate usart speed variables at:
// http://prototalk.net/forums/showthread.php?t=188
// TODO: fix
#define USART_19200_BPS		3269, -6		// 0.01% error
#define USART_38400_BPS		3205, -7		// 0.01% error
#define USART_57600_BPS		2094, -7		// 0.01% error
#define USART_115200_BPS	983, -7			// 0.01% error
#define USART_7200_BPS		2206, -4

/*-----------------------------------------------------------------*/
// Usart data structure
//
struct Usart
{
	// Pointer to usart registers
	volatile USART_t *usart;
	// Pointer to port where usart is
	volatile PORT_t *port;
	// 	Receive and transmit buffer size
	const uint8_t rxSize;
	const uint8_t txSize;
	
	// Pointers to receive and transmit buffers
	uint8_t *rx;
	uint8_t *tx;
	
	volatile uint8_t error;				// USART error
	volatile uint8_t received;			// Received bytes
	volatile uint8_t txWrite, txRead;	// Transmit ring buffer position
	uint8_t crc;						// Send CRC
	uint8_t timeout;					// Receive timeout
	uint8_t driverEnable;				// Bitmask to enable half duplex driver
};

// Declare usarts
extern struct Usart controlUsart;

/*-----------------------------------------------------------------*/
// Define receive and transmit buffer sizes
// NOTE: these have to be on power of two!
//
#define SENSORS_USART_RX	128
#define SENSORS_USART_TX	32

/*-----------------------------------------------------------------*/

// Initialize USART
void initUsart( struct Usart *usart, const uint16_t bsel, const int8_t bscale, 
                const uint8_t parity);

// Changes USART settings
void changeUsart(   struct Usart *usart, const uint16_t bsel, 
                    const int8_t bscale, const uint8_t parity);

// Enables usart
void enableUsart(volatile USART_t *usart);
// Disables usart
void disableUsart(volatile USART_t *usart);

// Sets usart to work as half duplex
void setHalfDuplex(struct Usart *usart, const uint8_t driverEnable);

// Returns true(1) if usart is sending data
uint8_t isSending(struct Usart *usart);

// Send data to USART
void send(struct Usart *usart, const uint8_t data);

// Removes received data from beginning of array
void removeData(struct Usart *usart, const uint8_t count);

// Calculates CRC for a buffer
uint8_t calculateCrc(struct Usart *usart, uint8_t size);

#endif // USART_H
