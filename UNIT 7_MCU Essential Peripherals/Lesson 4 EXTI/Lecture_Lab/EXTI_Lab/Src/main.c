/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdullah Karkour
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "Stm32_F103X6.h"
#include "Stm32_F103C6_EXTI_driver.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "LCD_interface.h"
#include "LCD_Config.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

uint8_t IRQ_Flag ;

void Wait(int x)
{
	unsigned int i , j ;
	for(i=0 ; i<x ;i++)
	{
		for(j = 0 ; j<255 ; j++);
	}
}
void clock_init()
{
	// Enable IO port A clock
	RCC_GPIOA_CLK_EN();
	// Enable IO Port B clock
	RCC_GPIOB_CLK_EN();
	// AFIO Clock
	RCC_AFIO_CLK_EN();
}

void EXTI9_CallBack(void)
{
	IRQ_Flag = 1;
	LCD_Send_string("IRQ EXTI9 is Happened _|-");
	Wait(1000);
	LCD_Clear_Screen();

}

int main(void)
{
	clock_init();
	LCD_init();
	LCD_Clear_Screen();

	// Configuration of EXTI9PB9
	EXTI_PinConfig_t EXTI_Confg ;
	EXTI_Confg.EXTI_Pin = EXTI9PB9;
	EXTI_Confg.Trigger_case = EXTI_TRIGGER_RAISING;
	EXTI_Confg.P_IRQ_CallBack= EXTI9_CallBack;
	EXTI_Confg.IRQ_EN = EXTI_IRQ_ENABLE ;

	MCAL_EXTI_GPIO_Update(&EXTI_Confg);

	IRQ_Flag = 1;
    /* Loop forever */
	while(1)
	{
		if(IRQ_Flag)
		{
			LCD_Clear_Screen();
			IRQ_Flag =0 ;
		}

	}
}
