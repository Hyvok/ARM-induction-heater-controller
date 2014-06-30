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

// Helper macros
// Set register bits specified by mask to value
#define SET_REG_MASK(reg, mask, val)    (reg = ((reg & ~mask)) | val)

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
void initTimer(AC_TIM_t* tim);

void setPinMode(GPIO_t* port, GPIO_PIN_t pin, GPIO_MODER_t mode)
{
    SET_REG_MASK(   port->MODER, (GPIO_MODER_MODER0_bm << (pin * 2)), 
                    (mode << (pin * 2)));
}
void setPinOutType(GPIO_t* port, GPIO_PIN_t pin, GPIO_OTYPER_t type)
{
    SET_REG_MASK(port->OTYPER, (GPIO_OTYPER_OT0_bm << pin), (type << pin));
}
void setPinOutSpeed(GPIO_t* port, GPIO_PIN_t pin, GPIO_OSPEEDR_t speed)
{
    SET_REG_MASK(   port->OSPEEDR, (GPIO_OSPEEDR_OSPEEDR0_bm << (pin * 2)), 
                    (speed << (pin * 2)));
}
void setPinPull(GPIO_t* port, GPIO_PIN_t pin, GPIO_PUPDR_t pull)
{
    SET_REG_MASK(   port->PUPDR, (GPIO_PUPDR_PUPDR0_bm << (pin * 2)), 
                    (pull << (pin * 2)));
}
void setAltFunct(GPIO_t* port, GPIO_PIN_t pin, GPIO_AFR_t af)
{
    if(pin <= 7)
    {
        SET_REG_MASK(   port->AFRL, (GPIO_AFR_AFR_bm << (pin * 4)), 
                        (af << (pin * 4)));
    }
    else
    {
        SET_REG_MASK(   port->AFRH, (GPIO_AFR_AFR_bm << (pin * 4)), 
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

    // LEDs
    setPinMode(&LED1_PORT, LED1, GPIO_MODER_OUT_gc);
    setPinMode(&LED2_PORT, LED2, GPIO_MODER_OUT_gc);
    setPinMode(&LED3_PORT, LED3, GPIO_MODER_OUT_gc);

    // PWM
    setPinMode(&DRVR_OE_PORT, DRVR_OE, GPIO_MODER_OUT_gc);
    setPin(&DRVR_OE_PORT, DRVR_OE);

    setAltFunct(&PWM_CH1_PORT, PWM_CH1, GPIO_AFR_AF6_gc);
    setAltFunct(&PWM_CH2_PORT, PWM_CH2, GPIO_AFR_AF6_gc);
    setAltFunct(&PWM_CH1N_PORT, PWM_CH1N, GPIO_AFR_AF6_gc);
    setAltFunct(&PWM_CH2N_PORT, PWM_CH2N, GPIO_AFR_AF6_gc);

    setPinMode(&PWM_CH1_PORT, PWM_CH1, GPIO_MODER_AF_gc);
    setPinMode(&PWM_CH2_PORT, PWM_CH2, GPIO_MODER_AF_gc);
    setPinMode(&PWM_CH1N_PORT, PWM_CH1N, GPIO_MODER_AF_gc);
    setPinMode(&PWM_CH2N_PORT, PWM_CH2N, GPIO_MODER_AF_gc);
    
    // Inputs

    // Initialize timers
    initTimer(&PWM_TIMER);
    setPin(&LED1_PORT, LED1);
}
void initTimer(AC_TIM_t* tim)
{
    // Enable line driver
    resetPin(&DRVR_OE_PORT, DRVR_OE);

    SET_REG_MASK(tim->CCMR1, AC_TIM_CCMR1_CC1S_bm, AC_TIM_CCMR1_CC1S_OUT_gc);
    SET_REG_MASK(tim->CCMR1, AC_TIM_CCMR1_CC2S_bm, AC_TIM_CCMR1_CC2S_OUT_gc);
    SET_REG_MASK(tim->CCMR1, AC_TIM_CCMR1_OC1M_bm, AC_TIM_CCMR1_OC1M_PWMM1_gc);
    SET_REG_MASK(tim->CCMR1, AC_TIM_CCMR1_OC2M_bm, AC_TIM_CCMR1_OC2M_PWMM1_gc);
    SET_REG_MASK(tim->ARR, AC_TIM_ARR_ARR_bm, 0x0FFF);
    SET_REG_MASK(tim->CCR1, AC_TIM_CCR1_CCR1_bm, 0xF0);
    SET_REG_MASK(tim->CCR2, AC_TIM_CCR2_CCR2_bm, 0xFF);
    SET_REG_MASK(tim->CCMR1, AC_TIM_CCMR1_OC1PE_bm, AC_TIM_CCMR1_OC1PE_EN_gc);
    SET_REG_MASK(tim->CCMR1, AC_TIM_CCMR1_OC2PE_bm, AC_TIM_CCMR1_OC2PE_EN_gc);
    SET_REG_MASK(tim->CR1, AC_TIM_CR1_ARPE_bm, AC_TIM_CR1_ARPE_BUF_gc);
    SET_REG_MASK(tim->CR1, AC_TIM_CR1_CMS_bm, AC_TIM_CR1_CMS_CENTER1_gc);
    SET_REG_MASK(tim->CCER, AC_TIM_CCER_CC1E_bm, AC_TIM_CCER_CC1E_EN_gc);
    SET_REG_MASK(tim->CCER, AC_TIM_CCER_CC2E_bm, AC_TIM_CCER_CC2E_EN_gc);
    SET_REG_MASK(tim->CCER, AC_TIM_CCER_CC1NE_bm, AC_TIM_CCER_CC1NE_EN_gc);
    SET_REG_MASK(tim->CCER, AC_TIM_CCER_CC2NE_bm, AC_TIM_CCER_CC2NE_EN_gc);
    SET_REG_MASK(tim->EGR, AC_TIM_EGR_UG_bm, AC_TIM_EGR_UG_REINIT_gc);
    SET_REG_MASK(tim->CR1, AC_TIM_CR1_CEN_bm, AC_TIM_CR1_CEN_EN_gc);
    SET_REG_MASK(tim->BDTR, AC_TIM_BDTR_AOE_bm, AC_TIM_BDTR_AOE_EN_gc);
}
// Dummy function to avoid compiler error
void _init() {}
