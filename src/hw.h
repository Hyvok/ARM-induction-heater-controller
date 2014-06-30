// Inputs 
#define BUTTON_PORT     GPIOA
#define BUTTON		    GPIO_PIN_15_gc

// Outputs
#define LED1_PORT       GPIOA
#define LED1		    GPIO_PIN_12
#define LED2_PORT       GPIOA
#define LED2		    GPIO_PIN_11
#define LED3_PORT       GPIOA
#define LED3		    GPIO_PIN_10
#define LED4_PORT       GPIOB
#define LED4		    GPIO_PIN_15
#define LED5_PORT       GPIOB
#define LED5		    GPIO_PIN_14
#define LED6_PORT       GPIOB
#define LED6		    GPIO_PIN_12

// 74HC125 output enable
#define DRVR_OE_PORT    GPIOB
#define DRVR_OE         GPIO_PIN_10

// Timers
#define PWM_TIMER       TIM1
#define PWM_CH1_PORT    GPIOA
#define PWM_CH1         GPIO_PIN_8
#define PWM_CH2_PORT    GPIOA
#define PWM_CH2         GPIO_PIN_9
#define PWM_CH1N_PORT   GPIOB
#define PWM_CH1N        GPIO_PIN_13
#define PWM_CH2N_PORT   GPIOB
#define PWM_CH2N        GPIO_PIN_0
