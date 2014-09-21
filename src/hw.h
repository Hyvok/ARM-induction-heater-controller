/*--------------------------------------------------------------------*/
// Inputs 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Button
//
#define BUTTON_PORT         GPIOA
#define BUTTON		        GPIO_PIN_15_gc

/*--------------------------------------------------------------------*/
// Outputs 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// LEDs 
//
#define LED1_PORT           GPIOA
#define LED1		        GPIO_PIN_12
#define LED2_PORT           GPIOA
#define LED2		        GPIO_PIN_11
#define LED3_PORT           GPIOA
#define LED3		        GPIO_PIN_10
#define LED4_PORT           GPIOB
#define LED4		        GPIO_PIN_15
#define LED5_PORT           GPIOB
#define LED5		        GPIO_PIN_14
#define LED6_PORT           GPIOB
#define LED6		        GPIO_PIN_12

/*--------------------------------------------------------------------*/
// Line driver 
//
#define DRVR_OE_PORT        GPIOB
#define DRVR_OE             GPIO_PIN_10

/*--------------------------------------------------------------------*/
// Gate driver 
//
#define GD_OE_PORT          GPIOA
#define GD_OE               GPIO_PIN_7

/*--------------------------------------------------------------------*/
// Timers 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Main PWM timer
//
#define PWM_TIM             TIM1
#define PWM_CH_CCR          TIM1.CCR1
#define PWM_TIM_IRQH        TIM1_CC_IRQHandler
#define PWM_TIM_UP_IRQH     TIM1_UP_TIM16_IRQHandler
#define PWM_TIM_IRQN        TIM1_CC_IRQn
#define PWM_TIM_UP_IRQN     TIM1_UP_TIM16_IRQn
#define PWM_CH1_PORT        GPIOA
#define PWM_CH1             GPIO_PIN_8
#define PWM_CH1N_PORT       GPIOB
#define PWM_CH1N            GPIO_PIN_13
#define PWM_STEPS           65535 

/*--------------------------------------------------------------------*/
// Comparators
//
#define FB_COMP             COMP1
#define FB_COMP_IRQH        COMP1_2_3_IRQHandler
#define FB_COMP_IRQN        COMP1_2_3_IRQn
#define FB_COMP_EXTIN       EXTI_21n
#define FB_PIN_PORT         GPIOA
#define FB_PIN              GPIO_PIN_0

/*--------------------------------------------------------------------*/
// Digital phase-locked loop 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Timer to use for input capture
//
#define IC_TIM              TIM8

/*--------------------------------------------------------------------*/
// Defines related to digital PLL algorithm
//
#define DEADTIME            0x3F
#define INIT_PWM_FREQ       0x550
#define MAX_PERIOD          0x09C4
#define MIN_PERIOD          0x01F4

/*--------------------------------------------------------------------*/
// IIR filter coefficients
//
#define B0F_TERM            (0.259259)
#define B1F_TERM            (-0.234568)
#define A1F_TERM            (-0.975309)

/*--------------------------------------------------------------------*/
// Frequency division
//
//#define PREDIV
#define FREQ_DIVIDE         10

/*--------------------------------------------------------------------*/
// Low-pass filtering 
//
//#define LOWPASS

/*--------------------------------------------------------------------*/
// Flow-meter 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// Flow meter hardware defines
// TODO: check pins
//
#define FLOW_TIM            TIM3
#define FLOW_PIN_PORT       GPIOA
#define FLOW_PIN            GPIO_PIN_1
#define TICK_PER_L          12

/*--------------------------------------------------------------------*/
// SysTick conf 
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
// SysTick related
//
#define SYSTICKS_IN_SEC     1000

