/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdullah karkour
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#include "Platform_Types.h"


                 /*********                   Macros of Register address                     *******/
#define RCC_BASE            0x40021000                                //reset and clock control base address
#define GPIOA_BASE          0x40010800                                // general purpose input/output A base address
#define RCC_APB2ENR         *(volatile uint32 *)(RCC_BASE   + 0x18 )
#define GPIOA_CRH           *(volatile uint32 *)(GPIOA_BASE + 0x04 ) // CRH Register to control mode of pin
#define GPIOA_ODR           *(volatile uint32 *)(GPIOA_BASE + 0x0C) // GPIOA_ODR Register to control output of pin

 // union to control register GPIOA_ODR
typedef union {

	vuint32_t   all_fields;
	struct {
		vuint32_t reversed:13;
		vuint32_t p_13:1 ;
	} pin;
}R_ODR_t;

// pointer to register GPIOA_ODR
volatile R_ODR_t* R_ODR  = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

uint8 G_variables[3]={1,2,3};
uint8 const const_variables[3] = {1,2,3};
int main(void)
{
	RCC_APB2ENR |= (1<<2);     // Set pin 2 in RCC_APB2ENR register
	GPIOA_CRH   &= 0xFF0FFFFF; // Clear bits 20->24
	GPIOA_CRH   |= 0x00200000; // Set 2 in bits 20->24

	int i ;
	while(1)
	{
		R_ODR->pin.p_13 = 1;             // LED OFF
		for( i =0 ; i<5000 ; i++);    // delay
		R_ODR->pin.p_13 = 0;             // LED ON
		for(i =0 ; i<5000 ; i++);    //delay
	}

	return 0 ;
}

