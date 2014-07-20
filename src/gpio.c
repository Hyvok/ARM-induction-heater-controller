#include "gpio.h"
#include "stm32f30x_new.h"
#include "macros.h"

void setPinMode(GPIO_t* port, GPIO_PIN_t pin, GPIO_MODER_t mode)
{
    SET_MASK(   port->MODER, (GPIO_MODER_MODER0_bm << (pin * 2)), 
                    (mode << (pin * 2)));
}
void setPinOutType(GPIO_t* port, GPIO_PIN_t pin, GPIO_OTYPER_t type)
{
    SET_MASK(port->OTYPER, (GPIO_OTYPER_OT0_bm << pin), (type << pin));
}
void setPinOutSpeed(GPIO_t* port, GPIO_PIN_t pin, GPIO_OSPEEDR_t speed)
{
    SET_MASK(   port->OSPEEDR, (GPIO_OSPEEDR_OSPEEDR0_bm << (pin * 2)), 
                    (speed << (pin * 2)));
}
void setPinPull(GPIO_t* port, GPIO_PIN_t pin, GPIO_PUPDR_t pull)
{
    SET_MASK(   port->PUPDR, (GPIO_PUPDR_PUPDR0_bm << (pin * 2)), 
                    (pull << (pin * 2)));
}
void setAltFunct(GPIO_t* port, GPIO_PIN_t pin, GPIO_AFR_t af)
{
    if(pin <= 7)
    {
        SET_MASK(   port->AFRL, (GPIO_AFR_AFR_bm << (pin * 4)), 
                        (af << (pin * 4)));
    }
    else
    {
        SET_MASK(   port->AFRH, (GPIO_AFR_AFR_bm << (pin * 4)), 
                        (af << ((pin - 8) * 4)));
    }
}
PIN_STATE_t getInPinState(GPIO_t* port, GPIO_PIN_t pin)
{
    return (PIN_STATE_t)((port->IDR & (GPIO_IDR_IDR0_bm << pin)) >> pin);
}
PIN_STATE_t getOutPinState(GPIO_t* port, GPIO_PIN_t pin)
{
    return (PIN_STATE_t)((port->ODR & (GPIO_ODR_ODR0_bm << pin)) >> pin);
}
void setPin(GPIO_t* port, GPIO_PIN_t pin)
{
    port->BSRR = (0x01 << pin);
}
void resetPin(GPIO_t* port, GPIO_PIN_t pin)
{
    port->BSRR = ((0x01 << pin) << 16);
}
void setPort(GPIO_t* port, uint16_t val)
{
    port->ODR = val;
}
