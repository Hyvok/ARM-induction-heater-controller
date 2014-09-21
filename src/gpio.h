#ifndef GPIO_H
#define GPIO_H

#include "stm32f30x_new.h"

/*--------------------------------------------------------------------*/
// GPIO related functions
/*--------------------------------------------------------------------*/

typedef enum
{
    LOW = 0x00,
    HIGH = 0x01
} PIN_STATE_t;

/*--------------------------------------------------------------------*/
// Set pin mode
//
void setPinMode(GPIO_t* port, GPIO_PIN_t pin, GPIO_MODER_t mode);

/*--------------------------------------------------------------------*/
// Set pin output type
//
void setPinOutType(GPIO_t* port, GPIO_PIN_t pin, GPIO_OTYPER_t type);

/*--------------------------------------------------------------------*/
// Set pin edge speed
//
void setPinOutSpeed(GPIO_t* port, GPIO_PIN_t pin, GPIO_OSPEEDR_t speed);

/*--------------------------------------------------------------------*/
// Set pin pull-up or pull-down
//
void setPinPull(GPIO_t* port, GPIO_PIN_t pin, GPIO_PUPDR_t pull);

/*--------------------------------------------------------------------*/
// Set pin alternate functions
//
void setAltFunct(GPIO_t* port, GPIO_PIN_t pin, GPIO_AFR_t af);

/*--------------------------------------------------------------------*/
// Get input pin state
//
PIN_STATE_t getInPinState(GPIO_t* port, GPIO_PIN_t pin);

/*--------------------------------------------------------------------*/
// Get output pin state
//
PIN_STATE_t getOutPinState(GPIO_t* port, GPIO_PIN_t pin);

/*--------------------------------------------------------------------*/
// Set pin state 
//
void setPin(GPIO_t* port, GPIO_PIN_t pin);

/*--------------------------------------------------------------------*/
// Reset pin state 
//
void resetPin(GPIO_t* port, GPIO_PIN_t pin);

/*--------------------------------------------------------------------*/
// Set whole port state 
//
void setPort(GPIO_t* port, uint16_t val);

#endif // Include guard
