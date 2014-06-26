/* New header for the STM32F30x series of ARM Cortex-M4 microcontrollers. */

// Memory type defines
#define _MMIO_DWORD(mem_addr) (*(volatile uint32_t *)(mem_addr))

#define _SFR_MEM32(mem_addr) _MMIO_DWORD(mem_addr)

typedef volatile uint32_t register32_t;
typedef volatile uint16_t register16_t;
typedef volatile uint8_t register8_t;

// Registers for advanced control timers TIM1 and TIM8
typedef struct 
{

    register32_t CR1;                       // Control register 1, 0x00
    register32_t CR2;                       // Control register 2, 0x04
    register32_t SMCR;                      // Slave mode control register, 0x08
    register32_t DIER;                      // DMA/enable interrupt register, 0x0C
    register32_t SR;                        // Status register, 0x10
    register32_t EGR;                       // Event generation register, 0x14
    register32_t CCMR1;                     // Capture/compare mode register 1, 0x18
    register32_t CCMR2;                     // Capture/compare mode register 2, 0x1C
    register32_t CCER;                      // Capture/compare enable register, 0x20
    register32_t CNT;                       // Counter, 0x24
    register32_t PSC;                       // Prescaler, 0x28
    register32_t ARR;                       // Auto-reload register, 0x2C
    register32_t RCR;                       // Repetition counter register, 0x30
    register32_t CCR1;                      // Capture/compare register 1, 0x34
    register32_t CCR2;                      // Capture/compare register 2, 0x38
    register32_t CCR3;                      // Capture/compare register 3, 0x3C
    register32_t CCR4;                      // Capture/compare register 4, 0x40
    register32_t BDTR;                      // Break and dead-time register, 0x44
    register32_t DCR;                       // DMA control register, 0x48
    register32_t DMAR;                      // DMA address for full transfer, 0x4C
    register32_t reserved_0x50;
    register32_t CCMR3;                     // Capture/compare mode register 3, 0x54
    register32_t CCR5;                      // Capture/compare register 5, 0x58
    register32_t CCR6;                      // Capture/compare register 6, 0x5C
    register32_t OR;                        // Option registers, 0x60

} AC_TIM_t;

typedef struct 
{

    register32_t MODER;                     // GPIO port mode register, 0x00 
    register16_t OTYPER;                    // GPIO port output type register, 0x04 
    register16_t reserved_0x06;             // Reserved, 0x06 
    register32_t OSPEEDR;                   // GPIO port output speed register, 0x08 
    register32_t PUPDR;                     // GPIO port pull-up/pull-down register, 0x0C 
    register16_t IDR;                       // GPIO port input data register, 0x10 
    register16_t reserved_0x12;             // Reserved, 0x12 
    register16_t ODR;                       // GPIO port §output data register, 0x14 
    register16_t reserved_0x16;             // Reserved, 0x16 
    register32_t BSRR;                      // GPIO port bit set/reset register, 0x18 
    register32_t LCKR;                      // GPIO port configuration lock register, 0x1C 
    register32_t AFRL;                      // GPIO alternate function low register, 0x20-0x24 
    register32_t AFRH;                      // GPIO alternate function low register, 0x20-0x24 
    register16_t BRR;                       // GPIO bit reset register, 0x28 
    register16_t reserved_0x2A;             // Reserved, 0x2A 

} GPIO_t;

// TODO: check this
typedef struct 
{

    register32_t CR;         /*!< RCC clock control register,                                  Address offset: 0x00 */
    register32_t CFGR;       /*!< RCC clock configuration register,                            Address offset: 0x04 */
    register32_t CIR;        /*!< RCC clock interrupt register,                                Address offset: 0x08 */
    register32_t APB2RSTR;   /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
    register32_t APB1RSTR;   /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
    register32_t AHBENR;     /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
    register32_t APB2ENR;    /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
    register32_t APB1ENR;    /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
    register32_t BDCR;       /*!< RCC Backup domain control register,                          Address offset: 0x20 */
    register32_t CSR;        /*!< RCC clock control & status register,                         Address offset: 0x24 */
    register32_t AHBRSTR;    /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
    register32_t CFGR2;      /*!< RCC clock configuration register 2,                          Address offset: 0x2C */
    register32_t CFGR3;      /*!< RCC clock configuration register 3,                          Address offset: 0x30 */

} RCC_t;

typedef enum
{

    RCC_AHBENR_ADC34EN_gc = (0x01<<29),        /*!< ADC1/ ADC2 clock enable */
    RCC_AHBENR_ADC12EN_gc = (0x01<<28),        /*!< ADC1/ ADC2 clock enable */
    RCC_AHBENR_TSCEN_gc = (0x01<<24),        /*!< TS clock enable */
    RCC_AHBENR_IOPFEN_gc = (0x01<<22),
    RCC_AHBENR_IOPEEN_gc = (0x01<<21),
    RCC_AHBENR_IOPDEN_gc = (0x01<<20),
    RCC_AHBENR_IOPCEN_gc = (0x01<<19),
    RCC_AHBENR_IOPBEN_gc = (0x01<<18),        /*!< GPIOB clock enable */
    RCC_AHBENR_IOPAEN_gc = (0x01<<17),        /*!< GPIOA clock enable */
    RCC_AHBENR_CRCEN_gc = (0x01<<6),        /*!< CRC clock enable */
    RCC_AHBENR_FLITFEN_gc = (0x01<<4),        /*!< FLITF clock enable */
    RCC_AHBENR_SRAMEN_gc = (0x01<<2),        /*!< SRAM interface clock enable */
    RCC_AHBENR_DMA2EN_gc = (0x01<<1),        /*!< DMA2 clock enable */

} RCC_AHBENR_t;

typedef enum
{

    RCC_APB2ENR_TIM17EN_gc = (0x01<<18),        /*!< TIM17 clock enable */
    RCC_APB2ENR_TIM16EN_gc = (0x01<<17),        /*!< TIM16 clock enable */
    RCC_APB2ENR_TIM15EN_gc = (0x01<<16),        /*!< TIM16 clock enable */
    RCC_APB2ENR_USART1EN_gc = (0x01<<14),        /*!< USART1 clock enable */
    RCC_APB2ENR_TIM8EN_gc = (0x01<<13),        /*!< TIM8 clock enable */
    RCC_APB2ENR_SPI1EN_gc = (0x01<<12),        /*!< SPI1 clock enable */
    RCC_APB2ENR_TIM1EN_gc = (0x01<<11),        /*!< TIM1 clock enable */
    RCC_APB2ENR_SYSCFGEN_gc = (0x01<<0),

} RCC_APB2ENR_t;

typedef enum
{

    RCC_APB1ENR_DAC1EN_gc = (0x01<<29),        /*!< DAC clock enable */
    RCC_APB1ENR_PWREN_gc = (0x01<<28),        /*!< PWR clock enable */
    RCC_APB1ENR_DAC2EN_gc = (0x01<<26),        /*!< DAC 2 clock enable */
    RCC_APB1ENR_CANEN_gc = (0x01<<25),        /*!< CAN clock enable */
    RCC_APB1ENR_USBEN_gc = (0x01<<23),        /*!< USB clock enable */
    RCC_APB1ENR_I2C2EN_gc = (0x01<<22),        /*!< I2C 2 clock enable */
    RCC_APB1ENR_I2C1EN_gc = (0x01<<21),        /*!< I2C 1 clock enable */
    RCC_APB1ENR_UART5EN_gc = (0x01<<20),        /*!< UART 5 clock enable */
    RCC_APB1ENR_UART4EN_gc = (0x01<<19),        /*!< UART 4 clock enable */
    RCC_APB1ENR_USART3EN_gc = (0x01<<18),        /*!< USART 3 clock enable */
    RCC_APB1ENR_USART2EN_gc = (0x01<<17),        /*!< USART 2 clock enable */
    RCC_APB1ENR_SPI3EN_gc = (0x01<<15),        /*!< SPI3 clock enable */
    RCC_APB1ENR_SPI2EN_gc = (0x01<<14),        /*!< SPI2 clock enable */
    RCC_APB1ENR_WWDGEN_gc = (0x01<<11),        /*!< Window Watchdog clock enable */
    RCC_APB1ENR_TIM7EN_gc = (0x01<<5),        /*!< Timer 7 clock enable */
    RCC_APB1ENR_TIM6EN_gc = (0x01<<4),        /*!< Timer 6 clock enable */
    RCC_APB1ENR_TIM4EN_gc = (0x01<<2),        /*!< Timer 4 clock enable */
    RCC_APB1ENR_TIM3EN_gc = (0x01<<1),        /*!< Timer 3 clock enable */
    RCC_APB1ENR_TIM2EN_gc = (0x01<<0),        /*!< Timer 2 clock enable */

} RCC_APB1ENR_t;

typedef enum
{

    RCC_CR_PLLRDY_LOCKED_gc = (0x01<<25),
    RCC_CR_PLLRDY_UNLOCKED_gc = (0x00<<25),
    RCC_CR_PLLON_ON_gc = (0x01<<24),
    RCC_CR_PLLON_OFF_gc = (0x00<<24),
    RCC_CR_CSSON_ON_gc = (0x01<<19),
    RCC_CR_CSSON_OFF_gc = (0x00<<19),
    RCC_CR_HSEBYP_BYPASS_gc = (0x01<<18),
    RCC_CR_HSEBYP_NOBYPASS_gc = (0x00<<18),
    RCC_CR_HSERDY_RDY_gc = (0x01<<17),
    RCC_CR_HSERDY_NOTRDY_gc = (0x00<<17),
    RCC_CR_HSEON_ON_gc = (0x01<<16),
    RCC_CR_HSEON_OFF_gc = (0x00<<16),
    RCC_CR_HSIRDY_RDY_gc = (0x01<<1),
    RCC_CR_HSIRDY_NOTRDY_gc = (0x00<<1),
    RCC_CR_HSION_ON_gc = (0x01),
    RCC_CR_HSION_OFF_gc = (0x00)

} RCC_CR_t;

typedef enum
{

    RCC_CFGR_PLLNODIV_NODIV_gc = (0x01<<31),
    RCC_CFGR_PLLNODIV_DIVBY2_gc = (0x00<<31),
    RCC_CFGR_MCOPRE_DIVBY1_gc = (0x00<<29),
    RCC_CFGR_MCOPRE_DIVBY2_gc = (0x01<<29),
    RCC_CFGR_MCOPRE_DIVBY4_gc = (0x02<<29),
    RCC_CFGR_MCOPRE_DIVBY8_gc = (0x03<<29),
    RCC_CFGR_MCOPRE_DIVBY16_gc = (0x04<<29),
    RCC_CFGR_MCOPRE_DIVBY32_gc = (0x05<<29),
    RCC_CFGR_MCOPRE_DIVBY64_gc = (0x06<<29),
    RCC_CFGR_MCOPRE_DIVBY128_gc = (0x07<<29),
    RCC_CFGR_MCO_DIS_gc = (0x00<<24),
    RCC_CFGR_MCO_LSI_gc = (0x02<<24),
    RCC_CFGR_MCO_LSE_gc = (0x03<<24),
    RCC_CFGR_MCO_SYSCLK_gc = (0x04<<24),
    RCC_CFGR_MCO_HSI_gc = (0x05<<24),
    RCC_CFGR_MCO_HSE_gc = (0x06<<24),
    RCC_CFGR_MCO_PLL_gc = (0x07<<24),
    RCC_CFGR_I2SSRC_SYS_gc = (0x00<<23),
    RCC_CFGR_I2SSRC_EXT_gc = (0x01<<23),
    RCC_CFGR_USBPRE_DIV_gc = (0x00<<22),
    RCC_CFGR_USBPRE_NODIV_gc = (0x01<<22),
    RCC_CFGR_PLLMUL_2_gc = (0x00<<18),
    RCC_CFGR_PLLMUL_3_gc = (0x01<<18),
    RCC_CFGR_PLLMUL_4_gc = (0x02<<18),
    RCC_CFGR_PLLMUL_5_gc = (0x03<<18),
    RCC_CFGR_PLLMUL_6_gc = (0x04<<18),
    RCC_CFGR_PLLMUL_7_gc = (0x05<<18),
    RCC_CFGR_PLLMUL_8_gc = (0x06<<18),
    RCC_CFGR_PLLMUL_9_gc = (0x07<<18),
    RCC_CFGR_PLLMUL_10_gc = (0x08<<18),
    RCC_CFGR_PLLMUL_11_gc = (0x09<<18),
    RCC_CFGR_PLLMUL_12_gc = (0x0A<<18),
    RCC_CFGR_PLLMUL_13_gc = (0x0B<<18),
    RCC_CFGR_PLLMUL_14_gc = (0x0C<<18),
    RCC_CFGR_PLLMUL_15_gc = (0x0D<<18),
    RCC_CFGR_PLLMUL_16_gc = (0x0E<<18),
    RCC_CFGR_PLLMUL_17_gc = (0x0F<<18),
    RCC_CFGR_PLLXTPRE_NODIV_gc = (0x00<<17),
    RCC_CFGR_PLLXTPRE_DIVBY2_gc = (0x01<<17),
    RCC_CFGR_PLLSRC_HSIDIVBY2_gc = (0x00<<16),
    RCC_CFGR_PLLSRC_HSEDIV_gc = (0x01<<16),
    RCC_CFGR_PPRE2_NODIV_gc = (0x00<<11),
    RCC_CFGR_PPRE2_DIVBY2_gc = (0x04<<11),
    RCC_CFGR_PPRE2_DIVBY4_gc = (0x05<<11),
    RCC_CFGR_PPRE2_DIVBY8_gc = (0x06<<11),
    RCC_CFGR_PPRE2_DIVBY16_gc = (0x07<<11),
    RCC_CFGR_PPRE1_NODIV_gc = (0x00<<8),
    RCC_CFGR_PPRE1_DIVBY2_gc = (0x04<<8),
    RCC_CFGR_PPRE1_DIVBY4_gc = (0x05<<8),
    RCC_CFGR_PPRE1_DIVBY8_gc = (0x06<<8),
    RCC_CFGR_PPRE1_DIVBY16_gc = (0x07<<8),
    RCC_CFGR_HPRE_NODIV_gc = (0x00<<4),
    RCC_CFGR_HPRE_DIVBY2_gc = (0x08<<4),
    RCC_CFGR_HPRE_DIVBY4_gc = (0x09<<4),
    RCC_CFGR_HPRE_DIVBY8_gc = (0x0A<<4),
    RCC_CFGR_HPRE_DIVBY16_gc = (0x0B<<4),
    RCC_CFGR_HPRE_DIVBY64_gc = (0x0C<<4),
    RCC_CFGR_HPRE_DIVBY128_gc = (0x0D<<4),
    RCC_CFGR_HPRE_DIVBY256_gc = (0x0E<<4),
    RCC_CFGR_HPRE_DIVBY512_gc = (0x0F<<4),
    RCC_CFGR_SWS_HSI_gc = (0x00<<2),
    RCC_CFGR_SWS_HSE_gc = (0x01<<2),
    RCC_CFGR_SWS_PLL_gc = (0x02<<2),
    RCC_CFGR_SW_HSI_gc = (0x00<<0),
    RCC_CFGR_SW_HSE_gc = (0x01<<0),
    RCC_CFGR_SW_PLL_gc = (0x02<<0)

} RCC_CFGR_t;

#define RCC_CFGR_PLLNODIV_bm (0x01<<31)
#define RCC_CFGR_MCOPRE_bm (0x07<<29)
#define RCC_CFGR_MCOF_bm (0x01<<28)
#define RCC_CFGR_MCO_bm (0x07<<24)
#define RCC_CFGR_I2SSRC_bm (0x01<<23)
#define RCC_CFGR_USBPRE_bm (0x01<<22)
#define RCC_CFGR_PLLMUL_bm (0x0F<<18)
#define RCC_CFGR_PLLXTPRE_bm (0x01<<17)
#define RCC_CFGR_PLLSRC_bm (0x01<<16)
#define RCC_CFGR_PPRE2_bm (0x07<<11)
#define RCC_CFGR_PPRE1_bm (0x07<<8)
#define RCC_CFGR_HPRE_bm (0x0F<<4)
#define RCC_CFGR_SWS_bm (0x03<<2)
#define RCC_CFGR_SW_bm (0x03<<0)

typedef struct
{

    register32_t ACR;          /*!< FLASH access control register,              Address offset: 0x00 */
    register32_t KEYR;         /*!< FLASH key register,                         Address offset: 0x04 */
    register32_t OPTKEYR;      /*!< FLASH option key register,                  Address offset: 0x08 */
    register32_t SR;           /*!< FLASH status register,                      Address offset: 0x0C */
    register32_t CR;           /*!< FLASH control register,                     Address offset: 0x10 */
    register32_t AR;           /*!< FLASH address register,                     Address offset: 0x14 */
    register32_t reserved_0x18;     /*!< Reserved, 0x18                                                   */
    register32_t OBR;          /*!< FLASH Option byte register,                 Address offset: 0x1C */
    register32_t WRPR;         /*!< FLASH Write register,                       Address offset: 0x20 */
  
} FLASH_t;

typedef enum
{

    FLASH_ACR_PRFTBS_EN_gc = (0x01<<5),
    FLASH_ACR_PRFTBS_DIS_gc = (0x00<<5),
    FLASH_ACR_PRFTBE_EN_gc = (0x01<<4),
    FLASH_ACR_PRFTBE_DIS_gc = (0x00<<4),
    FLASH_ACR_HLFCYA_EN_gc = (0x01<<3),
    FLASH_ACR_HLFCYA_DIS_gc = (0x00<<3),
    FLASH_ACR_LATENCY_0_gc = (0x00),
    FLASH_ACR_LATENCY_1_gc = (0x01),
    FLASH_ACR_LATENCY_2_gc = (0x02)

} FLASH_ACR_t;

// FLASH_ACR bitfields
#define FLASH_ACR_PRFTBS_bm (0x01<<5)
#define FLASH_ACR_PRFTBE_bm (0x01<<4)
#define FLASH_ACR_HLFCYA_bm (0x01<<3)
#define FLASH_ACR_LATENCY_bm (0x02)


typedef struct 
{

    register32_t CPUID;                   /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
    register32_t ICSR;                    /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
    register32_t VTOR;                    /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
    register32_t AIRCR;                   /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
    register32_t SCR;                     /*!< Offset: 0x010 (R/W)  System Control Register                               */
    register32_t CCR;                     /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
    register8_t  SHP[12];                 /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
    register32_t SHCSR;                   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
    register32_t CFSR;                    /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
    register32_t HFSR;                    /*!< Offset: 0x02C (R/W)  HardFault Status Register                             */
    register32_t DFSR;                    /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
    register32_t MMFAR;                   /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register                      */
    register32_t BFAR;                    /*!< Offset: 0x038 (R/W)  BusFault Address Register                             */
    register32_t AFSR;                    /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
    register32_t PFR[2];                  /*!< Offset: 0x040 (R/ )  Processor Feature Register                            */
    register32_t DFR;                     /*!< Offset: 0x048 (R/ )  Debug Feature Register                                */
    register32_t ADR;                     /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register                            */
    register32_t MMFR[4];                 /*!< Offset: 0x050 (R/ )  Memory Model Feature Register                         */
    register32_t ISAR[5];                 /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register                   */
    register32_t RESERVED0[5];
    register32_t CPACR;                   /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register                   */

} SCB_t;

typedef enum
{

    GPIO_MODER_OUT_gc = 0x01,
    GPIO_MODER_IN_gc = 0x00,
    GPIO_MODER_AF_gc = 0x02,
    GPIO_MODER_ANA_gc = 0x03

} GPIO_MODER_t;

typedef enum
{

   GPIO_OTYPER_PP_gc = 0x00,
   GPIO_OTYPER_OD_gc = 0x01

} GPIO_OTYPER_t;

typedef enum
{

    GPIO_OSPEEDR_LOW_gc = 0x00,
    GPIO_OSPEEDR_MED_gc = 0x01,
    GPIO_OSPEEDR_HI_gc = 0x03

} GPIO_OSPEEDR_t;

typedef enum
{

    GPIO_PUPDR_NONE_gc = 0x00,
    GPIO_PUPDR_PULLUP_gc = 0x01,
    GPIO_PUPDR_PULLDOWN_gc = 0x02

} GPIO_PUPDR_t;

typedef enum
{

    GPIO_PIN_0 = 0x00,
    GPIO_PIN_1 = 0x01,
    GPIO_PIN_2 = 0x02,
    GPIO_PIN_3 = 0x03,
    GPIO_PIN_4 = 0x04,
    GPIO_PIN_5 = 0x05,
    GPIO_PIN_6 = 0x06,
    GPIO_PIN_7 = 0x07,
    GPIO_PIN_8 = 0x08,
    GPIO_PIN_9 = 0x09,
    GPIO_PIN_10 = 0x0A,
    GPIO_PIN_11 = 0x0B,
    GPIO_PIN_12 = 0x0C,
    GPIO_PIN_13 = 0x0D,
    GPIO_PIN_14 = 0x0E,
    GPIO_PIN_15 = 0x0F

} GPIO_PIN_t;  

// RCC_CR register bitfields
#define RCC_CR_PLLRDY_bm (0x01<<25)
#define RCC_CR_PLLON_bm (0x01<<24)
#define RCC_CR_CSSON_bm (0x01<<19)
#define RCC_CR_HSEBYP_bm (0x01<<18)
#define RCC_CR_HSERDY_bm (0x01<<17)
#define RCC_CR_HSEON_bm (0x01<<16)
#define RCC_CR_HSIRDY_bm (0x01<<1)
#define RCC_CR_HSION_bm (0x01<<0)
#define RCC_CR_HSICAL_bm (0xFF<<8)
#define RCC_CR_HSITRIM_bm (0x1F<<3)

// Random defines
#define VECT_TAB_OFFSET  0x0

#define FLASH_BASE            ((uint32_t)0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE             ((uint32_t)0x20000000) /*!< SRAM base address in the alias region */
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x00002000) /*!< Flash registers base address */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address  */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address  */


#define PERIPH_BASE           0x40000000 /*!< Peripheral base address in the alias region */
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)

// APB2 peripherals
#define TIM1 (*(AC_TIM_t *) (APB2PERIPH_BASE + 0x00002C00))
#define TIM8 (*(AC_TIM_t *) (APB2PERIPH_BASE + 0x00003400))

// AHB1 peripherals
#define RCC             ((RCC_t *) (AHB1PERIPH_BASE + 0x00001000))

// TODO: da fuq is this
#define HSI_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSI start up */

// AHB1 peripherals
#define FLASH               ((FLASH_t *) FLASH_R_BASE)

// Not peripherals
#define SCB                 ((SCB_t *) SCB_BASE      )   /*!< SCB configuration struct           */

// AHB2 peripherals
#define GPIOA (*(GPIO_t *) (AHB2PERIPH_BASE + 0x0000))
#define GPIOB (*(GPIO_t *) (AHB2PERIPH_BASE + 0x0400))
#define GPIOC (*(GPIO_t *) (AHB2PERIPH_BASE + 0x0800))
#define GPIOD (*(GPIO_t *) (AHB2PERIPH_BASE + 0x0C00))
#define GPIOE (*(GPIO_t *) (AHB2PERIPH_BASE + 0x1000))
#define GPIOF (*(GPIO_t *) (AHB2PERIPH_BASE + 0x1400))

// GPIO bitfields
// MODER
#define GPIO_MODER_MODER0_bm (0x03<<0)
#define GPIO_MODER_MODER1_bm (0x03<<2)
#define GPIO_MODER_MODER2_bm (0x03<<4)
#define GPIO_MODER_MODER3_bm (0x03<<6)
#define GPIO_MODER_MODER4_bm (0x03<<8)
#define GPIO_MODER_MODER5_bm (0x03<<10)
#define GPIO_MODER_MODER6_bm (0x03<<12)
#define GPIO_MODER_MODER7_bm (0x03<<14)
#define GPIO_MODER_MODER8_bm (0x03<<16)
#define GPIO_MODER_MODER9_bm (0x03<<18)
#define GPIO_MODER_MODER10_bm (0x03<<20)
#define GPIO_MODER_MODER11_bm (0x03<<22)
#define GPIO_MODER_MODER12_bm (0x03<<24)
#define GPIO_MODER_MODER13_bm (0x03<<26)
#define GPIO_MODER_MODER14_bm (0x03<<28)
#define GPIO_MODER_MODER15_bm (0x03<<30)

// OTYPER
#define GPIO_OTYPER_OT0_bm (0x01<<0)
#define GPIO_OTYPER_OT1_bm (0x01<<1)
#define GPIO_OTYPER_OT2_bm (0x01<<2)
#define GPIO_OTYPER_OT3_bm (0x01<<3)
#define GPIO_OTYPER_OT4_bm (0x01<<4)
#define GPIO_OTYPER_OT5_bm (0x01<<5)
#define GPIO_OTYPER_OT6_bm (0x01<<6)
#define GPIO_OTYPER_OT7_bm (0x01<<7)
#define GPIO_OTYPER_OT8_bm (0x01<<8)
#define GPIO_OTYPER_OT9_bm (0x01<<9)
#define GPIO_OTYPER_OT10_bm (0x01<<10)
#define GPIO_OTYPER_OT11_bm (0x01<<11)
#define GPIO_OTYPER_OT12_bm (0x01<<12)
#define GPIO_OTYPER_OT13_bm (0x01<<13)
#define GPIO_OTYPER_OT14_bm (0x01<<14)
#define GPIO_OTYPER_OT15_bm (0x01<<15)

// OSPEEDR
#define GPIO_OSPEEDR_OSPEEDR0_bm (0x03<<0)
#define GPIO_OSPEEDR_OSPEEDR1_bm (0x03<<2)
#define GPIO_OSPEEDR_OSPEEDR2_bm (0x03<<4)
#define GPIO_OSPEEDR_OSPEEDR3_bm (0x03<<6)
#define GPIO_OSPEEDR_OSPEEDR4_bm (0x03<<8)
#define GPIO_OSPEEDR_OSPEEDR5_bm (0x03<<10)
#define GPIO_OSPEEDR_OSPEEDR6_bm (0x03<<12)
#define GPIO_OSPEEDR_OSPEEDR7_bm (0x03<<14)
#define GPIO_OSPEEDR_OSPEEDR8_bm (0x03<<16)
#define GPIO_OSPEEDR_OSPEEDR9_bm (0x03<<18)
#define GPIO_OSPEEDR_OSPEEDR10_bm (0x03<<20)
#define GPIO_OSPEEDR_OSPEEDR11_bm (0x03<<22)
#define GPIO_OSPEEDR_OSPEEDR12_bm (0x03<<24)
#define GPIO_OSPEEDR_OSPEEDR13_bm (0x03<<26)
#define GPIO_OSPEEDR_OSPEEDR14_bm (0x03<<28)
#define GPIO_OSPEEDR_OSPEEDR15_bm (0x03<<30)

// PUPDR
#define GPIO_PUPDR_PUPDR0_bm (0x03<<0)
#define GPIO_PUPDR_PUPDR1_bm (0x03<<2)
#define GPIO_PUPDR_PUPDR2_bm (0x03<<4)
#define GPIO_PUPDR_PUPDR3_bm (0x03<<6)
#define GPIO_PUPDR_PUPDR4_bm (0x03<<8)
#define GPIO_PUPDR_PUPDR5_bm (0x03<<10)
#define GPIO_PUPDR_PUPDR6_bm (0x03<<12)
#define GPIO_PUPDR_PUPDR7_bm (0x03<<14)
#define GPIO_PUPDR_PUPDR8_bm (0x03<<16)
#define GPIO_PUPDR_PUPDR9_bm (0x03<<18)
#define GPIO_PUPDR_PUPDR10_bm (0x03<<20)
#define GPIO_PUPDR_PUPDR11_bm (0x03<<22)
#define GPIO_PUPDR_PUPDR12_bm (0x03<<24)
#define GPIO_PUPDR_PUPDR13_bm (0x03<<26)
#define GPIO_PUPDR_PUPDR14_bm (0x03<<28)
#define GPIO_PUPDR_PUPDR15_bm (0x03<<30)

// IDR
#define GPIO_IDR_IDR0_bm (0x01<<0)
#define GPIO_IDR_IDR1_bm (0x01<<1)
#define GPIO_IDR_IDR2_bm (0x01<<2)
#define GPIO_IDR_IDR3_bm (0x01<<3)
#define GPIO_IDR_IDR4_bm (0x01<<4)
#define GPIO_IDR_IDR5_bm (0x01<<5)
#define GPIO_IDR_IDR6_bm (0x01<<6)
#define GPIO_IDR_IDR7_bm (0x01<<7)
#define GPIO_IDR_IDR8_bm (0x01<<8)
#define GPIO_IDR_IDR9_bm (0x01<<9)
#define GPIO_IDR_IDR10_bm (0x01<<10)
#define GPIO_IDR_IDR11_bm (0x01<<11)
#define GPIO_IDR_IDR12_bm (0x01<<12)
#define GPIO_IDR_IDR13_bm (0x01<<13)
#define GPIO_IDR_IDR14_bm (0x01<<14)
#define GPIO_IDR_IDR15_bm (0x01<<15)

// ODR
#define GPIO_ODR_ODR0_bm (0x01<<0)
#define GPIO_ODR_ODR1_bm (0x01<<1)
#define GPIO_ODR_ODR2_bm (0x01<<2)
#define GPIO_ODR_ODR3_bm (0x01<<3)
#define GPIO_ODR_ODR4_bm (0x01<<4)
#define GPIO_ODR_ODR5_bm (0x01<<5)
#define GPIO_ODR_ODR6_bm (0x01<<6)
#define GPIO_ODR_ODR7_bm (0x01<<7)
#define GPIO_ODR_ODR8_bm (0x01<<8)
#define GPIO_ODR_ODR9_bm (0x01<<9)
#define GPIO_ODR_ODR10_bm (0x01<<10)
#define GPIO_ODR_ODR11_bm (0x01<<11)
#define GPIO_ODR_ODR12_bm (0x01<<12)
#define GPIO_ODR_ODR13_bm (0x01<<13)
#define GPIO_ODR_ODR14_bm (0x01<<14)
#define GPIO_ODR_ODR15_bm (0x01<<15)

// BSRR
// BRy
#define GPIO_BSRR_BR0_bm ((0x01<<0)<<16)
#define GPIO_BSRR_BR1_bm ((0x01<<1)<<16)
#define GPIO_BSRR_BR2_bm ((0x01<<2)<<16)
#define GPIO_BSRR_BR3_bm ((0x01<<3)<<16)
#define GPIO_BSRR_BR4_bm ((0x01<<4)<<16)
#define GPIO_BSRR_BR5_bm ((0x01<<5)<<16)
#define GPIO_BSRR_BR6_bm ((0x01<<6)<<16)
#define GPIO_BSRR_BR7_bm ((0x01<<7)<<16)
#define GPIO_BSRR_BR8_bm ((0x01<<8)<<16)
#define GPIO_BSRR_BR9_bm ((0x01<<9)<<16)
#define GPIO_BSRR_BR10_bm ((0x01<<10)<<16)
#define GPIO_BSRR_BR11_bm ((0x01<<11)<<16)
#define GPIO_BSRR_BR12_bm ((0x01<<12)<<16)
#define GPIO_BSRR_BR13_bm ((0x01<<13)<<16)
#define GPIO_BSRR_BR14_bm ((0x01<<14)<<16)
#define GPIO_BSRR_BR15_bm ((0x01<<15)<<16)
// BSy
#define GPIO_BSRR_BS0_bm (0x01<<0)
#define GPIO_BSRR_BS1_bm (0x01<<1)
#define GPIO_BSRR_BS2_bm (0x01<<2)
#define GPIO_BSRR_BS3_bm (0x01<<3)
#define GPIO_BSRR_BS4_bm (0x01<<4)
#define GPIO_BSRR_BS5_bm (0x01<<5)
#define GPIO_BSRR_BS6_bm (0x01<<6)
#define GPIO_BSRR_BS7_bm (0x01<<7)
#define GPIO_BSRR_BS8_bm (0x01<<8)
#define GPIO_BSRR_BS9_bm (0x01<<9)
#define GPIO_BSRR_BS10_bm (0x01<<10)
#define GPIO_BSRR_BS11_bm (0x01<<11)
#define GPIO_BSRR_BS12_bm (0x01<<12)
#define GPIO_BSRR_BS13_bm (0x01<<13)
#define GPIO_BSRR_BS14_bm (0x01<<14)
#define GPIO_BSRR_BS15_bm (0x01<<15)
/* TIM1 registers
#define TIM1_CR1                 _SFR_MEM32(TIM1)
#define TIM1_CR2                 _SFR_MEM32(TIM1 + 0x04)
#define TIM1_SMCR                _SFR_MEM32(TIM1 + 0x08)
#define TIM1_DIER                _SFR_MEM32(TIM1 + 0x0C)
#define TIM1_SR                  _SFR_MEM32(TIM1 + 0x10)
#define TIM1_EGR                 _SFR_MEM32(TIM1 + 0x14)
#define TIM1_CCMR1               _SFR_MEM32(TIM1 + 0x18)
#define TIM1_CCMR2               _SFR_MEM32(TIM1 + 0x1C)
#define TIM1_CCER                _SFR_MEM32(TIM1 + 0x20)
#define TIM1_CNT                 _SFR_MEM32(TIM1 + 0x24)
#define TIM1_PSC                 _SFR_MEM32(TIM1 + 0x28)
#define TIM1_ARR                 _SFR_MEM32(TIM1 + 0x2C)
#define TIM1_RCR                 _SFR_MEM32(TIM1 + 0x30)
#define TIM1_CCR1                _SFR_MEM32(TIM1 + 0x34)
#define TIM1_CCR2                _SFR_MEM32(TIM1 + 0x38)
#define TIM1_CCR3                _SFR_MEM32(TIM1 + 0x3C)
#define TIM1_CCR4                _SFR_MEM32(TIM1 + 0x40)
#define TIM1_BDTR                _SFR_MEM32(TIM1 + 0x44)
#define TIM1_DCR                 _SFR_MEM32(TIM1 + 0x48)
#define TIM1_DMAR                _SFR_MEM32(TIM1 + 0x4C)
#define TIM1_CCMR3               _SFR_MEM32(TIM1 + 0x54)
#define TIM1_CCR5                _SFR_MEM32(TIM1 + 0x58)
#define TIM1_CCR6                _SFR_MEM32(TIM1 + 0x5C)
#define TIM1_OR                  _SFR_MEM32(TIM1 + 0x60)
*/
