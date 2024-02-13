/*
 * 		Stm32_F103X6.h
 * 		Created on: Dec 15, 2023
 *      Author: Abdullah Karkour
 */

#ifndef INC_STM32_F103X6_H_
#define INC_STM32_F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include "Platform_Types.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define Flash_memory_BASE										0x08000000
#define System_memory_BASE										0x1FFFF000
#define SRAM_memory_BASE										0x20000000

#define Perpherals_memory_BASE									0x40000000
#define Cortex_M3_internal_Perpherals_BASE						0xE0000000

// NVIC registers
#define NVIC_BASE						0xE000E100
#define NVIC_ISER0						*(volatile uint32_t *)(NVIC_BASE + 0x000)
#define NVIC_ISER1						*(volatile uint32_t *)(NVIC_BASE + 0x004)
#define NVIC_ISER2						*(volatile uint32_t *)(NVIC_BASE + 0x008)
#define NVIC_ICER0						*(volatile uint32_t *)(NVIC_BASE + 0x080)
#define NVIC_ICER1						*(volatile uint32_t *)(NVIC_BASE + 0x084)
#define NVIC_ICER2						*(volatile uint32_t *)(NVIC_BASE + 0x088)


//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE												0x40021000

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

/* GPIO in LQFP48 Package
 * A,B fully included
 * C,D Partial  included
 * E not  included
 * */
#define GPIOA_BASE												0X40010800UL
#define GPIOB_BASE												0X40010C00UL
#define GPIOC_BASE												0X40011000UL
#define GPIOD_BASE												0X40011400UL
#define GPIOE_BASE												0X40011800UL

// AFIO
#define AFIO_BASE												0X40010000UL

// EXTI
#define EXTI_BASE												0X40010400UL


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

//=====================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*


//Peripheral register: GPIO
typedef struct
{
	volatile uint32 CRL  ;
	volatile uint32 CRH  ;
	volatile uint32 IDR  ;
	volatile uint32 ODR  ;
	volatile uint32 BSRR ;
	volatile uint32 BRR  ;
	volatile uint32 LCKR ;

}GPIO_TypeDef;

//Peripheral register: AFIO
typedef struct
{
	volatile uint32 EVCR 	 ;
	volatile uint32 MAPR 	 ;
	volatile uint32 EXTICR[4];
	volatile uint32 RESERVED ;
	volatile uint32 MAPR2 	 ;

}AFIO_TypeDef;

//Peripheral register: RCC
typedef struct
{
	volatile uint32 CR 		  ;
	volatile uint32 CFGR 	  ;
	volatile uint32 CIR  	  ;
	volatile uint32 APB2RSTR  ;
	volatile uint32 APB1RSTR  ;
	volatile uint32 AHBENR    ;
	volatile uint32 APB2ENR   ;
	volatile uint32 APB1ENR   ;
	volatile uint32 BDCR 	  ;
	volatile uint32 CSR 	  ;
	volatile uint32 AHBSTR    ;
	volatile uint32 CFGR2     ;

}RCC_TypeDef;

//Peripheral register: EXTI
typedef struct
{
	volatile uint32 IMR    ;
	volatile uint32 EMR    ;
	volatile uint32 RTSR   ;
	volatile uint32 FTSR   ;
	volatile uint32 SWIER  ;
	volatile uint32 PR     ;

}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

// GPIO
#define GPIOA       (((GPIO_TypeDef *)GPIOA_BASE))
#define GPIOB       (((GPIO_TypeDef *)GPIOB_BASE))
#define GPIOC       (((GPIO_TypeDef *)GPIOC_BASE))
#define GPIOD       (((GPIO_TypeDef *)GPIOD_BASE))
#define GPIOE       (((GPIO_TypeDef *)GPIOE_BASE))

// RCC
#define RCC       (((RCC_TypeDef *)RCC_BASE))

//AFIO
#define AFIO       (((AFIO_TypeDef *)AFIO_BASE))

// EXTI
#define EXTI       (((EXTI_TypeDef *)EXTI_BASE))


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

// GPIO ENABLE
#define RCC_GPIOA_CLK_EN()  (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()  (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()  (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()  (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()  (RCC->APB2ENR |= 1<<6)

// AFIO ENABLE
#define RCC_AFIO_CLK_EN()  (RCC->APB2ENR |= 1<<0)

//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC Enable And Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

// NVIC Enable
#define NVIC_IRQ6_EXTI0_ENABLE					(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_ENABLE					(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_ENABLE					(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_ENABLE					(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_ENABLE					(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_ENABLE				(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_ENABLE				(NVIC_ISER1 |= (1<<8)) //(32-63) ISER[1] 40-32 = 8

// NVIC Disable
#define NVIC_IRQ6_EXTI0_DISABLE					(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_DISABLE					(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_DISABLE					(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_DISABLE					(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_DISABLE				(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_DISABLE				(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_DISABLE			(NVIC_ICER1 |= (1<<8)) //(32-63)ICER[1] 40-32 = 8


//-*-*-*-*-*-*-*-*-*-*-*-
//IVT
//-*-*-*-*-*-*-*-*-*-*-*
// EXTI
#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40



//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif /* INC_STM32_F103X6_H_ */
