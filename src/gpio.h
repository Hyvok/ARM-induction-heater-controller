#ifndef GPIO_H
#define GPIO_H

#include "stm32f30x_new.h"

typedef enum
{
    LOW = 0x00,
    HIGH = 0x01
} PIN_STATE_t;

void setPinMode(GPIO_t* port, GPIO_PIN_t pin, GPIO_MODER_t mode);
void setPinOutType(GPIO_t* port, GPIO_PIN_t pin, GPIO_OTYPER_t type);
void setPinOutSpeed(GPIO_t* port, GPIO_PIN_t pin, GPIO_OSPEEDR_t speed);
void setPinPull(GPIO_t* port, GPIO_PIN_t pin, GPIO_PUPDR_t pull);
void setAltFunct(GPIO_t* port, GPIO_PIN_t pin, GPIO_AFR_t af);
PIN_STATE_t getInPinState(GPIO_t* port, GPIO_PIN_t pin);
PIN_STATE_t getOutPinState(GPIO_t* port, GPIO_PIN_t pin);
void setPin(GPIO_t* port, GPIO_PIN_t pin);
void resetPin(GPIO_t* port, GPIO_PIN_t pin);
void setPort(GPIO_t* port, uint16_t val);

#endif // Include guard
