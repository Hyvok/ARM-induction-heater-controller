#ifndef STM32F30X_NEW_H
#define STM32F30X_NEW_H

#include <stdint.h>

/* New header for the STM32F30x series of ARM Cortex-M4 microcontrollers. */ 

// Memory type defines
#define _MMIO_DWORD(mem_addr) (*(volatile uint32_t *)(mem_addr))
#define _SFR_MEM32(mem_addr) _MMIO_DWORD(mem_addr)

typedef volatile uint32_t register32_t;
typedef volatile uint16_t register16_t;
typedef volatile uint8_t register8_t;

typedef enum
{
    /******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
    NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
    MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
    BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
    UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
    SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
    DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
    PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
    SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
    /******  STM32 specific Interrupt Numbers **********************************************************************/
    WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
    PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
    TAMPER_STAMP_IRQn           = 2,      /*!< Tamper and TimeStamp interrupts                                   */
    RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI lines 17, 19 & 20           */
    FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
    RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
    EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
    EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
    EXTI2_TS_IRQn               = 8,      /*!< EXTI Line2 Interrupt and Touch Sense Interrupt                    */
    EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
    EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
    DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 Interrupt                                          */
    DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 Interrupt                                          */
    DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 Interrupt                                          */
    DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 Interrupt                                          */
    DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 Interrupt                                          */
    DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 Interrupt                                          */
    DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 Interrupt                                          */
    ADC1_2_IRQn                 = 18,     /*!< ADC1 & ADC2 Interrupts                                            */
    USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts                    */
    USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts                    */  
    CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
    CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
    TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 Break and TIM15 Interrupts                                   */
    TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 Update and TIM16 Interrupts                                  */
    TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt                  */
    TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
    TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
    TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
    TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
    I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
    I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */ 
    I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */  
    I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
    SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
    SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
    USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
    USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
    USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */  
    EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
    RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    USBWakeUp_IRQn              = 42,     /*!< USB Wakeup Interrupt                                              */
    TIM8_BRK_IRQn               = 43,     /*!< TIM8 Break Interrupt                                              */
    TIM8_UP_IRQn                = 44,     /*!< TIM8 Update Interrupt                                             */
    TIM8_TRG_COM_IRQn           = 45,     /*!< TIM8 Trigger and Commutation Interrupt                            */
    TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                    */
    ADC3_IRQn                   = 47,     /*!< ADC3 global Interrupt                                             */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
    UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
    UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
    TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
    TIM7_IRQn                   = 55,     /*!< TIM7 global Interrupt                                             */
    DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                                   */
    DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                                   */
    DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                                   */
    DMA2_Channel4_IRQn          = 59,     /*!< DMA2 Channel 4 global Interrupt                                   */
    DMA2_Channel5_IRQn          = 60,     /*!< DMA2 Channel 5 global Interrupt                                   */
    ADC4_IRQn                   = 61,     /*!< ADC4  global Interrupt                                            */
    COMP1_2_3_IRQn              = 64,     /*!< COMP1, COMP2 and COMP3 global Interrupt                           */
    COMP4_5_6_IRQn              = 65,     /*!< COMP5, COMP6 and COMP4 global Interrupt                           */
    COMP7_IRQn                  = 66,     /*!< COMP7 global Interrupt                                            */
    USB_HP_IRQn                 = 74,     /*!< USB High Priority global Interrupt remap                          */
    USB_LP_IRQn                 = 75,     /*!< USB Low Priority global Interrupt  remap                          */
    USBWakeUp_RMP_IRQn          = 76,     /*!< USB Wakeup Interrupt remap                                        */
    FPU_IRQn                    = 81      /*!< Floating point Interrupt                                          */
} IRQn_t;

typedef enum
{
    EXTI_21n                     = 21,
} EXTIn_t;

// Registers for advanced control timers TIM1 and TIM8
typedef struct 
{
    register32_t CR1;                           // Control register 1, 0x00
    register32_t CR2;                           // Control register 2, 0x04
    register32_t SMCR;                          // Slave mode control register, 0x08
    register32_t DIER;                          // DMA/enable interrupt register, 0x0C
    register32_t SR;                            // Status register, 0x10
    register32_t EGR;                           // Event generation register, 0x14
    register32_t CCMR1;                         // Capture/compare mode register 1, 0x18
    register32_t CCMR2;                         // Capture/compare mode register 2, 0x1C
    register32_t CCER;                          // Capture/compare enable register, 0x20
    register32_t CNT;                           // Counter, 0x24
    // TODO: PSC is 16bit register?
    register32_t PSC;                           // Prescaler, 0x28
    register32_t ARR;                           // Auto-reload register, 0x2C
    register32_t RCR;                           // Repetition counter register, 0x30
    register32_t CCR1;                          // Capture/compare register 1, 0x34
    register32_t CCR2;                          // Capture/compare register 2, 0x38
    register32_t CCR3;                          // Capture/compare register 3, 0x3C
    register32_t CCR4;                          // Capture/compare register 4, 0x40
    register32_t BDTR;                          // Break and dead-time register, 0x44
    register32_t DCR;                           // DMA control register, 0x48
    register32_t DMAR;                          // DMA address for full transfer, 0x4C
    register32_t reserved_0x50;
    register32_t CCMR3;                         // Capture/compare mode register 3, 0x54
    register32_t CCR5;                          // Capture/compare register 5, 0x58
    register32_t CCR6;                          // Capture/compare register 6, 0x5C
    register32_t OR;                            // Option registers, 0x60
} AC_TIM_t;

typedef enum 
{
    AC_TIM_CR1_UIFREMAP_EN_gc       = (0x01<<11),
    AC_TIM_CR1_UIFREMAP_DIS_gc      = (0x00<<11),
    AC_TIM_CR1_CKD_NODIV_gc         = (0x00<<8),
    AC_TIM_CR1_CKD_DIVBY2_gc        = (0x01<<8),
    AC_TIM_CR1_CKD_DIVBY4_gc        = (0x02<<8),
    AC_TIM_CR1_CKD_DIVBY8_gc        = (0x01<<8),
    AC_TIM_CR1_ARPE_BUF_gc          = (0x01<<7),
    AC_TIM_CR1_ARPE_UNBUF_gc        = (0x01<<7),
    AC_TIM_CR1_CMS_EDGE_gc          = (0x00<<5),
    AC_TIM_CR1_CMS_CENTER1_gc       = (0x01<<5),
    AC_TIM_CR1_CMS_CENTER2_gc       = (0x02<<5),
    AC_TIM_CR1_CMS_CENTER3_gc       = (0x03<<5),
    AC_TIM_CR1_DIR_UP_gc            = (0x00<<4),
    AC_TIM_CR1_DIR_DOWN_gc          = (0x01<<4),
    AC_TIM_CR1_OPM_EN_gc            = (0x00<<3),
    AC_TIM_CR1_OPM_DIS_gc           = (0x01<<3),
    AC_TIM_CR1_URS_ANY_gc           = (0x00<<2),
    AC_TIM_CR1_URS_ONLYOFUF_gc      = (0x00<<2),
    AC_TIM_CR1_UDIS_EN_gc           = (0x00<<1),
    AC_TIM_CR1_UDIS_DIS_gc          = (0x01<<1),
    AC_TIM_CR1_CEN_EN_gc            = (0x01<<0),
    AC_TIM_CR1_CEN_DIS_gc           = (0x00<<0)
} AC_TIM_CR1_t;

#define AC_TIM_CR1_UIFREMAP_bm      (0x01<<11)
#define AC_TIM_CR1_CKD_bm           (0x03<<8)
#define AC_TIM_CR1_ARPE_bm          (0x01<<7)
#define AC_TIM_CR1_CMS_bm           (0x03<<5)
#define AC_TIM_CR1_DIR_bm           (0x01<<4)
#define AC_TIM_CR1_OPM_bm           (0x01<<3)
#define AC_TIM_CR1_URS_bm           (0x01<<2)
#define AC_TIM_CR1_UDIS_bm          (0x01<<1)
#define AC_TIM_CR1_CEN_bm           (0x01<<0)

typedef enum 
{
    AC_TIM_CR2_MMS2_RES_gc                  = (0x00<<20),
    AC_TIM_CR2_MMS2_EN_gc                   = (0x01<<20),
    AC_TIM_CR2_MMS2_UPDATE_gc               = (0x02<<20),
    AC_TIM_CR2_MMS2_CMPPULS_gc              = (0x03<<20),
    AC_TIM_CR2_MMS2_COMP_OC1REF_gc          = (0x04<<20),
    AC_TIM_CR2_MMS2_COMP_OC2REF_gc          = (0x05<<20),
    AC_TIM_CR2_MMS2_COMP_OC3REF_gc          = (0x06<<20),
    AC_TIM_CR2_MMS2_COMP_OC4REF_gc          = (0x07<<20),
    AC_TIM_CR2_MMS2_COMP_OC5REF_gc          = (0x08<<20),
    AC_TIM_CR2_MMS2_COMP_OC6REF_gc          = (0x09<<20),
    AC_TIM_CR2_MMS2_CMPPULS_OC4REF_gc       = (0x0A<<20),
    AC_TIM_CR2_MMS2_CMPPULS_OC6REF_gc       = (0x0B<<20),
    AC_TIM_CR2_MMS2_CMPPULS_OC46REF_RIS_gc  = (0x0C<<20),
    AC_TIM_CR2_MMS2_CMPPULS_OC46REF_FALL_gc = (0x0D<<20),
    AC_TIM_CR2_MMS2_CMPPULS_OC56REF_RIS_gc  = (0x0E<<20),
    AC_TIM_CR2_MMS2_CMPPULS_OC56REF_FALL_gc = (0x0F<<20),
    AC_TIM_CR2_OIS6_0_gc                    = (0x00<<18),
    AC_TIM_CR2_OIS6_1_gc                    = (0x01<<18),
    AC_TIM_CR2_OIS5_0_gc                    = (0x00<<16),
    AC_TIM_CR2_OIS5_1_gc                    = (0x01<<16),
    AC_TIM_CR2_OIS4_0_gc                    = (0x00<<14),
    AC_TIM_CR2_OIS4_1_gc                    = (0x01<<14),
    AC_TIM_CR2_OIS3N_0_gc                   = (0x00<<13),
    AC_TIM_CR2_OIS3N_1_gc                   = (0x01<<13),
    AC_TIM_CR2_OIS3_0_gc                    = (0x00<<12),
    AC_TIM_CR2_OIS3_1_gc                    = (0x01<<12),
    AC_TIM_CR2_OIS2N_0_gc                   = (0x00<<11),
    AC_TIM_CR2_OIS2N_1_gc                   = (0x01<<11),
    AC_TIM_CR2_OIS2_0_gc                    = (0x00<<10),
    AC_TIM_CR2_OIS2_1_gc                    = (0x01<<10),
    AC_TIM_CR2_OIS1N_0_gc                   = (0x00<<9),
    AC_TIM_CR2_OIS1N_1_gc                   = (0x01<<9),
    AC_TIM_CR2_OIS1_0_gc                    = (0x00<<8),
    AC_TIM_CR2_OIS1_1_gc                    = (0x01<<8),
    AC_TIM_CR2_TI1S_CH1_gc                  = (0x00<<7),
    AC_TIM_CR2_TI1S_XOR_gc                  = (0x01<<7),
    AC_TIM_CR2_MMS_RES_gc                   = (0x00<<4),
    AC_TIM_CR2_MMS_EN_gc                    = (0x01<<4),
    AC_TIM_CR2_MMS_UPDATE_gc                = (0x02<<4),
    AC_TIM_CR2_MMS_CMPPULS_gc               = (0x03<<4),
    AC_TIM_CR2_MMS_COMP_OC1REF_gc           = (0x04<<4),
    AC_TIM_CR2_MMS_COMP_OC2REF_gc           = (0x05<<4),
    AC_TIM_CR2_MMS_COMP_OC3REF_gc           = (0x06<<4),
    AC_TIM_CR2_MMS_COMP_OC4REF_gc           = (0x07<<4),
    AC_TIM_CR2_CCDS_CCX_gc                  = (0x00<<3),
    AC_TIM_CR2_CCDS_UPDATE_gc               = (0x01<<3),
    AC_TIM_CR2_CCUS_COMG_gc                 = (0x00<<2),
    AC_TIM_CR2_CCUS_COMG_OR_TRGI_gc         = (0x01<<2),
    AC_TIM_CR2_CCPC_NOPRELOAD_gc            = (0x00<<0),
    AC_TIM_CR2_CCPC_PRELOAD_gc              = (0x01<<0)
} AC_TIM_CR2_t;

#define AC_TIM_CR2_MMS2_bm          (0x15<<20)
#define AC_TIM_CR2_OIS6_bm          (0x01<<18)
#define AC_TIM_CR2_OIS5_bm          (0x01<<16)
#define AC_TIM_CR2_OIS4_bm          (0x01<<14)
#define AC_TIM_CR2_OIS3N_bm         (0x01<<13)
#define AC_TIM_CR2_OIS3_bm          (0x01<<12)
#define AC_TIM_CR2_OIS2N_bm         (0x01<<11)
#define AC_TIM_CR2_OIS2_bm          (0x01<<10)
#define AC_TIM_CR2_OIS1N_bm         (0x01<<9)
#define AC_TIM_CR2_OIS1_bm          (0x01<<8)
#define AC_TIM_CR2_TI1S_bm          (0x01<<7)
#define AC_TIM_CR2_MMS_bm           (0x07<<4)
#define AC_TIM_CR2_CCDS_bm          (0x01<<3)
#define AC_TIM_CR2_CCUS_bm          (0x01<<2)
#define AC_TIM_CR2_CCPC_bm          (0x01<<0)

#define AC_TIM_SMCR_SMS_bm          (0x10007)
#define AC_TIM_SMCR_ETP_bm          (0x01<<15)
#define AC_TIM_SMCR_ECE_bm          (0x01<<14)
#define AC_TIM_SMCR_ETPS_bm         (0x03<<12)
#define AC_TIM_SMCR_ETF_bm          (0x0F<<8)
#define AC_TIM_SMCR_MSM_bm          (0x01<<7)
#define AC_TIM_SMCR_TS_bm           (0x07<<4)
#define AC_TIM_SMCR_OCCS_bm         (0x01<<3)

typedef enum
{
    AC_TIM_DIER_TDE_EN_gc           = (0x01<<14),
    AC_TIM_DIER_TDE_DIS_gc          = (0x00<<14),
    AC_TIM_DIER_COMDE_EN_gc         = (0x01<<13),
    AC_TIM_DIER_COMDE_DIS_gc        = (0x00<<13),
    AC_TIM_DIER_CC4DE_EN_gc         = (0x01<<12),
    AC_TIM_DIER_CC4DE_DIS_gc        = (0x00<<12),
    AC_TIM_DIER_CC3DE_DIS_gc        = (0x00<<11),
    AC_TIM_DIER_CC3DE_EN_gc         = (0x01<<11),
    AC_TIM_DIER_CC2DE_EN_gc         = (0x01<<10),
    AC_TIM_DIER_CC2DE_DIS_gc        = (0x00<<10),
    AC_TIM_DIER_CC1DE_DIS_gc        = (0x00<<9),
    AC_TIM_DIER_CC1DE_EN_gc         = (0x01<<9),
    AC_TIM_DIER_UDE_EN_gc           = (0x01<<8),
    AC_TIM_DIER_UDE_DIS_gc          = (0x00<<8),
    AC_TIM_DIER_BIE_EN_gc           = (0x01<<7),
    AC_TIM_DIER_BIE_DIS_gc          = (0x00<<7),
    AC_TIM_DIER_TIE_EN_gc           = (0x01<<6),
    AC_TIM_DIER_TIE_DIS_gc          = (0x00<<6),
    AC_TIM_DIER_COMIE_EN_gc         = (0x01<<5),
    AC_TIM_DIER_COMIE_DIS_gc        = (0x00<<5),
    AC_TIM_DIER_CC4IE_EN_gc         = (0x01<<4),
    AC_TIM_DIER_CC4IE_DIS_gc        = (0x00<<4),
    AC_TIM_DIER_CC3IE_DIS_gc        = (0x00<<3),
    AC_TIM_DIER_CC3IE_EN_gc         = (0x01<<3),
    AC_TIM_DIER_CC2IE_EN_gc         = (0x01<<2),
    AC_TIM_DIER_CC2IE_DIS_gc        = (0x00<<2),
    AC_TIM_DIER_CC1IE_DIS_gc        = (0x00<<1),
    AC_TIM_DIER_CC1IE_EN_gc         = (0x01<<1),
    AC_TIM_DIER_UIE_EN_gc           = (0x01<<0),
    AC_TIM_DIER_UIE_DIS_gc          = (0x00<<0),
} AC_TIM_DIER_t;

#define AC_TIM_DIER_TDE_bm          (0x01<<14)
#define AC_TIM_DIER_COMDE_bm        (0x01<<13)
#define AC_TIM_DIER_CC4DE_bm        (0x01<<12)
#define AC_TIM_DIER_CC3DE_bm        (0x01<<11)
#define AC_TIM_DIER_CC2DE_bm        (0x01<<10)
#define AC_TIM_DIER_CC1DE_bm        (0x01<<9)
#define AC_TIM_DIER_UDE_bm          (0x01<<8)
#define AC_TIM_DIER_BIE_bm          (0x01<<7)
#define AC_TIM_DIER_TIE_bm          (0x01<<6)
#define AC_TIM_DIER_COMIE_bm        (0x01<<5)
#define AC_TIM_DIER_CC4IE_bm        (0x01<<4)
#define AC_TIM_DIER_CC3IE_bm        (0x01<<3)
#define AC_TIM_DIER_CC2IE_bm        (0x01<<2)
#define AC_TIM_DIER_CC1IE_bm        (0x01<<1)
#define AC_TIM_DIER_UIE_bm          (0x01<<0)

typedef enum
{
    AC_TIM_SR_CC6IF_EN_gc           = (0x01<<17),
    AC_TIM_SR_CC6IF_DIS_gc          = (0x00<<17),
    AC_TIM_SR_CC5IF_EN_gc           = (0x01<<16),
    AC_TIM_SR_CC5IF_DIS_gc          = (0x00<<16),
    AC_TIM_SR_CC4OF_EN_gc           = (0x01<<12),
    AC_TIM_SR_CC4OF_DIS_gc          = (0x00<<12),
    AC_TIM_SR_CC3OF_EN_gc           = (0x01<<11),
    AC_TIM_SR_CC3OF_DIS_gc          = (0x00<<11),
    AC_TIM_SR_CC2OF_EN_gc           = (0x01<<10),
    AC_TIM_SR_CC2OF_DIS_gc          = (0x00<<10),
    AC_TIM_SR_CC1OF_EN_gc           = (0x01<<9),
    AC_TIM_SR_CC1OF_DIS_gc          = (0x00<<9),
    AC_TIM_SR_B2IF_EN_gc            = (0x01<<8),
    AC_TIM_SR_B2IF_DIS_gc           = (0x00<<8),
    AC_TIM_SR_BIF_EN_gc             = (0x01<<7),
    AC_TIM_SR_BIF_DIS_gc            = (0x00<<7),
    AC_TIM_SR_TIF_EN_gc             = (0x01<<6),
    AC_TIM_SR_TIF_DIS_gc            = (0x00<<6),
    AC_TIM_SR_COMIF_EN_gc           = (0x01<<5),
    AC_TIM_SR_COMIF_DIS_gc          = (0x00<<5),
    AC_TIM_SR_CC4IF_EN_gc           = (0x01<<4),
    AC_TIM_SR_CC4IF_DIS_gc          = (0x00<<4),
    AC_TIM_SR_CC3IF_EN_gc           = (0x01<<3),
    AC_TIM_SR_CC3IF_DIS_gc          = (0x00<<3),
    AC_TIM_SR_CC2IF_EN_gc           = (0x01<<2),
    AC_TIM_SR_CC2IF_DIS_gc          = (0x00<<2),
    AC_TIM_SR_CC1IF_EN_gc           = (0x01<<1),
    AC_TIM_SR_CC1IF_DIS_gc          = (0x00<<1),
    AC_TIM_SR_UIF_EN_gc             = (0x01<<0),
    AC_TIM_SR_UIF_DIS_gc            = (0x00<<0),
} AC_TIM_SR_t;

#define AC_TIM_SR_CC6IF_bm          (0x01<<17)
#define AC_TIM_SR_CC5IF_bm          (0x01<<16)
#define AC_TIM_SR_CC4OF_bm          (0x01<<12)
#define AC_TIM_SR_CC3OF_bm          (0x01<<11)
#define AC_TIM_SR_CC2OF_bm          (0x01<<10)
#define AC_TIM_SR_CC1OF_bm          (0x01<<9)
#define AC_TIM_SR_B2IF_bm           (0x01<<8)
#define AC_TIM_SR_BIF_bm            (0x01<<7)
#define AC_TIM_SR_TIF_bm            (0x01<<6)
#define AC_TIM_SR_COMIF_bm          (0x01<<5)
#define AC_TIM_SR_CC4IF_bm          (0x01<<4)
#define AC_TIM_SR_CC3IF_bm          (0x01<<3)
#define AC_TIM_SR_CC2IF_bm          (0x01<<2)
#define AC_TIM_SR_CC1IF_bm          (0x01<<1)
#define AC_TIM_SR_UIF_bm            (0x01<<0)

typedef enum
{
    AC_TIM_EGR_UG_NOACT_gc          = (0x00<<0),
    AC_TIM_EGR_UG_REINIT_gc         = (0x01<<0)
} AC_TIM_EGR_t;

#define AC_TIM_EGR_UG_bm            (0x01<<0)

typedef enum 
{
    AC_TIM_CCMR1_OC2M_FROZEN_gc         = (0x00<<12),
    AC_TIM_CCMR1_OC2M_CH1_ACT_gc        = (0x01<<12),
    AC_TIM_CCMR1_OC2M_CH1_INACT_gc      = (0x02<<12),
    AC_TIM_CCMR1_OC2M_TOGGLE_gc         = (0x03<<12),
    AC_TIM_CCMR1_OC2M_FINACTIVE_gc      = (0x04<<12),
    AC_TIM_CCMR1_OC2M_FACTIVE_gc        = (0x05<<12),
    AC_TIM_CCMR1_OC2M_PWMM1_gc          = (0x06<<12),
    AC_TIM_CCMR1_OC2M_PWMM2_gc          = (0x07<<12),
    AC_TIM_CCMR1_OC2M_OPMM1_gc          = ((0x01<<24)|((0x00<<12))),
    AC_TIM_CCMR1_OC2M_OPMM2_gc          = ((0x01<<24)|((0x01<<12))),
    AC_TIM_CCMR1_OC2M_CPWMM1_gc         = ((0x01<<24)|((0x04<<12))),
    AC_TIM_CCMR1_OC2M_CPWMM2_gc         = ((0x01<<24)|((0x05<<12))),
    AC_TIM_CCMR1_OC2M_APWMM1_gc         = ((0x01<<24)|((0x06<<12))),
    AC_TIM_CCMR1_OC1M_FROZEN_gc         = (0x00<<4),
    AC_TIM_CCMR1_OC1M_CH1_ACT_gc        = (0x01<<4),
    AC_TIM_CCMR1_OC1M_CH1_INACT_gc      = (0x02<<4),
    AC_TIM_CCMR1_OC1M_TOGGLE_gc         = (0x03<<4),
    AC_TIM_CCMR1_OC1M_FINACTIVE_gc      = (0x04<<4),
    AC_TIM_CCMR1_OC1M_FACTIVE_gc        = (0x05<<4),
    AC_TIM_CCMR1_OC1M_PWMM1_gc          = (0x06<<4),
    AC_TIM_CCMR1_OC1M_PWMM2_gc          = (0x07<<4),
    AC_TIM_CCMR1_OC1M_OPMM1_gc          = ((0x01<<16)|((0x00<<4))),
    AC_TIM_CCMR1_OC1M_OPMM2_gc          = ((0x01<<16)|((0x01<<4))),
    AC_TIM_CCMR1_OC1M_CPWMM1_gc         = ((0x01<<16)|((0x04<<4))),
    AC_TIM_CCMR1_OC1M_CPWMM2_gc         = ((0x01<<16)|((0x05<<4))),
    AC_TIM_CCMR1_OC1M_APWMM1_gc         = ((0x01<<16)|((0x06<<4))),
    AC_TIM_CCMR1_OC1M_APWMM2_gc         = ((0x01<<16)|((0x07<<4))),
    AC_TIM_CCMR1_OC1M_APWMM3_gc         = ((0x01<<16)|((0x07<<4))),
    AC_TIM_CCMR1_IC2F_NONE_gc           = (0x00<<12),
    AC_TIM_CCMR1_IC2F_DIV1N2_gc         = (0x01<<12),
    AC_TIM_CCMR1_IC2F_DIV1N4_gc         = (0x02<<12),
    AC_TIM_CCMR1_IC2F_DIV1N8_gc         = (0x03<<12),
    AC_TIM_CCMR1_IC2F_DIV2N6_gc         = (0x04<<12),
    AC_TIM_CCMR1_IC2F_DIV2N8_gc         = (0x05<<12),
    AC_TIM_CCMR1_IC2F_DIV4N6_gc         = (0x06<<12),
    AC_TIM_CCMR1_IC2F_DIV4N8_gc         = (0x07<<12),
    AC_TIM_CCMR1_IC2F_DIV8N6_gc         = (0x08<<12),
    AC_TIM_CCMR1_IC2F_DIV8N8_gc         = (0x09<<12),
    AC_TIM_CCMR1_IC2F_DIV16N5_gc        = (0x0A<<12),
    AC_TIM_CCMR1_IC2F_DIV16N6_gc        = (0x0B<<12),
    AC_TIM_CCMR1_IC2F_DIV16N8_gc        = (0x0C<<12),
    AC_TIM_CCMR1_IC2F_DIV32N5_gc        = (0x0D<<12),
    AC_TIM_CCMR1_IC2F_DIV32N6_gc        = (0x0E<<12),
    AC_TIM_CCMR1_IC2F_DIV32N8_gc        = (0x0F<<12),
    AC_TIM_CCMR1_IC1F_NONE_gc           = (0x00<<4),
    AC_TIM_CCMR1_IC1F_DIV1N2_gc         = (0x01<<4),
    AC_TIM_CCMR1_IC1F_DIV1N4_gc         = (0x02<<4),
    AC_TIM_CCMR1_IC1F_DIV1N8_gc         = (0x03<<4),
    AC_TIM_CCMR1_IC1F_DIV2N6_gc         = (0x04<<4),
    AC_TIM_CCMR1_IC1F_DIV2N8_gc         = (0x05<<4),
    AC_TIM_CCMR1_IC1F_DIV4N6_gc         = (0x06<<4),
    AC_TIM_CCMR1_IC1F_DIV4N8_gc         = (0x07<<4),
    AC_TIM_CCMR1_IC1F_DIV8N6_gc         = (0x08<<4),
    AC_TIM_CCMR1_IC1F_DIV8N8_gc         = (0x09<<4),
    AC_TIM_CCMR1_IC1F_DIV16N5_gc        = (0x0A<<4),
    AC_TIM_CCMR1_IC1F_DIV16N6_gc        = (0x0B<<4),
    AC_TIM_CCMR1_IC1F_DIV16N8_gc        = (0x0C<<4),
    AC_TIM_CCMR1_IC1F_DIV32N5_gc        = (0x0D<<4),
    AC_TIM_CCMR1_IC1F_DIV32N6_gc        = (0x0E<<4),
    AC_TIM_CCMR1_IC1F_DIV32N8_gc        = (0x0F<<4),
    AC_TIM_CCMR1_IC2PSC_NONE_gc         = (0x00<<10),
    AC_TIM_CCMR1_IC2PSC_N2_gc           = (0x01<<10),
    AC_TIM_CCMR1_IC2PSC_N4_gc           = (0x02<<10),
    AC_TIM_CCMR1_IC2PSC_N8_gc           = (0x03<<10),
    AC_TIM_CCMR1_IC1PSC_NONE_gc         = (0x00<<2),
    AC_TIM_CCMR1_IC1PSC_N2_gc           = (0x01<<2),
    AC_TIM_CCMR1_IC1PSC_N4_gc           = (0x02<<2),
    AC_TIM_CCMR1_IC1PSC_N8_gc           = (0x03<<2),
    AC_TIM_CCMR1_CC2S_OUT_gc            = (0x00<<8),
    AC_TIM_CCMR1_CC2S_INTI2_gc          = (0x01<<8),
    AC_TIM_CCMR1_CC2S_INTI1_gc          = (0x02<<8),
    AC_TIM_CCMR1_CC2S_INTRC_gc          = (0x03<<8),
    AC_TIM_CCMR1_CC1S_OUT_gc            = (0x00<<0),
    AC_TIM_CCMR1_CC1S_INTI2_gc          = (0x01<<0),
    AC_TIM_CCMR1_CC1S_INTI1_gc          = (0x02<<0),
    AC_TIM_CCMR1_CC1S_INTRC_gc          = (0x03<<0),
    AC_TIM_CCMR1_OC2CE_DIS_gc           = (0x00<<15),
    AC_TIM_CCMR1_OC2CE_EN_gc            = (0x01<<15),
    AC_TIM_CCMR1_OC2PE_DIS_gc           = (0x00<<11),
    AC_TIM_CCMR1_OC2PE_EN_gc            = (0x01<<11),
    AC_TIM_CCMR1_OC2FE_NORM_gc          = (0x00<<10),
    AC_TIM_CCMR1_OC2FE_FAST_gc          = (0x01<<10),
    AC_TIM_CCMR1_OC1CE_DIS_gc           = (0x00<<7),
    AC_TIM_CCMR1_OC1CE_EN_gc            = (0x01<<7),
    AC_TIM_CCMR1_OC1PE_DIS_gc           = (0x00<<3),
    AC_TIM_CCMR1_OC1PE_EN_gc            = (0x01<<3),
    AC_TIM_CCMR1_OC1FE_NORM_gc          = (0x00<<2),
    AC_TIM_CCMR1_OC1FE_FAST_gc          = (0x01<<2),
} AC_TIM_CCMR1_t;

#define AC_TIM_CCMR1_OC2M_bm        (0x807000)
#define AC_TIM_CCMR1_OC1M_bm        (0x10070)
#define AC_TIM_CCMR1_IC2F_bm        (0x0F<<12)
#define AC_TIM_CCMR1_IC2PSC_bm      (0x03<<10)
#define AC_TIM_CCMR1_OC2CE_bm       (0x01<<15)
#define AC_TIM_CCMR1_OC2PE_bm       (0x01<<11)
#define AC_TIM_CCMR1_OC2FE_bm       (0x01<<10)
#define AC_TIM_CCMR1_CC2S_bm        (0x03<<8)
#define AC_TIM_CCMR1_IC1F_bm        (0x0F<<4)
#define AC_TIM_CCMR1_IC1PSC_bm      (0x03<<2)
#define AC_TIM_CCMR1_OC1CE_bm       (0x01<<7)
#define AC_TIM_CCMR1_OC1PE_bm       (0x01<<3)
#define AC_TIM_CCMR1_OC1FE_bm       (0x01<<2)
#define AC_TIM_CCMR1_CC1S_bm        (0x03<<0)

typedef enum 
{
    AC_TIM_CCMR2_OC4M_FROZEN_gc         = (0x00<<12),
    AC_TIM_CCMR2_OC4M_CH1_ACT_gc        = (0x01<<12),
    AC_TIM_CCMR2_OC4M_CH1_INACT_gc      = (0x02<<12),
    AC_TIM_CCMR2_OC4M_TOGGLE_gc         = (0x03<<12),
    AC_TIM_CCMR2_OC4M_FINACTIVE_gc      = (0x04<<12),
    AC_TIM_CCMR2_OC4M_FACTIVE_gc        = (0x05<<12),
    AC_TIM_CCMR2_OC4M_PWMM1_gc          = (0x06<<12),
    AC_TIM_CCMR2_OC4M_PWMM2_gc          = (0x07<<12),
    AC_TIM_CCMR2_OC4M_OPMM1_gc          = ((0x01<<24)|((0x00<<12))),
    AC_TIM_CCMR2_OC4M_OPMM2_gc          = ((0x01<<24)|((0x01<<12))),
    AC_TIM_CCMR2_OC4M_CPWMM1_gc         = ((0x01<<24)|((0x04<<12))),
    AC_TIM_CCMR2_OC4M_CPWMM2_gc         = ((0x01<<24)|((0x05<<12))),
    AC_TIM_CCMR2_OC4M_APWMM1_gc         = ((0x01<<24)|((0x06<<12))),
    AC_TIM_CCMR2_OC3M_FROZEN_gc         = (0x00<<4),
    AC_TIM_CCMR2_OC3M_CH1_ACT_gc        = (0x01<<4),
    AC_TIM_CCMR2_OC3M_CH1_INACT_gc      = (0x02<<4),
    AC_TIM_CCMR2_OC3M_TOGGLE_gc         = (0x03<<4),
    AC_TIM_CCMR2_OC3M_FINACTIVE_gc      = (0x04<<4),
    AC_TIM_CCMR2_OC3M_FACTIVE_gc        = (0x05<<4),
    AC_TIM_CCMR2_OC3M_PWMM1_gc          = (0x06<<4),
    AC_TIM_CCMR2_OC3M_PWMM2_gc          = (0x07<<4),
    AC_TIM_CCMR2_OC3M_OPMM1_gc          = ((0x01<<16)|((0x00<<4))),
    AC_TIM_CCMR2_OC3M_OPMM2_gc          = ((0x01<<16)|((0x01<<4))),
    AC_TIM_CCMR2_OC3M_CPWMM1_gc         = ((0x01<<16)|((0x04<<4))),
    AC_TIM_CCMR2_OC3M_CPWMM2_gc         = ((0x01<<16)|((0x05<<4))),
    AC_TIM_CCMR2_OC3M_APWMM1_gc         = ((0x01<<16)|((0x06<<4))),
    AC_TIM_CCMR2_OC3M_APWMM2_gc         = ((0x01<<16)|((0x07<<4))),
    AC_TIM_CCMR2_OC3M_APWMM3_gc         = ((0x01<<16)|((0x07<<4))),
    AC_TIM_CCMR2_IC4F_NONE_gc           = (0x00<<12),
    AC_TIM_CCMR2_IC4F_DIV1N2_gc         = (0x01<<12),
    AC_TIM_CCMR2_IC4F_DIV1N4_gc         = (0x02<<12),
    AC_TIM_CCMR2_IC4F_DIV1N8_gc         = (0x03<<12),
    AC_TIM_CCMR2_IC4F_DIV2N6_gc         = (0x04<<12),
    AC_TIM_CCMR2_IC4F_DIV2N8_gc         = (0x05<<12),
    AC_TIM_CCMR2_IC4F_DIV4N6_gc         = (0x06<<12),
    AC_TIM_CCMR2_IC4F_DIV4N8_gc         = (0x07<<12),
    AC_TIM_CCMR2_IC4F_DIV8N6_gc         = (0x08<<12),
    AC_TIM_CCMR2_IC4F_DIV8N8_gc         = (0x09<<12),
    AC_TIM_CCMR2_IC4F_DIV16N5_gc        = (0x0A<<12),
    AC_TIM_CCMR2_IC4F_DIV16N6_gc        = (0x0B<<12),
    AC_TIM_CCMR2_IC4F_DIV16N8_gc        = (0x0C<<12),
    AC_TIM_CCMR2_IC4F_DIV32N5_gc        = (0x0D<<12),
    AC_TIM_CCMR2_IC4F_DIV32N6_gc        = (0x0E<<12),
    AC_TIM_CCMR2_IC4F_DIV32N8_gc        = (0x0F<<12),
    AC_TIM_CCMR2_IC3F_NONE_gc           = (0x00<<4),
    AC_TIM_CCMR2_IC3F_DIV1N2_gc         = (0x01<<4),
    AC_TIM_CCMR2_IC3F_DIV1N4_gc         = (0x02<<4),
    AC_TIM_CCMR2_IC3F_DIV1N8_gc         = (0x03<<4),
    AC_TIM_CCMR2_IC3F_DIV2N6_gc         = (0x04<<4),
    AC_TIM_CCMR2_IC3F_DIV2N8_gc         = (0x05<<4),
    AC_TIM_CCMR2_IC3F_DIV4N6_gc         = (0x06<<4),
    AC_TIM_CCMR2_IC3F_DIV4N8_gc         = (0x07<<4),
    AC_TIM_CCMR2_IC3F_DIV8N6_gc         = (0x08<<4),
    AC_TIM_CCMR2_IC3F_DIV8N8_gc         = (0x09<<4),
    AC_TIM_CCMR2_IC3F_DIV16N5_gc        = (0x0A<<4),
    AC_TIM_CCMR2_IC3F_DIV16N6_gc        = (0x0B<<4),
    AC_TIM_CCMR2_IC3F_DIV16N8_gc        = (0x0C<<4),
    AC_TIM_CCMR2_IC3F_DIV32N5_gc        = (0x0D<<4),
    AC_TIM_CCMR2_IC3F_DIV32N6_gc        = (0x0E<<4),
    AC_TIM_CCMR2_IC3F_DIV32N8_gc        = (0x0F<<4),
    AC_TIM_CCMR2_IC4PSC_NONE_gc         = (0x00<<10),
    AC_TIM_CCMR2_IC4PSC_N2_gc           = (0x01<<10),
    AC_TIM_CCMR2_IC4PSC_N4_gc           = (0x02<<10),
    AC_TIM_CCMR2_IC4PSC_N8_gc           = (0x03<<10),
    AC_TIM_CCMR2_IC3PSC_NONE_gc         = (0x00<<2),
    AC_TIM_CCMR2_IC3PSC_N2_gc           = (0x01<<2),
    AC_TIM_CCMR2_IC3PSC_N4_gc           = (0x02<<2),
    AC_TIM_CCMR2_IC3PSC_N8_gc           = (0x03<<2),
    AC_TIM_CCMR2_CC4S_OUT_gc            = (0x00<<8),
    AC_TIM_CCMR2_CC4S_INTI2_gc          = (0x01<<8),
    AC_TIM_CCMR2_CC4S_INTI1_gc          = (0x02<<8),
    AC_TIM_CCMR2_CC4S_INTRC_gc          = (0x03<<8),
    AC_TIM_CCMR2_CC3S_OUT_gc            = (0x00<<0),
    AC_TIM_CCMR2_CC3S_INTI2_gc          = (0x01<<0),
    AC_TIM_CCMR2_CC3S_INTI1_gc          = (0x02<<0),
    AC_TIM_CCMR2_CC3S_INTRC_gc          = (0x03<<0),
    AC_TIM_CCMR2_OC4CE_DIS_gc           = (0x00<<15),
    AC_TIM_CCMR2_OC4CE_EN_gc            = (0x01<<15),
    AC_TIM_CCMR2_OC4PE_DIS_gc           = (0x00<<11),
    AC_TIM_CCMR2_OC4PE_EN_gc            = (0x01<<11),
    AC_TIM_CCMR2_OC4FE_NORM_gc          = (0x00<<10),
    AC_TIM_CCMR2_OC4FE_FAST_gc          = (0x01<<10),
    AC_TIM_CCMR2_OC3CE_DIS_gc           = (0x00<<7),
    AC_TIM_CCMR2_OC3CE_EN_gc            = (0x01<<7),
    AC_TIM_CCMR2_OC3PE_DIS_gc           = (0x00<<3),
    AC_TIM_CCMR2_OC3PE_EN_gc            = (0x01<<3),
    AC_TIM_CCMR2_OC3FE_NORM_gc          = (0x00<<2),
    AC_TIM_CCMR2_OC3FE_FAST_gc          = (0x01<<2),
} AC_TIM_CCMR2_t;

#define AC_TIM_CCMR2_OC4M_bm        (0x807000)
#define AC_TIM_CCMR2_OC3M_bm        (0x10070)
#define AC_TIM_CCMR2_IC4F_bm        (0x0F<<12)
#define AC_TIM_CCMR2_IC4PSC_bm      (0x03<<10)
#define AC_TIM_CCMR2_OC4CE_bm       (0x01<<15)
#define AC_TIM_CCMR2_OC4PE_bm       (0x01<<11)
#define AC_TIM_CCMR2_OC4FE_bm       (0x01<<10)
#define AC_TIM_CCMR2_CC4S_bm        (0x03<<8)
#define AC_TIM_CCMR2_IC3F_bm        (0x0F<<4)
#define AC_TIM_CCMR2_IC3PSC_bm      (0x03<<2)
#define AC_TIM_CCMR2_OC3CE_bm       (0x01<<7)
#define AC_TIM_CCMR2_OC3PE_bm       (0x01<<3)
#define AC_TIM_CCMR2_OC3FE_bm       (0x01<<2)
#define AC_TIM_CCMR2_CC3S_bm        (0x03<<0)

typedef enum 
{
    AC_TIM_CCER_CC1E_DIS_gc         = (0x00<<0),
    AC_TIM_CCER_CC1E_EN_gc          = (0x01<<0),
    AC_TIM_CCER_CC2E_DIS_gc         = (0x00<<4),
    AC_TIM_CCER_CC2E_EN_gc          = (0x01<<4),
    AC_TIM_CCER_CC3E_DIS_gc         = (0x00<<8),
    AC_TIM_CCER_CC3E_EN_gc          = (0x01<<8),
    AC_TIM_CCER_CC4E_DIS_gc         = (0x00<<12),
    AC_TIM_CCER_CC4E_EN_gc          = (0x01<<12),
    AC_TIM_CCER_CC5E_DIS_gc         = (0x00<<16),
    AC_TIM_CCER_CC5E_EN_gc          = (0x01<<16),
    AC_TIM_CCER_CC6E_DIS_gc         = (0x00<<20),
    AC_TIM_CCER_CC6E_EN_gc          = (0x01<<20),
    AC_TIM_CCER_CC1P_ACTHI_gc       = (0x00<<1),
    AC_TIM_CCER_CC1P_ACTLO_gc       = (0x01<<1),
    AC_TIM_CCER_CC2P_ACTHI_gc       = (0x00<<5),
    AC_TIM_CCER_CC2P_ACTLO_gc       = (0x01<<5),
    AC_TIM_CCER_CC3P_ACTHI_gc       = (0x00<<9),
    AC_TIM_CCER_CC3P_ACTLO_gc       = (0x01<<9),
    AC_TIM_CCER_CC4P_ACTHI_gc       = (0x00<<13),
    AC_TIM_CCER_CC4P_ACTLO_gc       = (0x01<<13),
    AC_TIM_CCER_CC5P_ACTHI_gc       = (0x00<<17),
    AC_TIM_CCER_CC5P_ACTLO_gc       = (0x01<<17),
    AC_TIM_CCER_CC6P_ACTHI_gc       = (0x00<<21),
    AC_TIM_CCER_CC6P_ACTLO_gc       = (0x01<<21),
    AC_TIM_CCER_CC1NE_DIS_gc        = (0x00<<2),
    AC_TIM_CCER_CC1NE_EN_gc         = (0x01<<2),
    AC_TIM_CCER_CC2NE_DIS_gc        = (0x00<<6),
    AC_TIM_CCER_CC2NE_EN_gc         = (0x01<<6),
    AC_TIM_CCER_CC3NE_DIS_gc        = (0x00<<10),
    AC_TIM_CCER_CC3NE_EN_gc         = (0x01<<10),
    AC_TIM_CCER_CC1NP_ACTHI_gc      = (0x00<<3),
    AC_TIM_CCER_CC1NP_ACTLO_gc      = (0x01<<3),
    AC_TIM_CCER_CC2NP_ACTHI_gc      = (0x00<<7),
    AC_TIM_CCER_CC2NP_ACTLO_gc      = (0x01<<7),
    AC_TIM_CCER_CC3NP_ACTHI_gc      = (0x00<<11),
    AC_TIM_CCER_CC3NP_ACTLO_gc      = (0x01<<11),
    AC_TIM_CCER_CC4NP_ACTHI_gc      = (0x00<<15),
    AC_TIM_CCER_CC4NP_ACTLO_gc      = (0x01<<15),
    AC_TIM_CCER_CC1IN_RIS_gc        = (0x00<<1),
    AC_TIM_CCER_CC1IN_FALL_gc       = (0x01<<1),
    AC_TIM_CCER_CC1IN_BOTH_gc       = (0x05<<1),
    AC_TIM_CCER_CC2IN_RIS_gc        = (0x00<<5),
    AC_TIM_CCER_CC2IN_FALL_gc       = (0x01<<5),
    AC_TIM_CCER_CC2IN_BOTH_gc       = (0x05<<5),
    AC_TIM_CCER_CC3IN_RIS_gc        = (0x00<<9),
    AC_TIM_CCER_CC3IN_FALL_gc       = (0x01<<9),
    AC_TIM_CCER_CC3IN_BOTH_gc       = (0x05<<9),
    AC_TIM_CCER_CC4IN_RIS_gc        = (0x00<<13),
    AC_TIM_CCER_CC4IN_FALL_gc       = (0x01<<13),
    AC_TIM_CCER_CC4IN_BOTH_gc       = (0x05<<13),
} AC_TIM_CCER_t;

#define AC_TIM_CCER_CC6P_bm         (0x01<<21)
#define AC_TIM_CCER_CC6E_bm         (0x01<<20)
#define AC_TIM_CCER_CC5P_bm         (0x01<<17)
#define AC_TIM_CCER_CC5E_bm         (0x01<<16)
#define AC_TIM_CCER_CC4NP_bm        (0x01<<15)
#define AC_TIM_CCER_CC4P_bm         (0x01<<13)
#define AC_TIM_CCER_CC4E_bm         (0x01<<12)
#define AC_TIM_CCER_CC3NP_bm        (0x01<<11)
#define AC_TIM_CCER_CC3NE_bm        (0x01<<10)
#define AC_TIM_CCER_CC3P_bm         (0x01<<9)
#define AC_TIM_CCER_CC3E_bm         (0x01<<8)
#define AC_TIM_CCER_CC2NP_bm        (0x01<<7)
#define AC_TIM_CCER_CC2NE_bm        (0x01<<6)
#define AC_TIM_CCER_CC2P_bm         (0x01<<5)
#define AC_TIM_CCER_CC2E_bm         (0x01<<4)
#define AC_TIM_CCER_CC1NP_bm        (0x01<<3)
#define AC_TIM_CCER_CC1NE_bm        (0x01<<2)
#define AC_TIM_CCER_CC1P_bm         (0x01<<1)
#define AC_TIM_CCER_CC1E_bm         (0x01<<0)
// Masks for CCxP and CCxNP pins when channel is configured as input
#define AC_TIM_CCER_CC1I_bm         (0x0A)
#define AC_TIM_CCER_CC2I_bm         (0xA0)
#define AC_TIM_CCER_CC3I_bm         (0xA000)

#define AC_TIM_CNT_CNT_bm           (0xFFFF<<0)
#define AC_TIM_CNT_UIFCPY_bm        (0x01<<31)

#define AC_TIM_PSC_PSC_bm           (0xFFFF<<0)

#define AC_TIM_ARR_ARR_bm           (0xFFFF<<0)

#define AC_TIM_RCR_REP_bm           (0xFFFF<<0)

#define AC_TIM_CCR1_CCR1_bm         (0xFFFF<<0)

#define AC_TIM_CCR2_CCR2_bm         (0xFFFF<<0)

#define AC_TIM_CCR3_CCR3_bm         (0xFFFF<<0)

#define AC_TIM_CCR4_CCR4_bm         (0xFFFF<<0)

typedef enum 
{
    AC_TIM_CCR5_GC5C3_NONE_gc       = (0x00<<31),
    AC_TIM_CCR5_GC5C3_AND_gc        = (0x01<<31),
    AC_TIM_CCR5_GC5C2_NONE_gc       = (0x00<<30),
    AC_TIM_CCR5_GC5C2_AND_gc        = (0x01<<30),
    AC_TIM_CCR5_GC5C1_NONE_gc       = (0x00<<29),
    AC_TIM_CCR5_GC5C1_AND_gc        = (0x01<<29),
} AC_TIM_CCR5_t;

#define AC_TIM_CCR5_CCR5_bm         (0xFFFF<<0)
#define AC_TIM_CCR5_GC5C3_bm        (0x01<<31)
#define AC_TIM_CCR5_GC5C2_bm        (0x01<<30)
#define AC_TIM_CCR5_GC5C1_bm        (0x01<<29)

#define AC_TIM_CCR6_CCR6_bm         (0xFFFF<<0)

typedef enum 
{
    AC_TIM_BDTR_BK2P_ACTLO_gc       = (0x00<<25),
    AC_TIM_BDTR_BK2P_ACTHI_gc       = (0x01<<25),
    AC_TIM_BDTR_BK2E_DIS_gc         = (0x00<<24),
    AC_TIM_BDTR_BK2E_EN_gc          = (0x01<<24),
    AC_TIM_BDTR_BK2F_NONE_gc        = (0x00<<20),
    AC_TIM_BDTR_BK2F_DIVBY1N2_gc    = (0x01<<20),
    AC_TIM_BDTR_BK2F_DIVBY1N4_gc    = (0x02<<20),
    AC_TIM_BDTR_BK2F_DIVBY1N8_gc    = (0x03<<20),
    AC_TIM_BDTR_BK2F_DIVBY2N6_gc    = (0x04<<20),
    AC_TIM_BDTR_BK2F_DIVBY2N8_gc    = (0x05<<20),
    AC_TIM_BDTR_BK2F_DIVBY4N6_gc    = (0x06<<20),
    AC_TIM_BDTR_BK2F_DIVBY4N8_gc    = (0x07<<20),
    AC_TIM_BDTR_BK2F_DIVBY8N6_gc    = (0x08<<20),
    AC_TIM_BDTR_BK2F_DIVBY8N8_gc    = (0x09<<20),
    AC_TIM_BDTR_BK2F_DIVBY16N5_gc   = (0x0A<<20),
    AC_TIM_BDTR_BK2F_DIVBY16N6_gc   = (0x0B<<20),
    AC_TIM_BDTR_BK2F_DIVBY16N8_gc   = (0x0C<<20),
    AC_TIM_BDTR_BK2F_DIVBY32N5_gc   = (0x0D<<20),
    AC_TIM_BDTR_BK2F_DIVBY32N6_gc   = (0x0E<<20),
    AC_TIM_BDTR_BK2F_DIVBY32N8_gc   = (0x0F<<20),
    AC_TIM_BDTR_BKF_NONE_gc         = (0x00<<16),
    AC_TIM_BDTR_BKF_DIVBY1N2_gc     = (0x01<<16),
    AC_TIM_BDTR_BKF_DIVBY1N4_gc     = (0x02<<16),
    AC_TIM_BDTR_BKF_DIVBY1N8_gc     = (0x03<<16),
    AC_TIM_BDTR_BKF_DIVBY2N6_gc     = (0x04<<16),
    AC_TIM_BDTR_BKF_DIVBY2N8_gc     = (0x05<<16),
    AC_TIM_BDTR_BKF_DIVBY4N6_gc     = (0x06<<16),
    AC_TIM_BDTR_BKF_DIVBY4N8_gc     = (0x07<<16),
    AC_TIM_BDTR_BKF_DIVBY8N6_gc     = (0x08<<16),
    AC_TIM_BDTR_BKF_DIVBY8N8_gc     = (0x09<<16),
    AC_TIM_BDTR_BKF_DIVBY16N5_gc    = (0x0A<<16),
    AC_TIM_BDTR_BKF_DIVBY16N6_gc    = (0x0B<<16),
    AC_TIM_BDTR_BKF_DIVBY16N8_gc    = (0x0C<<16),
    AC_TIM_BDTR_BKF_DIVBY32N5_gc    = (0x0D<<16),
    AC_TIM_BDTR_BKF_DIVBY32N6_gc    = (0x0E<<16),
    AC_TIM_BDTR_BKF_DIVBY32N8_gc    = (0x0F<<16),
    AC_TIM_BDTR_MOE_DIS_gc          = (0x00<<15),
    AC_TIM_BDTR_MOE_EN_gc           = (0x01<<15),
    AC_TIM_BDTR_AOE_DIS_gc          = (0x00<<14),
    AC_TIM_BDTR_AOE_EN_gc           = (0x01<<14),
    AC_TIM_BDTR_BKP_ACTLO_gc        = (0x00<<13),
    AC_TIM_BDTR_BKP_ACTHI_gc        = (0x01<<13),
    AC_TIM_BDTR_BKE_DIS_gc          = (0x00<<12),
    AC_TIM_BDTR_BKE_EN_gc           = (0x01<<12),
    AC_TIM_BDTR_OSSR_DIS_gc         = (0x00<<11),
    AC_TIM_BDTR_OSSR_EN_gc          = (0x01<<11),
    AC_TIM_BDTR_OSSI_DIS_gc         = (0x00<<10),
    AC_TIM_BDTR_OSSI_EN_gc          = (0x01<<10),
    AC_TIM_BDTR_LOCK_OFF_gc         = (0x00<<8),
    AC_TIM_BDTR_LOCK_LVL1_gc        = (0x01<<8),
    AC_TIM_BDTR_LOCK_LVL2_gc        = (0x02<<8),
    AC_TIM_BDTR_LOCK_LVL3_gc        = (0x03<<8),
} AC_TIM_BDTR_t;

#define AC_TIM_BDTR_BK2P_bm         (0x01<<25)
#define AC_TIM_BDTR_BK2E_bm         (0x01<<24)
#define AC_TIM_BDTR_BK2F_bm         (0x0F<<20)
#define AC_TIM_BDTR_BKF_bm          (0x0F<<16)
#define AC_TIM_BDTR_MOE_bm          (0x01<<15)
#define AC_TIM_BDTR_AOE_bm          (0x01<<14)
#define AC_TIM_BDTR_BKP_bm          (0x01<<13)
#define AC_TIM_BDTR_BKE_bm          (0x01<<12)
#define AC_TIM_BDTR_OSSR_bm         (0x01<<11)
#define AC_TIM_BDTR_OSSI_bm         (0x01<<10)
#define AC_TIM_BDTR_LOCK_bm         (0x03<<8)
#define AC_TIM_BDTR_DTG_bm          (0xFF<<0)

typedef enum 
{
    AC_TIM_CCMR3_OC6M_FROZEN_gc         = (0x00<<12),
    AC_TIM_CCMR3_OC6M_CH1_ACT_gc        = (0x01<<12),
    AC_TIM_CCMR3_OC6M_CH1_INACT_gc      = (0x02<<12),
    AC_TIM_CCMR3_OC6M_TOGGLE_gc         = (0x03<<12),
    AC_TIM_CCMR3_OC6M_FINACTIVE_gc      = (0x04<<12),
    AC_TIM_CCMR3_OC6M_FACTIVE_gc        = (0x05<<12),
    AC_TIM_CCMR3_OC6M_PWMM1_gc          = (0x06<<12),
    AC_TIM_CCMR3_OC6M_PWMM2_gc          = (0x07<<12),
    AC_TIM_CCMR3_OC6M_OPMM1_gc          = ((0x01<<24)|((0x00<<12))),
    AC_TIM_CCMR3_OC6M_OPMM2_gc          = ((0x01<<24)|((0x01<<12))),
    AC_TIM_CCMR3_OC6M_CPWMM1_gc         = ((0x01<<24)|((0x04<<12))),
    AC_TIM_CCMR3_OC6M_CPWMM2_gc         = ((0x01<<24)|((0x05<<12))),
    AC_TIM_CCMR3_OC6M_APWMM1_gc         = ((0x01<<24)|((0x06<<12))),
    AC_TIM_CCMR3_OC5M_FROZEN_gc         = (0x00<<4),
    AC_TIM_CCMR3_OC5M_CH1_ACT_gc        = (0x01<<4),
    AC_TIM_CCMR3_OC5M_CH1_INACT_gc      = (0x02<<4),
    AC_TIM_CCMR3_OC5M_TOGGLE_gc         = (0x03<<4),
    AC_TIM_CCMR3_OC5M_FINACTIVE_gc      = (0x04<<4),
    AC_TIM_CCMR3_OC5M_FACTIVE_gc        = (0x05<<4),
    AC_TIM_CCMR3_OC5M_PWMM1_gc          = (0x06<<4),
    AC_TIM_CCMR3_OC5M_PWMM2_gc          = (0x07<<4),
    AC_TIM_CCMR3_OC5M_OPMM1_gc          = ((0x01<<16)|((0x00<<4))),
    AC_TIM_CCMR3_OC5M_OPMM2_gc          = ((0x01<<16)|((0x01<<4))),
    AC_TIM_CCMR3_OC5M_CPWMM1_gc         = ((0x01<<16)|((0x04<<4))),
    AC_TIM_CCMR3_OC5M_CPWMM2_gc         = ((0x01<<16)|((0x05<<4))),
    AC_TIM_CCMR3_OC5M_APWMM1_gc         = ((0x01<<16)|((0x06<<4))),
    AC_TIM_CCMR3_OC5M_APWMM2_gc         = ((0x01<<16)|((0x07<<4))),
    AC_TIM_CCMR3_OC5M_APWMM3_gc         = ((0x01<<16)|((0x07<<4))),
    AC_TIM_CCMR3_OC6CE_DIS_gc           = (0x00<<15),
    AC_TIM_CCMR3_OC6CE_EN_gc            = (0x01<<15),
    AC_TIM_CCMR3_OC6PE_DIS_gc           = (0x00<<11),
    AC_TIM_CCMR3_OC6PE_EN_gc            = (0x01<<11),
    AC_TIM_CCMR3_OC6FE_NORM_gc          = (0x00<<10),
    AC_TIM_CCMR3_OC6FE_FAST_gc          = (0x01<<10),
    AC_TIM_CCMR3_OC5CE_DIS_gc           = (0x00<<7),
    AC_TIM_CCMR3_OC5CE_EN_gc            = (0x01<<7),
    AC_TIM_CCMR3_OC5PE_DIS_gc           = (0x00<<3),
    AC_TIM_CCMR3_OC5PE_EN_gc            = (0x01<<3),
    AC_TIM_CCMR3_OC5FE_NORM_gc          = (0x00<<2),
    AC_TIM_CCMR3_OC5FE_FAST_gc          = (0x01<<2),
} AC_TIM_CCMR3_t;

#define AC_TIM_CCMR3_OC6M_bm        (0x807000)
#define AC_TIM_CCMR3_OC5M_bm        (0x10070)
#define AC_TIM_CCMR3_OC6CE_bm       (0x01<<15)
#define AC_TIM_CCMR3_OC6PE_bm       (0x01<<11)
#define AC_TIM_CCMR3_OC6FE_bm       (0x01<<10)
#define AC_TIM_CCMR3_OC5CE_bm       (0x01<<7)
#define AC_TIM_CCMR3_OC5PE_bm       (0x01<<3)
#define AC_TIM_CCMR3_OC5FE_bm       (0x01<<2)

// Registers for general purpose timers TIM2, 3, and TIM4
typedef struct 
{
    register32_t CR1;                           // Control register 1, 0x00
    register32_t CR2;                           // Control register 2, 0x04
    register32_t SMCR;                          // Slave mode control register, 0x08
    register32_t DIER;                          // DMA/enable interrupt register, 0x0C
    register32_t SR;                            // Status register, 0x10
    register32_t EGR;                           // Event generation register, 0x14
    register32_t CCMR1;                         // Capture/compare mode register 1, 0x18
    register32_t CCMR2;                         // Capture/compare mode register 2, 0x1C
    register32_t CCER;                          // Capture/compare enable register, 0x20
    register32_t CNT;                           // Counter, 0x24
    // TODO: PSC is 16bit register?
    register32_t PSC;                           // Prescaler, 0x28
    register32_t ARR;                           // Auto-reload register, 0x2C
    register32_t reserved_0x30;
    register32_t CCR1;                          // Capture/compare register 1, 0x34
    register32_t CCR2;                          // Capture/compare register 2, 0x38
    register32_t CCR3;                          // Capture/compare register 3, 0x3C
    register32_t CCR4;                          // Capture/compare register 4, 0x40
    register32_t reserved_0x44;
    register32_t DCR;                           // DMA control register, 0x48
    register32_t DMAR;                          // DMA address for full transfer, 0x4C
} TIM_t;

typedef enum 
{
    TIM_CR1_UIFREMAP_EN_gc          = (0x01<<11),
    TIM_CR1_UIFREMAP_DIS_gc         = (0x00<<11),
    TIM_CR1_CKD_NODIV_gc            = (0x00<<8),
    TIM_CR1_CKD_DIVBY2_gc           = (0x01<<8),
    TIM_CR1_CKD_DIVBY4_gc           = (0x02<<8),
    TIM_CR1_CKD_DIVBY8_gc           = (0x01<<8),
    TIM_CR1_ARPE_BUF_gc             = (0x01<<7),
    TIM_CR1_ARPE_UNBUF_gc           = (0x01<<7),
    TIM_CR1_CMS_EDGE_gc             = (0x00<<5),
    TIM_CR1_CMS_CENTER1_gc          = (0x01<<5),
    TIM_CR1_CMS_CENTER2_gc          = (0x02<<5),
    TIM_CR1_CMS_CENTER3_gc          = (0x03<<5),
    TIM_CR1_DIR_UP_gc               = (0x00<<4),
    TIM_CR1_DIR_DOWN_gc             = (0x01<<4),
    TIM_CR1_OPM_EN_gc               = (0x00<<3),
    TIM_CR1_OPM_DIS_gc              = (0x01<<3),
    TIM_CR1_URS_ANY_gc              = (0x00<<2),
    TIM_CR1_URS_ONLYOFUF_gc         = (0x00<<2),
    TIM_CR1_UDIS_EN_gc              = (0x00<<1),
    TIM_CR1_UDIS_DIS_gc             = (0x01<<1),
    TIM_CR1_CEN_EN_gc               = (0x01<<0),
    TIM_CR1_CEN_DIS_gc              = (0x00<<0)
} TIM_CR1_t;

#define TIM_CR1_UIFREMAP_bm         (0x01<<11)
#define TIM_CR1_CKD_bm              (0x03<<8)
#define TIM_CR1_ARPE_bm             (0x01<<7)
#define TIM_CR1_CMS_bm              (0x03<<5)
#define TIM_CR1_DIR_bm              (0x01<<4)
#define TIM_CR1_OPM_bm              (0x01<<3)
#define TIM_CR1_URS_bm              (0x01<<2)
#define TIM_CR1_UDIS_bm             (0x01<<1)
#define TIM_CR1_CEN_bm              (0x01<<0)

typedef enum
{
    TIM_DIER_TDE_EN_gc          = (0x01<<14),
    TIM_DIER_TDE_DIS_gc         = (0x00<<14),
    TIM_DIER_CC4DE_EN_gc        = (0x01<<12),
    TIM_DIER_CC4DE_DIS_gc       = (0x00<<12),
    TIM_DIER_CC3DE_DIS_gc       = (0x00<<11),
    TIM_DIER_CC3DE_EN_gc        = (0x01<<11),
    TIM_DIER_CC2DE_EN_gc        = (0x01<<10),
    TIM_DIER_CC2DE_DIS_gc       = (0x00<<10),
    TIM_DIER_CC1DE_DIS_gc       = (0x00<<9),
    TIM_DIER_CC1DE_EN_gc        = (0x01<<9),
    TIM_DIER_UDE_EN_gc          = (0x01<<8),
    TIM_DIER_UDE_DIS_gc         = (0x00<<8),
    TIM_DIER_TIE_EN_gc          = (0x01<<6),
    TIM_DIER_TIE_DIS_gc         = (0x00<<6),
    TIM_DIER_CC4IE_EN_gc        = (0x01<<4),
    TIM_DIER_CC4IE_DIS_gc       = (0x00<<4),
    TIM_DIER_CC3IE_DIS_gc       = (0x00<<3),
    TIM_DIER_CC3IE_EN_gc        = (0x01<<3),
    TIM_DIER_CC2IE_EN_gc        = (0x01<<2),
    TIM_DIER_CC2IE_DIS_gc       = (0x00<<2),
    TIM_DIER_CC1IE_DIS_gc       = (0x00<<1),
    TIM_DIER_CC1IE_EN_gc        = (0x01<<1),
    TIM_DIER_UIE_EN_gc          = (0x01<<0),
    TIM_DIER_UIE_DIS_gc         = (0x00<<0),
} TIM_DIER_t;

#define TIM_DIER_TDE_bm         (0x01<<14)
#define TIM_DIER_CC4DE_bm       (0x01<<12)
#define TIM_DIER_CC3DE_bm       (0x01<<11)
#define TIM_DIER_CC2DE_bm       (0x01<<10)
#define TIM_DIER_CC1DE_bm       (0x01<<9)
#define TIM_DIER_UDE_bm         (0x01<<8)
#define TIM_DIER_TIE_bm         (0x01<<6)
#define TIM_DIER_CC4IE_bm       (0x01<<4)
#define TIM_DIER_CC3IE_bm       (0x01<<3)
#define TIM_DIER_CC2IE_bm       (0x01<<2)
#define TIM_DIER_CC1IE_bm       (0x01<<1)
#define TIM_DIER_UIE_bm         (0x01<<0)

typedef enum 
{
    TIM_CCMR1_OC2M_FROZEN_gc         = (0x00<<12),
    TIM_CCMR1_OC2M_CH1_ACT_gc        = (0x01<<12),
    TIM_CCMR1_OC2M_CH1_INACT_gc      = (0x02<<12),
    TIM_CCMR1_OC2M_TOGGLE_gc         = (0x03<<12),
    TIM_CCMR1_OC2M_FINACTIVE_gc      = (0x04<<12),
    TIM_CCMR1_OC2M_FACTIVE_gc        = (0x05<<12),
    TIM_CCMR1_OC2M_PWMM1_gc          = (0x06<<12),
    TIM_CCMR1_OC2M_PWMM2_gc          = (0x07<<12),
    TIM_CCMR1_OC2M_OPMM1_gc          = ((0x01<<24)|((0x00<<12))),
    TIM_CCMR1_OC2M_OPMM2_gc          = ((0x01<<24)|((0x01<<12))),
    TIM_CCMR1_OC2M_CPWMM1_gc         = ((0x01<<24)|((0x04<<12))),
    TIM_CCMR1_OC2M_CPWMM2_gc         = ((0x01<<24)|((0x05<<12))),
    TIM_CCMR1_OC2M_APWMM1_gc         = ((0x01<<24)|((0x06<<12))),
    TIM_CCMR1_OC1M_FROZEN_gc         = (0x00<<4),
    TIM_CCMR1_OC1M_CH1_ACT_gc        = (0x01<<4),
    TIM_CCMR1_OC1M_CH1_INACT_gc      = (0x02<<4),
    TIM_CCMR1_OC1M_TOGGLE_gc         = (0x03<<4),
    TIM_CCMR1_OC1M_FINACTIVE_gc      = (0x04<<4),
    TIM_CCMR1_OC1M_FACTIVE_gc        = (0x05<<4),
    TIM_CCMR1_OC1M_PWMM1_gc          = (0x06<<4),
    TIM_CCMR1_OC1M_PWMM2_gc          = (0x07<<4),
    TIM_CCMR1_OC1M_OPMM1_gc          = ((0x01<<16)|((0x00<<4))),
    TIM_CCMR1_OC1M_OPMM2_gc          = ((0x01<<16)|((0x01<<4))),
    TIM_CCMR1_OC1M_CPWMM1_gc         = ((0x01<<16)|((0x04<<4))),
    TIM_CCMR1_OC1M_CPWMM2_gc         = ((0x01<<16)|((0x05<<4))),
    TIM_CCMR1_OC1M_APWMM1_gc         = ((0x01<<16)|((0x06<<4))),
    TIM_CCMR1_OC1M_APWMM2_gc         = ((0x01<<16)|((0x07<<4))),
    TIM_CCMR1_OC1M_APWMM3_gc         = ((0x01<<16)|((0x07<<4))),
    TIM_CCMR1_IC2F_NONE_gc           = (0x00<<12),
    TIM_CCMR1_IC2F_DIV1N2_gc         = (0x01<<12),
    TIM_CCMR1_IC2F_DIV1N4_gc         = (0x02<<12),
    TIM_CCMR1_IC2F_DIV1N8_gc         = (0x03<<12),
    TIM_CCMR1_IC2F_DIV2N6_gc         = (0x04<<12),
    TIM_CCMR1_IC2F_DIV2N8_gc         = (0x05<<12),
    TIM_CCMR1_IC2F_DIV4N6_gc         = (0x06<<12),
    TIM_CCMR1_IC2F_DIV4N8_gc         = (0x07<<12),
    TIM_CCMR1_IC2F_DIV8N6_gc         = (0x08<<12),
    TIM_CCMR1_IC2F_DIV8N8_gc         = (0x09<<12),
    TIM_CCMR1_IC2F_DIV16N5_gc        = (0x0A<<12),
    TIM_CCMR1_IC2F_DIV16N6_gc        = (0x0B<<12),
    TIM_CCMR1_IC2F_DIV16N8_gc        = (0x0C<<12),
    TIM_CCMR1_IC2F_DIV32N5_gc        = (0x0D<<12),
    TIM_CCMR1_IC2F_DIV32N6_gc        = (0x0E<<12),
    TIM_CCMR1_IC2F_DIV32N8_gc        = (0x0F<<12),
    TIM_CCMR1_IC1F_NONE_gc           = (0x00<<4),
    TIM_CCMR1_IC1F_DIV1N2_gc         = (0x01<<4),
    TIM_CCMR1_IC1F_DIV1N4_gc         = (0x02<<4),
    TIM_CCMR1_IC1F_DIV1N8_gc         = (0x03<<4),
    TIM_CCMR1_IC1F_DIV2N6_gc         = (0x04<<4),
    TIM_CCMR1_IC1F_DIV2N8_gc         = (0x05<<4),
    TIM_CCMR1_IC1F_DIV4N6_gc         = (0x06<<4),
    TIM_CCMR1_IC1F_DIV4N8_gc         = (0x07<<4),
    TIM_CCMR1_IC1F_DIV8N6_gc         = (0x08<<4),
    TIM_CCMR1_IC1F_DIV8N8_gc         = (0x09<<4),
    TIM_CCMR1_IC1F_DIV16N5_gc        = (0x0A<<4),
    TIM_CCMR1_IC1F_DIV16N6_gc        = (0x0B<<4),
    TIM_CCMR1_IC1F_DIV16N8_gc        = (0x0C<<4),
    TIM_CCMR1_IC1F_DIV32N5_gc        = (0x0D<<4),
    TIM_CCMR1_IC1F_DIV32N6_gc        = (0x0E<<4),
    TIM_CCMR1_IC1F_DIV32N8_gc        = (0x0F<<4),
    TIM_CCMR1_IC2PSC_NONE_gc         = (0x00<<10),
    TIM_CCMR1_IC2PSC_N2_gc           = (0x01<<10),
    TIM_CCMR1_IC2PSC_N4_gc           = (0x02<<10),
    TIM_CCMR1_IC2PSC_N8_gc           = (0x03<<10),
    TIM_CCMR1_IC1PSC_NONE_gc         = (0x00<<2),
    TIM_CCMR1_IC1PSC_N2_gc           = (0x01<<2),
    TIM_CCMR1_IC1PSC_N4_gc           = (0x02<<2),
    TIM_CCMR1_IC1PSC_N8_gc           = (0x03<<2),
    TIM_CCMR1_CC2S_OUT_gc            = (0x00<<8),
    TIM_CCMR1_CC2S_INTI2_gc          = (0x01<<8),
    TIM_CCMR1_CC2S_INTI1_gc          = (0x02<<8),
    TIM_CCMR1_CC2S_INTRC_gc          = (0x03<<8),
    TIM_CCMR1_CC1S_OUT_gc            = (0x00<<0),
    TIM_CCMR1_CC1S_INTI2_gc          = (0x01<<0),
    TIM_CCMR1_CC1S_INTI1_gc          = (0x02<<0),
    TIM_CCMR1_CC1S_INTRC_gc          = (0x03<<0),
    TIM_CCMR1_OC2CE_DIS_gc           = (0x00<<15),
    TIM_CCMR1_OC2CE_EN_gc            = (0x01<<15),
    TIM_CCMR1_OC2PE_DIS_gc           = (0x00<<11),
    TIM_CCMR1_OC2PE_EN_gc            = (0x01<<11),
    TIM_CCMR1_OC2FE_NORM_gc          = (0x00<<10),
    TIM_CCMR1_OC2FE_FAST_gc          = (0x01<<10),
    TIM_CCMR1_OC1CE_DIS_gc           = (0x00<<7),
    TIM_CCMR1_OC1CE_EN_gc            = (0x01<<7),
    TIM_CCMR1_OC1PE_DIS_gc           = (0x00<<3),
    TIM_CCMR1_OC1PE_EN_gc            = (0x01<<3),
    TIM_CCMR1_OC1FE_NORM_gc          = (0x00<<2),
    TIM_CCMR1_OC1FE_FAST_gc          = (0x01<<2),
} TIM_CCMR1_t;

#define TIM_CCMR1_OC2M_bm        (0x807000)
#define TIM_CCMR1_OC1M_bm        (0x10070)
#define TIM_CCMR1_IC2F_bm        (0x0F<<12)
#define TIM_CCMR1_IC2PSC_bm      (0x03<<10)
#define TIM_CCMR1_OC2CE_bm       (0x01<<15)
#define TIM_CCMR1_OC2PE_bm       (0x01<<11)
#define TIM_CCMR1_OC2FE_bm       (0x01<<10)
#define TIM_CCMR1_CC2S_bm        (0x03<<8)
#define TIM_CCMR1_IC1F_bm        (0x0F<<4)
#define TIM_CCMR1_IC1PSC_bm      (0x03<<2)
#define TIM_CCMR1_OC1CE_bm       (0x01<<7)
#define TIM_CCMR1_OC1PE_bm       (0x01<<3)
#define TIM_CCMR1_OC1FE_bm       (0x01<<2)
#define TIM_CCMR1_CC1S_bm        (0x03<<0)

typedef enum 
{
    TIM_CCER_CC1E_DIS_gc         = (0x00<<0),
    TIM_CCER_CC1E_EN_gc          = (0x01<<0),
    TIM_CCER_CC2E_DIS_gc         = (0x00<<4),
    TIM_CCER_CC2E_EN_gc          = (0x01<<4),
    TIM_CCER_CC3E_DIS_gc         = (0x00<<8),
    TIM_CCER_CC3E_EN_gc          = (0x01<<8),
    TIM_CCER_CC4E_DIS_gc         = (0x00<<12),
    TIM_CCER_CC4E_EN_gc          = (0x01<<12),
    TIM_CCER_CC5E_DIS_gc         = (0x00<<16),
    TIM_CCER_CC5E_EN_gc          = (0x01<<16),
    TIM_CCER_CC6E_DIS_gc         = (0x00<<20),
    TIM_CCER_CC6E_EN_gc          = (0x01<<20),
    TIM_CCER_CC1P_ACTHI_gc       = (0x00<<1),
    TIM_CCER_CC1P_ACTLO_gc       = (0x01<<1),
    TIM_CCER_CC2P_ACTHI_gc       = (0x00<<5),
    TIM_CCER_CC2P_ACTLO_gc       = (0x01<<5),
    TIM_CCER_CC3P_ACTHI_gc       = (0x00<<9),
    TIM_CCER_CC3P_ACTLO_gc       = (0x01<<9),
    TIM_CCER_CC4P_ACTHI_gc       = (0x00<<13),
    TIM_CCER_CC4P_ACTLO_gc       = (0x01<<13),
    TIM_CCER_CC5P_ACTHI_gc       = (0x00<<17),
    TIM_CCER_CC5P_ACTLO_gc       = (0x01<<17),
    TIM_CCER_CC6P_ACTHI_gc       = (0x00<<21),
    TIM_CCER_CC6P_ACTLO_gc       = (0x01<<21),
    TIM_CCER_CC1NE_DIS_gc        = (0x00<<2),
    TIM_CCER_CC1NE_EN_gc         = (0x01<<2),
    TIM_CCER_CC2NE_DIS_gc        = (0x00<<6),
    TIM_CCER_CC2NE_EN_gc         = (0x01<<6),
    TIM_CCER_CC3NE_DIS_gc        = (0x00<<10),
    TIM_CCER_CC3NE_EN_gc         = (0x01<<10),
    TIM_CCER_CC1NP_ACTHI_gc      = (0x00<<3),
    TIM_CCER_CC1NP_ACTLO_gc      = (0x01<<3),
    TIM_CCER_CC2NP_ACTHI_gc      = (0x00<<7),
    TIM_CCER_CC2NP_ACTLO_gc      = (0x01<<7),
    TIM_CCER_CC3NP_ACTHI_gc      = (0x00<<11),
    TIM_CCER_CC3NP_ACTLO_gc      = (0x01<<11),
    TIM_CCER_CC4NP_ACTHI_gc      = (0x00<<15),
    TIM_CCER_CC4NP_ACTLO_gc      = (0x01<<15),
    TIM_CCER_CC1IN_RIS_gc        = (0x00<<1),
    TIM_CCER_CC1IN_FALL_gc       = (0x01<<1),
    TIM_CCER_CC1IN_BOTH_gc       = (0x05<<1),
    TIM_CCER_CC2IN_RIS_gc        = (0x00<<5),
    TIM_CCER_CC2IN_FALL_gc       = (0x01<<5),
    TIM_CCER_CC2IN_BOTH_gc       = (0x05<<5),
    TIM_CCER_CC3IN_RIS_gc        = (0x00<<9),
    TIM_CCER_CC3IN_FALL_gc       = (0x01<<9),
    TIM_CCER_CC3IN_BOTH_gc       = (0x05<<9),
    TIM_CCER_CC4IN_RIS_gc        = (0x00<<13),
    TIM_CCER_CC4IN_FALL_gc       = (0x01<<13),
    TIM_CCER_CC4IN_BOTH_gc       = (0x05<<13),
} TIM_CCER_t;

#define TIM_CCER_CC6P_bm         (0x01<<21)
#define TIM_CCER_CC6E_bm         (0x01<<20)
#define TIM_CCER_CC5P_bm         (0x01<<17)
#define TIM_CCER_CC5E_bm         (0x01<<16)
#define TIM_CCER_CC4NP_bm        (0x01<<15)
#define TIM_CCER_CC4P_bm         (0x01<<13)
#define TIM_CCER_CC4E_bm         (0x01<<12)
#define TIM_CCER_CC3NP_bm        (0x01<<11)
#define TIM_CCER_CC3NE_bm        (0x01<<10)
#define TIM_CCER_CC3P_bm         (0x01<<9)
#define TIM_CCER_CC3E_bm         (0x01<<8)
#define TIM_CCER_CC2NP_bm        (0x01<<7)
#define TIM_CCER_CC2NE_bm        (0x01<<6)
#define TIM_CCER_CC2P_bm         (0x01<<5)
#define TIM_CCER_CC2E_bm         (0x01<<4)
#define TIM_CCER_CC1NP_bm        (0x01<<3)
#define TIM_CCER_CC1NE_bm        (0x01<<2)
#define TIM_CCER_CC1P_bm         (0x01<<1)
#define TIM_CCER_CC1E_bm         (0x01<<0)
// Masks for CCxP and CCxNP pins when channel is configured as input
#define TIM_CCER_CC1I_bm         (0x0A)
#define TIM_CCER_CC2I_bm         (0xA0)
#define TIM_CCER_CC3I_bm         (0xA000)

typedef struct 
{
    register32_t MODER;                         // GPIO port mode register, 0x00 
    register16_t OTYPER;                        // GPIO port output type register, 0x04 
    register16_t reserved_0x06;                 // Reserved, 0x06 
    register32_t OSPEEDR;                       // GPIO port output speed register, 0x08 
    register32_t PUPDR;                         // GPIO port pull-up/pull-down register, 0x0C 
    register16_t IDR;                           // GPIO port input data register, 0x10 
    register16_t reserved_0x12;                 // Reserved, 0x12 
    register16_t ODR;                           // GPIO port §output data register, 0x14 
    register16_t reserved_0x16;                 // Reserved, 0x16 
    register32_t BSRR;                          // GPIO port bit set/reset register, 0x18 
    register32_t LCKR;                          // GPIO port configuration lock register, 0x1C 
    register32_t AFRL;                          // GPIO alternate function low register, 0x20-0x24 
    register32_t AFRH;                          // GPIO alternate function low register, 0x20-0x24 
    register16_t BRR;                           // GPIO bit reset register, 0x28 
    register16_t reserved_0x2A;                 // Reserved, 0x2A 
} GPIO_t;

// GPIO bitfields
// IDR
#define GPIO_IDR_IDR0_bm            (0x01<<0)
#define GPIO_IDR_IDR1_bm            (0x01<<1)
#define GPIO_IDR_IDR2_bm            (0x01<<2)
#define GPIO_IDR_IDR3_bm            (0x01<<3)
#define GPIO_IDR_IDR4_bm            (0x01<<4)
#define GPIO_IDR_IDR5_bm            (0x01<<5)
#define GPIO_IDR_IDR6_bm            (0x01<<6)
#define GPIO_IDR_IDR7_bm            (0x01<<7)
#define GPIO_IDR_IDR8_bm            (0x01<<8)
#define GPIO_IDR_IDR9_bm            (0x01<<9)
#define GPIO_IDR_IDR10_bm           (0x01<<10)
#define GPIO_IDR_IDR11_bm           (0x01<<11)
#define GPIO_IDR_IDR12_bm           (0x01<<12)
#define GPIO_IDR_IDR13_bm           (0x01<<13)
#define GPIO_IDR_IDR14_bm           (0x01<<14)
#define GPIO_IDR_IDR15_bm           (0x01<<15)

// ODR
#define GPIO_ODR_ODR0_bm            (0x01<<0)
#define GPIO_ODR_ODR1_bm            (0x01<<1)
#define GPIO_ODR_ODR2_bm            (0x01<<2)
#define GPIO_ODR_ODR3_bm            (0x01<<3)
#define GPIO_ODR_ODR4_bm            (0x01<<4)
#define GPIO_ODR_ODR5_bm            (0x01<<5)
#define GPIO_ODR_ODR6_bm            (0x01<<6)
#define GPIO_ODR_ODR7_bm            (0x01<<7)
#define GPIO_ODR_ODR8_bm            (0x01<<8)
#define GPIO_ODR_ODR9_bm            (0x01<<9)
#define GPIO_ODR_ODR10_bm           (0x01<<10)
#define GPIO_ODR_ODR11_bm           (0x01<<11)
#define GPIO_ODR_ODR12_bm           (0x01<<12)
#define GPIO_ODR_ODR13_bm           (0x01<<13)
#define GPIO_ODR_ODR14_bm           (0x01<<14)
#define GPIO_ODR_ODR15_bm           (0x01<<15)

// BSRR
// BRy
#define GPIO_BSRR_BR0_bm            ((0x01<<0)<<16)
#define GPIO_BSRR_BR1_bm            ((0x01<<1)<<16)
#define GPIO_BSRR_BR2_bm            ((0x01<<2)<<16)
#define GPIO_BSRR_BR3_bm            ((0x01<<3)<<16)
#define GPIO_BSRR_BR4_bm            ((0x01<<4)<<16)
#define GPIO_BSRR_BR5_bm            ((0x01<<5)<<16)
#define GPIO_BSRR_BR6_bm            ((0x01<<6)<<16)
#define GPIO_BSRR_BR7_bm            ((0x01<<7)<<16)
#define GPIO_BSRR_BR8_bm            ((0x01<<8)<<16)
#define GPIO_BSRR_BR9_bm            ((0x01<<9)<<16)
#define GPIO_BSRR_BR10_bm           ((0x01<<10)<<16)
#define GPIO_BSRR_BR11_bm           ((0x01<<11)<<16)
#define GPIO_BSRR_BR12_bm           ((0x01<<12)<<16)
#define GPIO_BSRR_BR13_bm           ((0x01<<13)<<16)
#define GPIO_BSRR_BR14_bm           ((0x01<<14)<<16)
#define GPIO_BSRR_BR15_bm           ((0x01<<15)<<16)

// BSy
#define GPIO_BSRR_BS0_bm            (0x01<<0)
#define GPIO_BSRR_BS1_bm            (0x01<<1)
#define GPIO_BSRR_BS2_bm            (0x01<<2)
#define GPIO_BSRR_BS3_bm            (0x01<<3)
#define GPIO_BSRR_BS4_bm            (0x01<<4)
#define GPIO_BSRR_BS5_bm            (0x01<<5)
#define GPIO_BSRR_BS6_bm            (0x01<<6)
#define GPIO_BSRR_BS7_bm            (0x01<<7)
#define GPIO_BSRR_BS8_bm            (0x01<<8)
#define GPIO_BSRR_BS9_bm            (0x01<<9)
#define GPIO_BSRR_BS10_bm           (0x01<<10)
#define GPIO_BSRR_BS11_bm           (0x01<<11)
#define GPIO_BSRR_BS12_bm           (0x01<<12)
#define GPIO_BSRR_BS13_bm           (0x01<<13)
#define GPIO_BSRR_BS14_bm           (0x01<<14)
#define GPIO_BSRR_BS15_bm           (0x01<<15)

typedef enum
{
    GPIO_MODER_OUT_gc               = 0x01,
    GPIO_MODER_IN_gc                = 0x00,
    GPIO_MODER_AF_gc                = 0x02,
    GPIO_MODER_ANA_gc               = 0x03
} GPIO_MODER_t;

// MODER
#define GPIO_MODER_MODER0_bm        (0x03<<0)
#define GPIO_MODER_MODER1_bm        (0x03<<2)
#define GPIO_MODER_MODER2_bm        (0x03<<4)
#define GPIO_MODER_MODER3_bm        (0x03<<6)
#define GPIO_MODER_MODER4_bm        (0x03<<8)
#define GPIO_MODER_MODER5_bm        (0x03<<10)
#define GPIO_MODER_MODER6_bm        (0x03<<12)
#define GPIO_MODER_MODER7_bm        (0x03<<14)
#define GPIO_MODER_MODER8_bm        (0x03<<16)
#define GPIO_MODER_MODER9_bm        (0x03<<18)
#define GPIO_MODER_MODER10_bm       (0x03<<20)
#define GPIO_MODER_MODER11_bm       (0x03<<22)
#define GPIO_MODER_MODER12_bm       (0x03<<24)
#define GPIO_MODER_MODER13_bm       (0x03<<26)
#define GPIO_MODER_MODER14_bm       (0x03<<28)
#define GPIO_MODER_MODER15_bm       (0x03<<30)

typedef enum
{
   GPIO_OTYPER_PP_gc                = 0x00,
   GPIO_OTYPER_OD_gc                = 0x01
} GPIO_OTYPER_t;

// OTYPER
#define GPIO_OTYPER_OT0_bm          (0x01<<0)
#define GPIO_OTYPER_OT1_bm          (0x01<<1)
#define GPIO_OTYPER_OT2_bm          (0x01<<2)
#define GPIO_OTYPER_OT3_bm          (0x01<<3)
#define GPIO_OTYPER_OT4_bm          (0x01<<4)
#define GPIO_OTYPER_OT5_bm          (0x01<<5)
#define GPIO_OTYPER_OT6_bm          (0x01<<6)
#define GPIO_OTYPER_OT7_bm          (0x01<<7)
#define GPIO_OTYPER_OT8_bm          (0x01<<8)
#define GPIO_OTYPER_OT9_bm          (0x01<<9)
#define GPIO_OTYPER_OT10_bm         (0x01<<10)
#define GPIO_OTYPER_OT11_bm         (0x01<<11)
#define GPIO_OTYPER_OT12_bm         (0x01<<12)
#define GPIO_OTYPER_OT13_bm         (0x01<<13)
#define GPIO_OTYPER_OT14_bm         (0x01<<14)
#define GPIO_OTYPER_OT15_bm         (0x01<<15)

typedef enum
{
    GPIO_OSPEEDR_LOW_gc             = 0x00,
    GPIO_OSPEEDR_MED_gc             = 0x01,
    GPIO_OSPEEDR_HI_gc              = 0x03
} GPIO_OSPEEDR_t;

// OSPEEDR
#define GPIO_OSPEEDR_OSPEEDR0_bm    (0x03<<0)
#define GPIO_OSPEEDR_OSPEEDR1_bm    (0x03<<2)
#define GPIO_OSPEEDR_OSPEEDR2_bm    (0x03<<4)
#define GPIO_OSPEEDR_OSPEEDR3_bm    (0x03<<6)
#define GPIO_OSPEEDR_OSPEEDR4_bm    (0x03<<8)
#define GPIO_OSPEEDR_OSPEEDR5_bm    (0x03<<10)
#define GPIO_OSPEEDR_OSPEEDR6_bm    (0x03<<12)
#define GPIO_OSPEEDR_OSPEEDR7_bm    (0x03<<14)
#define GPIO_OSPEEDR_OSPEEDR8_bm    (0x03<<16)
#define GPIO_OSPEEDR_OSPEEDR9_bm    (0x03<<18)
#define GPIO_OSPEEDR_OSPEEDR10_bm   (0x03<<20)
#define GPIO_OSPEEDR_OSPEEDR11_bm   (0x03<<22)
#define GPIO_OSPEEDR_OSPEEDR12_bm   (0x03<<24)
#define GPIO_OSPEEDR_OSPEEDR13_bm   (0x03<<26)
#define GPIO_OSPEEDR_OSPEEDR14_bm   (0x03<<28)
#define GPIO_OSPEEDR_OSPEEDR15_bm   (0x03<<30)

typedef enum
{
    GPIO_PUPDR_NONE_gc              = 0x00,
    GPIO_PUPDR_PULLUP_gc            = 0x01,
    GPIO_PUPDR_PULLDOWN_gc          = 0x02
} GPIO_PUPDR_t;

// PUPDR
#define GPIO_PUPDR_PUPDR0_bm        (0x03<<0)
#define GPIO_PUPDR_PUPDR1_bm        (0x03<<2)
#define GPIO_PUPDR_PUPDR2_bm        (0x03<<4)
#define GPIO_PUPDR_PUPDR3_bm        (0x03<<6)
#define GPIO_PUPDR_PUPDR4_bm        (0x03<<8)
#define GPIO_PUPDR_PUPDR5_bm        (0x03<<10)
#define GPIO_PUPDR_PUPDR6_bm        (0x03<<12)
#define GPIO_PUPDR_PUPDR7_bm        (0x03<<14)
#define GPIO_PUPDR_PUPDR8_bm        (0x03<<16)
#define GPIO_PUPDR_PUPDR9_bm        (0x03<<18)
#define GPIO_PUPDR_PUPDR10_bm       (0x03<<20)
#define GPIO_PUPDR_PUPDR11_bm       (0x03<<22)
#define GPIO_PUPDR_PUPDR12_bm       (0x03<<24)
#define GPIO_PUPDR_PUPDR13_bm       (0x03<<26)
#define GPIO_PUPDR_PUPDR14_bm       (0x03<<28)
#define GPIO_PUPDR_PUPDR15_bm       (0x03<<30)

typedef enum
{
    GPIO_AFR_AF0_gc                 = (0x00),
    GPIO_AFR_AF1_gc                 = (0x01),
    GPIO_AFR_AF2_gc                 = (0x02),
    GPIO_AFR_AF3_gc                 = (0x03),
    GPIO_AFR_AF4_gc                 = (0x04),
    GPIO_AFR_AF5_gc                 = (0x05),
    GPIO_AFR_AF6_gc                 = (0x06),
    GPIO_AFR_AF7_gc                 = (0x07),
    GPIO_AFR_AF8_gc                 = (0x08),
    GPIO_AFR_AF9_gc                 = (0x09),
    GPIO_AFR_AF10_gc                = (0x0A),
    GPIO_AFR_AF11_gc                = (0x0B),
    GPIO_AFR_AF12_gc                = (0x0C),
    GPIO_AFR_AF13_gc                = (0x0D),
    GPIO_AFR_AF14_gc                = (0x0E),
    GPIO_AFR_AF15_gc                = (0x0F),
} GPIO_AFR_t;

#define GPIO_AFR_AFR_bm             (0x0F)

typedef enum
{
    GPIO_PIN_0                      = 0x00,
    GPIO_PIN_1                      = 0x01,
    GPIO_PIN_2                      = 0x02,
    GPIO_PIN_3                      = 0x03,
    GPIO_PIN_4                      = 0x04,
    GPIO_PIN_5                      = 0x05,
    GPIO_PIN_6                      = 0x06,
    GPIO_PIN_7                      = 0x07,
    GPIO_PIN_8                      = 0x08,
    GPIO_PIN_9                      = 0x09,
    GPIO_PIN_10                     = 0x0A,
    GPIO_PIN_11                     = 0x0B,
    GPIO_PIN_12                     = 0x0C,
    GPIO_PIN_13                     = 0x0D,
    GPIO_PIN_14                     = 0x0E,
    GPIO_PIN_15                     = 0x0F
} GPIO_PIN_t;  

typedef struct 
{
    register32_t CR;         // RCC clock control register,                                  Address offset: 0x00 
    register32_t CFGR;       // RCC clock configuration register,                            Address offset: 0x04 
    register32_t CIR;        // RCC clock interrupt register,                                Address offset: 0x08 
    register32_t APB2RSTR;   // RCC APB2 peripheral reset register,                          Address offset: 0x0C 
    register32_t APB1RSTR;   // RCC APB1 peripheral reset register,                          Address offset: 0x10 
    register32_t AHBENR;     // RCC AHB peripheral clock register,                           Address offset: 0x14 
    register32_t APB2ENR;    // RCC APB2 peripheral clock enable register,                   Address offset: 0x18 
    register32_t APB1ENR;    // RCC APB1 peripheral clock enable register,                   Address offset: 0x1C 
    register32_t BDCR;       // RCC Backup domain control register,                          Address offset: 0x20 
    register32_t CSR;        // RCC clock control & status register,                         Address offset: 0x24 
    register32_t AHBRSTR;    // RCC AHB peripheral reset register,                           Address offset: 0x28 
    register32_t CFGR2;      // RCC clock configuration register 2,                          Address offset: 0x2C 
    register32_t CFGR3;      // RCC clock configuration register 3,                          Address offset: 0x30 
} RCC_t;

typedef enum
{
    RCC_AHBENR_ADC34EN_gc           = (0x01<<29),        // ADC1/ ADC2 clock enable 
    RCC_AHBENR_ADC12EN_gc           = (0x01<<28),        // ADC1/ ADC2 clock enable 
    RCC_AHBENR_TSCEN_gc             = (0x01<<24),        // TS clock enable 
    RCC_AHBENR_IOPFEN_gc            = (0x01<<22),
    RCC_AHBENR_IOPEEN_gc            = (0x01<<21),
    RCC_AHBENR_IOPDEN_gc            = (0x01<<20),
    RCC_AHBENR_IOPCEN_gc            = (0x01<<19),
    RCC_AHBENR_IOPBEN_gc            = (0x01<<18),        // GPIOB clock enable 
    RCC_AHBENR_IOPAEN_gc            = (0x01<<17),        // GPIOA clock enable 
    RCC_AHBENR_CRCEN_gc             = (0x01<<6),        // CRC clock enable 
    RCC_AHBENR_FLITFEN_gc           = (0x01<<4),        // FLITF clock enable 
    RCC_AHBENR_SRAMEN_gc            = (0x01<<2),        // SRAM interface clock enable 
    RCC_AHBENR_DMA2EN_gc            = (0x01<<1)        // DMA2 clock enable 
} RCC_AHBENR_t;

typedef enum
{
    RCC_APB2ENR_TIM17EN_gc          = (0x01<<18),        // TIM17 clock enable 
    RCC_APB2ENR_TIM16EN_gc          = (0x01<<17),        // TIM16 clock enable 
    RCC_APB2ENR_TIM15EN_gc          = (0x01<<16),        // TIM16 clock enable 
    RCC_APB2ENR_USART1EN_gc         = (0x01<<14),        // USART1 clock enable 
    RCC_APB2ENR_TIM8EN_gc           = (0x01<<13),        // TIM8 clock enable 
    RCC_APB2ENR_SPI1EN_gc           = (0x01<<12),        // SPI1 clock enable 
    RCC_APB2ENR_TIM1EN_gc           = (0x01<<11),        // TIM1 clock enable 
    RCC_APB2ENR_SYSCFGEN_gc         = (0x01<<0)
} RCC_APB2ENR_t;

typedef enum
{
    RCC_APB1ENR_DAC1EN_gc           = (0x01<<29),        // DAC clock enable 
    RCC_APB1ENR_PWREN_gc            = (0x01<<28),        // PWR clock enable 
    RCC_APB1ENR_DAC2EN_gc           = (0x01<<26),        // DAC 2 clock enable 
    RCC_APB1ENR_CANEN_gc            = (0x01<<25),        // CAN clock enable 
    RCC_APB1ENR_USBEN_gc            = (0x01<<23),        // USB clock enable 
    RCC_APB1ENR_I2C2EN_gc           = (0x01<<22),        // I2C 2 clock enable 
    RCC_APB1ENR_I2C1EN_gc           = (0x01<<21),        // I2C 1 clock enable 
    RCC_APB1ENR_UART5EN_gc          = (0x01<<20),        // UART 5 clock enable 
    RCC_APB1ENR_UART4EN_gc          = (0x01<<19),        // UART 4 clock enable 
    RCC_APB1ENR_USART3EN_gc         = (0x01<<18),        // USART 3 clock enable 
    RCC_APB1ENR_USART2EN_gc         = (0x01<<17),        // USART 2 clock enable 
    RCC_APB1ENR_SPI3EN_gc           = (0x01<<15),        // SPI3 clock enable 
    RCC_APB1ENR_SPI2EN_gc           = (0x01<<14),        // SPI2 clock enable 
    RCC_APB1ENR_WWDGEN_gc           = (0x01<<11),        // Window Watchdog clock enable 
    RCC_APB1ENR_TIM7EN_gc           = (0x01<<5),        // Timer 7 clock enable 
    RCC_APB1ENR_TIM6EN_gc           = (0x01<<4),        // Timer 6 clock enable 
    RCC_APB1ENR_TIM4EN_gc           = (0x01<<2),        // Timer 4 clock enable 
    RCC_APB1ENR_TIM3EN_gc           = (0x01<<1),        // Timer 3 clock enable 
    RCC_APB1ENR_TIM2EN_gc           = (0x01<<0)        // Timer 2 clock enable 
} RCC_APB1ENR_t;

typedef enum
{
    RCC_CR_PLLRDY_LOCKED_gc         = (0x01<<25),
    RCC_CR_PLLRDY_UNLOCKED_gc       = (0x00<<25),
    RCC_CR_PLLON_ON_gc              = (0x01<<24),
    RCC_CR_PLLON_OFF_gc             = (0x00<<24),
    RCC_CR_CSSON_ON_gc              = (0x01<<19),
    RCC_CR_CSSON_OFF_gc             = (0x00<<19),
    RCC_CR_HSEBYP_BYPASS_gc         = (0x01<<18),
    RCC_CR_HSEBYP_NOBYPASS_gc       = (0x00<<18),
    RCC_CR_HSERDY_RDY_gc            = (0x01<<17),
    RCC_CR_HSERDY_NOTRDY_gc         = (0x00<<17),
    RCC_CR_HSEON_ON_gc              = (0x01<<16),
    RCC_CR_HSEON_OFF_gc             = (0x00<<16),
    RCC_CR_HSIRDY_RDY_gc            = (0x01<<1),
    RCC_CR_HSIRDY_NOTRDY_gc         = (0x00<<1),
    RCC_CR_HSION_ON_gc              = (0x01),
    RCC_CR_HSION_OFF_gc             = (0x00)
} RCC_CR_t;

// RCC_CR register bitfields
#define RCC_CR_PLLRDY_bm            (0x01<<25)
#define RCC_CR_PLLON_bm             (0x01<<24)
#define RCC_CR_CSSON_bm             (0x01<<19)
#define RCC_CR_HSEBYP_bm            (0x01<<18)
#define RCC_CR_HSERDY_bm            (0x01<<17)
#define RCC_CR_HSEON_bm             (0x01<<16)
#define RCC_CR_HSIRDY_bm            (0x01<<1)
#define RCC_CR_HSION_bm             (0x01<<0)
#define RCC_CR_HSICAL_bm            (0xFF<<8)
#define RCC_CR_HSITRIM_bm           (0x1F<<3)

typedef enum
{
    RCC_CFGR_PLLNODIV_NODIV_gc      = (0x01<<31),
    RCC_CFGR_PLLNODIV_DIVBY2_gc     = (0x00<<31),
    RCC_CFGR_MCOPRE_DIVBY1_gc       = (0x00<<29),
    RCC_CFGR_MCOPRE_DIVBY2_gc       = (0x01<<29),
    RCC_CFGR_MCOPRE_DIVBY4_gc       = (0x02<<29),
    RCC_CFGR_MCOPRE_DIVBY8_gc       = (0x03<<29),
    RCC_CFGR_MCOPRE_DIVBY16_gc      = (0x04<<29),
    RCC_CFGR_MCOPRE_DIVBY32_gc      = (0x05<<29),
    RCC_CFGR_MCOPRE_DIVBY64_gc      = (0x06<<29),
    RCC_CFGR_MCOPRE_DIVBY128_gc     = (0x07<<29),
    RCC_CFGR_MCO_DIS_gc             = (0x00<<24),
    RCC_CFGR_MCO_LSI_gc             = (0x02<<24),
    RCC_CFGR_MCO_LSE_gc             = (0x03<<24),
    RCC_CFGR_MCO_SYSCLK_gc          = (0x04<<24),
    RCC_CFGR_MCO_HSI_gc             = (0x05<<24),
    RCC_CFGR_MCO_HSE_gc             = (0x06<<24),
    RCC_CFGR_MCO_PLL_gc             = (0x07<<24),
    RCC_CFGR_I2SSRC_SYS_gc          = (0x00<<23),
    RCC_CFGR_I2SSRC_EXT_gc          = (0x01<<23),
    RCC_CFGR_USBPRE_DIV_gc          = (0x00<<22),
    RCC_CFGR_USBPRE_NODIV_gc        = (0x01<<22),
    RCC_CFGR_PLLMUL_2_gc            = (0x00<<18),
    RCC_CFGR_PLLMUL_3_gc            = (0x01<<18),
    RCC_CFGR_PLLMUL_4_gc            = (0x02<<18),
    RCC_CFGR_PLLMUL_5_gc            = (0x03<<18),
    RCC_CFGR_PLLMUL_6_gc            = (0x04<<18),
    RCC_CFGR_PLLMUL_7_gc            = (0x05<<18),
    RCC_CFGR_PLLMUL_8_gc            = (0x06<<18),
    RCC_CFGR_PLLMUL_9_gc            = (0x07<<18),
    RCC_CFGR_PLLMUL_10_gc           = (0x08<<18),
    RCC_CFGR_PLLMUL_11_gc           = (0x09<<18),
    RCC_CFGR_PLLMUL_12_gc           = (0x0A<<18),
    RCC_CFGR_PLLMUL_13_gc           = (0x0B<<18),
    RCC_CFGR_PLLMUL_14_gc           = (0x0C<<18),
    RCC_CFGR_PLLMUL_15_gc           = (0x0D<<18),
    RCC_CFGR_PLLMUL_16_gc           = (0x0E<<18),
    RCC_CFGR_PLLMUL_17_gc           = (0x0F<<18),
    RCC_CFGR_PLLXTPRE_NODIV_gc      = (0x00<<17),
    RCC_CFGR_PLLXTPRE_DIVBY2_gc     = (0x01<<17),
    RCC_CFGR_PLLSRC_HSIDIVBY2_gc    = (0x00<<16),
    RCC_CFGR_PLLSRC_HSEDIV_gc       = (0x01<<16),
    RCC_CFGR_PPRE2_NODIV_gc         = (0x00<<11),
    RCC_CFGR_PPRE2_DIVBY2_gc        = (0x04<<11),
    RCC_CFGR_PPRE2_DIVBY4_gc        = (0x05<<11),
    RCC_CFGR_PPRE2_DIVBY8_gc        = (0x06<<11),
    RCC_CFGR_PPRE2_DIVBY16_gc       = (0x07<<11),
    RCC_CFGR_PPRE1_NODIV_gc         = (0x00<<8),
    RCC_CFGR_PPRE1_DIVBY2_gc        = (0x04<<8),
    RCC_CFGR_PPRE1_DIVBY4_gc        = (0x05<<8),
    RCC_CFGR_PPRE1_DIVBY8_gc        = (0x06<<8),
    RCC_CFGR_PPRE1_DIVBY16_gc       = (0x07<<8),
    RCC_CFGR_HPRE_NODIV_gc          = (0x00<<4),
    RCC_CFGR_HPRE_DIVBY2_gc         = (0x08<<4),
    RCC_CFGR_HPRE_DIVBY4_gc         = (0x09<<4),
    RCC_CFGR_HPRE_DIVBY8_gc         = (0x0A<<4),
    RCC_CFGR_HPRE_DIVBY16_gc        = (0x0B<<4),
    RCC_CFGR_HPRE_DIVBY64_gc        = (0x0C<<4),
    RCC_CFGR_HPRE_DIVBY128_gc       = (0x0D<<4),
    RCC_CFGR_HPRE_DIVBY256_gc       = (0x0E<<4),
    RCC_CFGR_HPRE_DIVBY512_gc       = (0x0F<<4),
    RCC_CFGR_SWS_HSI_gc             = (0x00<<2),
    RCC_CFGR_SWS_HSE_gc             = (0x01<<2),
    RCC_CFGR_SWS_PLL_gc             = (0x02<<2),
    RCC_CFGR_SW_HSI_gc              = (0x00<<0),
    RCC_CFGR_SW_HSE_gc              = (0x01<<0),
    RCC_CFGR_SW_PLL_gc              = (0x02<<0)
} RCC_CFGR_t;

#define RCC_CFGR_PLLNODIV_bm        (0x01<<31)
#define RCC_CFGR_MCOPRE_bm          (0x07<<29)
#define RCC_CFGR_MCOF_bm            (0x01<<28)
#define RCC_CFGR_MCO_bm             (0x07<<24)
#define RCC_CFGR_I2SSRC_bm          (0x01<<23)
#define RCC_CFGR_USBPRE_bm          (0x01<<22)
#define RCC_CFGR_PLLMUL_bm          (0x0F<<18)
#define RCC_CFGR_PLLXTPRE_bm        (0x01<<17)
#define RCC_CFGR_PLLSRC_bm          (0x01<<16)
#define RCC_CFGR_PPRE2_bm           (0x07<<11)
#define RCC_CFGR_PPRE1_bm           (0x07<<8)
#define RCC_CFGR_HPRE_bm            (0x0F<<4)
#define RCC_CFGR_SWS_bm             (0x03<<2)
#define RCC_CFGR_SW_bm              (0x03<<0)

typedef enum
{
    RCC_CFGR3_UART5SW_PCLK_gc       = (0x00<<22),
    RCC_CFGR3_UART5SW_SYSCLK_gc     = (0x01<<22),
    RCC_CFGR3_UART5SW_LSE_gc        = (0x02<<22),
    RCC_CFGR3_UART5SW_HSI_gc        = (0x03<<22),
    RCC_CFGR3_UART4SW_PCLK_gc       = (0x00<<20),
    RCC_CFGR3_UART4SW_SYSCLK_gc     = (0x01<<20),
    RCC_CFGR3_UART4SW_LSE_gc        = (0x02<<20),
    RCC_CFGR3_UART4SW_HSI_gc        = (0x03<<20),
    RCC_CFGR3_USART3SW_PCLK_gc      = (0x00<<18),
    RCC_CFGR3_USART3SW_SYSCLK_gc    = (0x01<<18),
    RCC_CFGR3_USART3SW_LSE_gc       = (0x02<<18),
    RCC_CFGR3_USART3SW_HSI_gc       = (0x03<<18),
    RCC_CFGR3_USART2SW_PCLK_gc      = (0x00<<16),
    RCC_CFGR3_USART2SW_SYSCLK_gc    = (0x01<<16),
    RCC_CFGR3_USART2SW_LSE_gc       = (0x02<<16),
    RCC_CFGR3_USART2SW_HSI_gc       = (0x03<<16),
    RCC_CFGR3_TIM8SW_PCLK2_gc       = (0x00<<9),
    RCC_CFGR3_TIM8SW_PLL_gc         = (0x01<<9),
    RCC_CFGR3_TIM1SW_PCLK2_gc       = (0x00<<8),
    RCC_CFGR3_TIM1SW_PLL_gc         = (0x01<<8),
    RCC_CFGR3_I2C2SW_HSI_gc         = (0x00<<5),
    RCC_CFGR3_I2C2SW_SYSCLK_gc      = (0x01<<5),
    RCC_CFGR3_I2C1SW_HSI_gc         = (0x00<<4),
    RCC_CFGR3_I2C1SW_SYSCLK_gc      = (0x01<<4),
    RCC_CFGR3_USART1SW_PCLK_gc      = (0x00<<0),
    RCC_CFGR3_USART1SW_SYSCLK_gc    = (0x01<<0),
    RCC_CFGR3_USART1SW_LSE_gc       = (0x02<<0),
    RCC_CFGR3_USART1SW_HSI_gc       = (0x03<<0),
} RCC_CFGR3_t;

#define RCC_CFGR3_UART5SW_bm        (0x03<<22)
#define RCC_CFGR3_UART4SW_bm        (0x03<<20)
#define RCC_CFGR3_USART3SW_bm       (0x03<<18)
#define RCC_CFGR3_USART2SW_bm       (0x03<<16)
#define RCC_CFGR3_TIM8SW_bm         (0x01<<9)
#define RCC_CFGR3_TIM1SW_bm         (0x01<<8)
#define RCC_CFGR3_I2C2SW_bm         (0x01<<5)
#define RCC_CFGR3_I2C1SW_bm         (0x01<<4)
#define RCC_CFGR3_USART1SW_bm       (0x03<<0)

// TODO: redo comp options
typedef struct
{
   register32_t CSR; 
} COMP_t;

typedef enum
{
    COMP1_CSR_LOCK_RO_gc            = (0x01<<31),
    COMP1_CSR_LOCK_RW_gc            = (0x00<<31),
    COMP1_CSR_OUT_LOW_gc            = (0x00<<30),
    COMP1_CSR_OUT_HI_gc             = (0x01<<30),
    COMP1_CSR_BLANKING_NONE_gc      = (0x00<<18),
    COMP1_CSR_BLANKING_TIM1OC5_gc   = (0x01<<18),
    COMP1_CSR_BLANKING_TIM2OC3_gc   = (0x02<<18),
    COMP1_CSR_BLANKING_TIM3OC3_gc   = (0x03<<18),
    COMP1_CSR_HYST_NONE_gc          = (0x00<<16),
    COMP1_CSR_HYST_LOW_gc           = (0x01<<16),
    COMP1_CSR_HYST_MED_gc           = (0x02<<16),
    COMP1_CSR_HYST_HI_gc            = (0x03<<16),
    COMP1_CSR_POL_NOTINV_gc         = (0x00<<15),
    COMP1_CSR_POL_INV_gc            = (0x01<<15),
    COMP1_CSR_OUTSEL_NONE_gc        = (0x00<<10),
    COMP1_CSR_OUTSEL_TIM1BRK_gc     = (0x01<<10),
    COMP1_CSR_OUTSEL_TIM1BRK2_gc    = (0x02<<10),
    COMP1_CSR_OUTSEL_TIM8BRK_gc     = (0x03<<10),
    COMP1_CSR_OUTSEL_TIM8BRK2_gc    = (0x04<<10),
    COMP1_CSR_OUTSEL_TIM18BRK2_gc   = (0x05<<10),
    COMP1_CSR_OUTSEL_TIM1OCREFCLR_gc= (0x06<<10),
    COMP1_CSR_OUTSEL_TIM1IC1_gc     = (0x07<<10),
    COMP1_CSR_OUTSEL_TIM2IC4_gc     = (0x08<<10),
    COMP1_CSR_OUTSEL_TIM2OCREFCLR_gc= (0x09<<10),
    COMP1_CSR_OUTSEL_TIM3IC1_gc     = (0x0A<<10),
    COMP1_CSR_OUTSEL_TIM3OCREFCLR_gc= (0x0B<<10),
    COMP1_CSR_INMSEL_VCCDIV4_gc     = (0x00<<4),
    COMP1_CSR_INMSEL_VCCDIV2_gc     = (0x01<<4),
    COMP1_CSR_INMSEL_VCCDIV34_gc    = (0x02<<4),
    COMP1_CSR_INMSEL_VCCINT_gc      = (0x03<<4),
    COMP1_CSR_INMSEL_PA4_gc         = (0x04<<4),
    COMP1_CSR_INMSEL_PA5_gc         = (0x05<<4),
    COMP1_CSR_INMSEL_PA0_gc         = (0x06<<4),
    COMP1_CSR_MODE_HI_gc            = (0x00<<2),
    COMP1_CSR_MODE_MED_gc           = (0x01<<2),
    COMP1_CSR_MODE_LOW_gc           = (0x02<<2),
    COMP1_CSR_MODE_ULOW_gc          = (0x02<<2),
    COMP1_CSR_INP_DAC_OPEN_gc       = (0x00<<1),
    COMP1_CSR_INP_DAC_CLOSED_gc     = (0x01<<1),
    COMP1_CSR_EN_DIS_gc             = (0x00<<0),
    COMP1_CSR_EN_EN_gc              = (0x01<<0),
} COMP1_CSR_t;

#define COMP1_CSR_LOCK_bm           (0x01<<31)
#define COMP1_CSR_OUT_bm            (0x01<<30)
#define COMP1_CSR_BLANKING_bm       (0x03<<18)
#define COMP1_CSR_HYST_bm           (0x03<<16)
#define COMP1_CSR_POL_bm            (0x03<<15)
#define COMP1_CSR_OUTSEL_bm         (0x0F<<10)
#define COMP1_CSR_INMSEL_bm         (0x07<<4)
#define COMP1_CSR_MODE_bm           (0x03<<2)
#define COMP1_CSR__INP_DAC_bm       (0x01<<1)
#define COMP1_CSR_EN_bm             (0x01<<0)

typedef struct
{
    register32_t ACR;          // FLASH access control register,              Address offset: 0x00 
    register32_t KEYR;         // FLASH key register,                         Address offset: 0x04 
    register32_t OPTKEYR;      // FLASH option key register,                  Address offset: 0x08 
    register32_t SR;           // FLASH status register,                      Address offset: 0x0C 
    register32_t CR;           // FLASH control register,                     Address offset: 0x10 
    register32_t AR;           // FLASH address register,                     Address offset: 0x14 
    register32_t reserved_0x18;     // Reserved, 0x18                                                   
    register32_t OBR;          // FLASH Option byte register,                 Address offset: 0x1C 
    register32_t WRPR;         // FLASH Write register,                       Address offset: 0x20 
} FLASH_t;

typedef enum
{
    FLASH_ACR_PRFTBS_EN_gc          = (0x01<<5),
    FLASH_ACR_PRFTBS_DIS_gc         = (0x00<<5),
    FLASH_ACR_PRFTBE_EN_gc          = (0x01<<4),
    FLASH_ACR_PRFTBE_DIS_gc         = (0x00<<4),
    FLASH_ACR_HLFCYA_EN_gc          = (0x01<<3),
    FLASH_ACR_HLFCYA_DIS_gc         = (0x00<<3),
    FLASH_ACR_LATENCY_0_gc          = (0x00),
    FLASH_ACR_LATENCY_1_gc          = (0x01),
    FLASH_ACR_LATENCY_2_gc          = (0x02)
} FLASH_ACR_t;

// FLASH_ACR bitfields
#define FLASH_ACR_PRFTBS_bm         (0x01<<5)
#define FLASH_ACR_PRFTBE_bm         (0x01<<4)
#define FLASH_ACR_HLFCYA_bm         (0x01<<3)
#define FLASH_ACR_LATENCY_bm        (0x02)

// Cortex-M4 core related registers
typedef struct 
{
    register32_t CPUID;                   // Offset: 0x000 (R/ )  CPUID Base Register                                   
    register32_t ICSR;                    // Offset: 0x004 (R/W)  Interrupt Control and State Register                  
    register32_t VTOR;                    // Offset: 0x008 (R/W)  Vector Table Offset Register                          
    register32_t AIRCR;                   // Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      
    register32_t SCR;                     // Offset: 0x010 (R/W)  System Control Register                               
    register32_t CCR;                     // Offset: 0x014 (R/W)  Configuration Control Register                        
    register8_t  SHP[12];                 // Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) 
    register32_t SHCSR;                   // Offset: 0x024 (R/W)  System Handler Control and State Register             
    register32_t CFSR;                    // Offset: 0x028 (R/W)  Configurable Fault Status Register                    
    register32_t HFSR;                    // Offset: 0x02C (R/W)  HardFault Status Register                             
    register32_t DFSR;                    // Offset: 0x030 (R/W)  Debug Fault Status Register                           
    register32_t MMFAR;                   // Offset: 0x034 (R/W)  MemManage Fault Address Register                      
    register32_t BFAR;                    // Offset: 0x038 (R/W)  BusFault Address Register                             
    register32_t AFSR;                    // Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       
    register32_t PFR[2];                  // Offset: 0x040 (R/ )  Processor Feature Register                            
    register32_t DFR;                     // Offset: 0x048 (R/ )  Debug Feature Register                                
    register32_t ADR;                     // Offset: 0x04C (R/ )  Auxiliary Feature Register                            
    register32_t MMFR[4];                 // Offset: 0x050 (R/ )  Memory Model Feature Register                         
    register32_t ISAR[5];                 // Offset: 0x060 (R/ )  Instruction Set Attributes Register                   
    register32_t RESERVED0[5];
    register32_t CPACR;                   // Offset: 0x088 (R/W)  Coprocessor Access Control Register                   
} SCB_t;

typedef struct
{
    register32_t ISER[8];                 /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
    register32_t RESERVED0[24];
    register32_t ICER[8];                 /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
    register32_t RSERVED1[24];
    register32_t ISPR[8];                 /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
    register32_t RESERVED2[24];
    register32_t ICPR[8];                 /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
    register32_t RESERVED3[24];
    register32_t IABR[8];                 /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
    register32_t RESERVED4[56];
    register8_t  IP[240];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
    register32_t RESERVED5[644];
    register32_t STIR;                    /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
} NVIC_t;

// SysTick registers
typedef struct
{
    register32_t CTRL;
    register32_t LOAD;
    register32_t VAL;
    register32_t CALIB;
} STK_t;

typedef enum
{
    STK_CTRL_COUNTFLAG_UF_gc        = (0x01<<16),
    STK_CTRL_COUNTFLAG_NOUF_gc      = (0x00<<16),
    STK_CTRL_CLKSOURCE_AHB_gc       = (0x01<<2),
    STK_CTRL_CLKSOURCE_AHBDIV8_gc   = (0x00<<2),
    STK_CTRL_TICKINT_EN_gc          = (0x01<<1),
    STK_CTRL_TICKINT_DIS_gc         = (0x00<<1),
    STK_CTRL_ENABLE_EN_gc           = (0x01<<0),
    STK_CTRL_ENABLE_DIS_gc          = (0x00<<0),
} STK_CTRL_t;

typedef struct
{
  register32_t IMR1;        /*!< EXTI Interrupt mask register,                Address offset: 0x00 */
  register32_t EMR1;        /*!< EXTI Event mask register,                    Address offset: 0x04 */
  register32_t RTSR1;       /*!< EXTI Rising trigger selection register,      Address offset: 0x08 */
  register32_t FTSR1;       /*!< EXTI Falling trigger selection register,     Address offset: 0x0C */
  register32_t SWIER1;      /*!< EXTI Software interrupt event register,      Address offset: 0x10 */
  register32_t PR1;         /*!< EXTI Pending register,                       Address offset: 0x14 */
  register32_t reserved_0x18;  /*!< Reserved, 0x18                                                    */
  register32_t reserved_0x1c;  /*!< Reserved, 0x1C                                                    */
  register32_t IMR2;       /*!< EXTI Interrupt mask register,                Address offset: 0x20 */
  register32_t EMR2;       /*!< EXTI Event mask register,                    Address offset: 0x24 */
  register32_t RTSR2;      /*!< EXTI Rising trigger selection register,      Address offset: 0x28 */
  register32_t FTSR2;      /*!< EXTI Falling trigger selection register,     Address offset: 0x2C */
  register32_t SWIER2;     /*!< EXTI Software interrupt event register,      Address offset: 0x30 */
  register32_t PR2;        /*!< EXTI Pending register,                       Address offset: 0x34 */
} EXTI_t;

#define STK_CTRL_COUNTFLAG_bm       (0x01<<16)
#define STK_CTRL_CLKSOURCE_bm       (0x01<<2)
#define STK_CTRL_TICKINT_bm         (0x01<<1)
#define STK_CTRL_ENABLE_bm          (0x01<<0)

// Core related addresses
#define SCS_BASE                    (0xE000E000UL)                            // System Control Space Base Address  
#define SCB_BASE                    (SCS_BASE +  0x0D00UL)                    // System Control Block Base Address  
#define NVIC        ((NVIC_t *)     0xE000E100)   /*!< NVIC configuration struct          */
#define STK         ((STK_t *)      0xE000E010)
#define EXTI        ((EXTI_t *)     (APB2PERIPH_BASE + 0x400))

// Base memory addresses
#define FLASH_BASE                  (0x08000000) // FLASH base address in the alias region 
#define SRAM_BASE                   (0x20000000) // SRAM base address in the alias region 
#define PERIPH_BASE                 0x40000000 // Peripheral base address in the alias region 
#define APB1PERIPH_BASE             PERIPH_BASE
#define AHB1PERIPH_BASE             (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE             (PERIPH_BASE + 0x08000000)
#define APB2PERIPH_BASE             (PERIPH_BASE + 0x00010000)

// APB1 peripherals
#define TIM3        (*(TIM_t *)     (APB1PERIPH_BASE + 0x00000400))

// APB2 peripherals
#define TIM1        (*(AC_TIM_t *)  (APB2PERIPH_BASE + 0x00002C00))
#define TIM8        (*(AC_TIM_t *)  (APB2PERIPH_BASE + 0x00003400))
#define COMP1       (*(COMP_t *)    (APB2PERIPH_BASE + 0x0000001C))

// AHB1 peripherals
#define RCC         ((RCC_t *)      (AHB1PERIPH_BASE + 0x00001000))
#define FLASH       ((FLASH_t *)    (AHB1PERIPH_BASE + 0x00002000))

// AHB2 peripherals
#define GPIOA       (*(GPIO_t *)    (AHB2PERIPH_BASE + 0x0000))
#define GPIOB       (*(GPIO_t *)    (AHB2PERIPH_BASE + 0x0400))
#define GPIOC       (*(GPIO_t *)    (AHB2PERIPH_BASE + 0x0800))
#define GPIOD       (*(GPIO_t *)    (AHB2PERIPH_BASE + 0x0C00))
#define GPIOE       (*(GPIO_t *)    (AHB2PERIPH_BASE + 0x1000))
#define GPIOF       (*(GPIO_t *)    (AHB2PERIPH_BASE + 0x1400))

// Cortex-M4 core registers
#define SCB         ((SCB_t *)      SCB_BASE)   // SCB configuration struct           

// Random defines
#define VECT_TAB_OFFSET             (0x00)
#define HSI_STARTUP_TIMEOUT         (0x5000) // Time out for HSI start up 

#endif // Include guard
