#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stm32f30x_new.h"
#include "hw.h"

// Initial guess for the TIMx_ARR register, sets frequency, 
// depends on timer clock speed
#define PWM_FREQ_REG 0x8000
// Initial guess for the TIMx_CCRn register, sets pulse width, 
// depends on timer clock speed
#define PWM_PW_REG 0x8000

typedef enum
{

    LOW = 0x00,
    HIGH = 0x01

} PIN_STATE_t;

typedef enum
{

    DISABLE,
    ENABLE

} EN_t;

// Private function prototypes
void Delay(void);
void init();
//void initTimer(TIM_TypeDef* timer);

void setPinMode(GPIO_t* port, GPIO_PIN_t pin, GPIO_MODER_t mode)
{

    port->MODER |= ((GPIO_MODER_MODER0_bm << (pin * 2)) & (mode << (pin * 2)));

}

void setPinOutType(GPIO_t* port, GPIO_PIN_t pin, GPIO_OTYPER_t type)
{

    port->OTYPER |= ((GPIO_OTYPER_OT0_bm << pin) & (type << pin));

}

void setPinOutSpeed(GPIO_t* port, GPIO_PIN_t pin, GPIO_OSPEEDR_t speed)
{

    port->OSPEEDR |=    ((GPIO_OSPEEDR_OSPEEDR0_bm << (pin * 2)) & 
                        (speed << (pin * 2)));

}

void setPinPull(GPIO_t* port, GPIO_PIN_t pin, GPIO_PUPDR_t pull)
{

    port->PUPDR |= ((GPIO_PUPDR_PUPDR0_bm << (pin * 2)) & (pull << (pin * 2)));

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

    port->BSRR = (0x01<<pin);

}

void resetPin(GPIO_t* port, GPIO_PIN_t pin)
{

    port->BSRR = ((0x01<<pin)<<16);

}

void setPort(GPIO_t* port, uint16_t val)
{

    port->ODR = val;

}

void enableAhbPeriphClk(RCC_AHBENR_t periph, EN_t state)
{

    if(state == ENABLE)
    {
        RCC->AHBENR |= periph;
    }
    else
    {
        RCC->AHBENR &= ~periph;
    }

}

void enableApb1PeriphClk(RCC_APB1ENR_t periph, EN_t state)
{

    if(state == ENABLE)
    {
        RCC->APB1ENR |= periph;
    }
    else
    {
        RCC->APB1ENR &= ~periph;
    }

}

void enableApb2PeriphClk(RCC_APB2ENR_t periph, EN_t state)
{

    if(state == ENABLE)
    {
        RCC->APB2ENR |= periph;
    }
    else
    {
        RCC->APB2ENR &= ~periph;
    }

}

static void SetSysClock()
{

    uint32_t startUpCounter = 0, hsiStatus = 0;

    // Enable HSI
    RCC->CR |= RCC_CR_HSION_ON_gc;

    // Wait till HSI is ready and if timeout is reached, exit
    do
    {
        hsiStatus = (RCC->CR & RCC_CR_HSIRDY_bm);
        startUpCounter++;  
    } while((hsiStatus == 0) && (startUpCounter != HSI_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSIRDY_bm) != 0)
    {
        hsiStatus = 1;
    }
    else
    {
        hsiStatus = 0;
    }  

    if (hsiStatus == 1)
    {
        // Enable Prefetch Buffer and set flash Latency
        FLASH->ACR = (FLASH_ACR_PRFTBE_EN_gc | FLASH_ACR_LATENCY_1_gc);

        // HCLK = SYSCLK, PCLK1, PCLK2 = HCLK
        RCC->CFGR |= (  RCC_CFGR_HPRE_NODIV_gc | RCC_CFGR_PPRE2_NODIV_gc |
                        RCC_CFGR_PPRE1_DIVBY2_gc);

        // PLL configuration: PLLCLK = HSI * 9 = 72 MHz
        RCC->CFGR |= (RCC_CFGR_PLLSRC_HSIDIVBY2_gc | RCC_CFGR_PLLMUL_9_gc);

        // Enable PLL
        RCC->CR |= RCC_CR_PLLON_ON_gc;

        // Wait till PLL is ready
        while((RCC->CR & RCC_CR_PLLRDY_bm) == 0) {}

        // Select PLL as system clock source
        RCC->CFGR &= (~(RCC_CFGR_SW_bm));
        RCC->CFGR |= RCC_CFGR_SW_PLL_gc;    

        // Wait till PLL is used as system clock source
        while ((RCC->CFGR & RCC_CFGR_SWS_bm) != RCC_CFGR_SWS_PLL_gc) {}
    }
    else
    { 
        /* If HSI fails to start-up, the application will have wrong clock 
         configuration. User can add here some code to deal with this error */
    }

}

void SystemInit()
{

    #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    // FPU settings, set CP10 and CP11 full access
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));
    #endif

    // Configure the clocks
    SetSysClock();

    #ifdef VECT_TAB_SRAM
    SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM. */
    #else
    SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH. */
    #endif  

}

int main(void) 
{

    SystemInit();
    init();

	for(;;) 
    {
    }

	return 0;

}

void init() {

    // Clocks
    enableAhbPeriphClk(RCC_AHBENR_IOPAEN_gc, ENABLE);
    enableAhbPeriphClk(RCC_AHBENR_IOPBEN_gc, ENABLE);
    enableApb2PeriphClk(RCC_APB2ENR_TIM1EN_gc, ENABLE);

    // Port A
    setPinMode(&GPIOA, LED1, GPIO_MODER_OUT_gc);
    setPinMode(&GPIOA, LED2, GPIO_MODER_OUT_gc);
    setPinMode(&GPIOA, LED3, GPIO_MODER_OUT_gc);
    
    setPinOutType(&GPIOA, LED1, GPIO_OTYPER_PP_gc);
    setPinOutType(&GPIOA, LED2, GPIO_OTYPER_PP_gc);
    setPinOutType(&GPIOA, LED3, GPIO_OTYPER_PP_gc);

    setPinOutSpeed(&GPIOA, LED1, GPIO_OSPEEDR_LOW_gc);
    setPinOutSpeed(&GPIOA, LED2, GPIO_OSPEEDR_LOW_gc);
    setPinOutSpeed(&GPIOA, LED3, GPIO_OSPEEDR_LOW_gc);

    setPinPull(&GPIOA, LED1, GPIO_PUPDR_PULLUP_gc);
    setPinPull(&GPIOA, LED2, GPIO_PUPDR_PULLUP_gc);
    setPinPull(&GPIOA, LED3, GPIO_PUPDR_PULLUP_gc);

    // Port B

    // Inputs

    setPin(&GPIOA, LED1);
    setPin(&GPIOA, LED2);
    setPin(&GPIOA, LED3);

    // Initialize timers
    //initTimer(PWM_TIMER);
    //GPIO_SetBits(LED1_PORT, LED1);

}

/*void initTimer(TIM_TypeDef* timer)
{

    // Set the frequency to the auto-preload register
    timer->ARR = (0xFFFF & PWM_FREQ_REG);
    // Set the pulse width to the capture/compare register
    // TODO: remove channel specific settings and make separate init
    timer->CCR1 = (0xFFFF & PWM_PW_REG);
    timer->CCR2 = (0xFFFF & PWM_PW_REG);
    // Set timer to center-aligned mode 1, OC flags set when counting down
    timer->CCMR1 |= (TIM_CCMR1_OC1M & (0x06<<4));
    timer->CCMR1 |= (TIM_CCMR1_OC2M & (0x06<<12));
    // Set OCxPE bit to enable preload register
    // TODO: channel specific
    timer->CCMR1 |= (TIM_CCMR1_OC1PE | TIM_CCMR1_OC2PE);
    // Enable auto-reload preload
    timer->CR1 |= TIM_CR1_ARPE;
    // Set UG bit to cause update event to initialize the registers
    timer->EGR = TIM_EGR_UG;
    // Enable counter 
    timer->CR1 |= TIM_CR1_CEN;
    
    // Set output compares, channels have to be OFF to set CCnS register 
    //timer->CCMR1 |= (TIM_CCMR1_CC1S & 0x00);

    // Enable output compare channels
    // TODO: channel specific
    timer->CCER = ( TIM_CCER_CC1E | TIM_CCER_CC1NE | 
                    TIM_CCER_CC2E | TIM_CCER_CC2NE);

    // Enable correct output pin alternate functions
    // Configure pins as outputs
    ((GPIO_TypeDef*)GPIOA)->MODER |= (GPIO_MODER_MODER8_0 | GPIO_MODER_MODER9_0);
    ((GPIO_TypeDef*)GPIOB)->MODER |= (GPIO_MODER_MODER0_0 | GPIO_MODER_MODER13_0);
    // PA8
    ((GPIO_TypeDef*)GPIOA)->AFR[1] |= (GPIO_AFRH_AFRH0 & GPIO_AF_6);
    // PA9
    ((GPIO_TypeDef*)GPIOA_BASE)->AFR[1] |= (GPIO_AFRH_AFRH1 & (GPIO_AF_6<<4));
    // PB13
    ((GPIO_TypeDef*)GPIOB_BASE)->AFR[1] |= (GPIO_AFRH_AFRH5 & (GPIO_AF_6<<20));
    // PB0
    ((GPIO_TypeDef*)GPIOB_BASE)->AFR[0] |= (GPIO_AFRL_AFRL0 & GPIO_AF_6);

    // Main output enable
    timer->BDTR = TIM_BDTR_MOE;

}*/

// Dummy function to avoid compiler error
void _init() {}
