/*
*	 LCD_Config.h
*  	Created on: Dec 10, 2023
*   Author: Adbullah Karkour
*/


#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

// includes
#include "Stm32_F103X6.h"
#include "Stm32_F103C6_gpio_driver.h"

/*  RS configuration */
#define LCD_RS_PORT           GPIOB
#define LCD_RS_PIN            GPIO_PIN_0

/*  RW configuration */
#define LCD_RW_PORT           GPIOB
#define LCD_RW_PIN            GPIO_PIN_1

/* EN configuration */
#define LCD_EN_PORT           GPIOB
#define LCD_EN_PIN            GPIO_PIN_10


/* Options FOR LCD Mode:
1- LCD_8_BIT_MODE
2- LCD_4_BIT_MODE */

#define LCD_MODE              LCD_4_BIT_MODE


#define LCD_DATA_PORT         GPIOA


/* 4 Bit Mode Pins Configuration */

#if LCD_MODE == LCD_8_BIT_MODE

#define LCD_D0_PIN            GPIO_PIN_0
#define LCD_D1_PIN            GPIO_PIN_1
#define LCD_D2_PIN            GPIO_PIN_2
#define LCD_D3_PIN            GPIO_PIN_3

#endif

#define LCD_D4_PIN            GPIO_PIN_4
#define LCD_D5_PIN            GPIO_PIN_5
#define LCD_D6_PIN            GPIO_PIN_6
#define LCD_D7_PIN            GPIO_PIN_7

#endif /* LCD_LCD_CONFIG_H_ */
