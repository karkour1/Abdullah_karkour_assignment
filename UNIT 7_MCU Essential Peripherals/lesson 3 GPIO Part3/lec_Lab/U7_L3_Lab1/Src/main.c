/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Stm32_F103C6_gpio_driver.h"
#include "Stm32_F103X6.h"

GPIO_PinConfig_t pinconfg  ;

void clock_init()
{
	// Enable IO port A clock
	RCC_GPIOA_CLK_EN();
	// Enable IO Port B clock
	RCC_GPIOB_CLK_EN() ;
}
void GPIO_init()
{
	// set Register initial value 0
	GPIOA->CRL =0;
	GPIOA->CRH =0;
	GPIOA->ODR =0;
	GPIOB->CRL =0;
	GPIOB->CRH =0;
	GPIOB->ODR =0;

	// PA1 input in floating mode
	pinconfg.GPIO_PinNumber = GPIO_PIN_1;
	pinconfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pinconfg);
	// PB1 output in push-pull mode
	pinconfg.GPIO_PinNumber = GPIO_PIN_1;
	pinconfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pinconfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinconfg);
	// PA13 input in floating mode
	pinconfg.GPIO_PinNumber = GPIO_PIN_13;
	pinconfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pinconfg);
	// PB13 output in push-pull mode
	pinconfg.GPIO_PinNumber = GPIO_PIN_13;
	pinconfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pinconfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinconfg);
}
int main(void)
{
	clock_init();
	GPIO_init();

	/* Loop forever */
	while(1)
	{
		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0); // for single press
		}

		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		int i ;
		for(i=0 ; i<255 ; i++);
	}
}
