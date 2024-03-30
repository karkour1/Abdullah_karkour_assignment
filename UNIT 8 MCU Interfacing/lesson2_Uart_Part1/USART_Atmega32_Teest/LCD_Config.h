/*
*	 LCD_Config.h
*  	Created on: Dec 10, 2023
*   Author: Adbullah Karkour
*/


#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

/*  RS configuration */
#define LCD_RS_PORT           PORTB
#define LCD_RS_DIR_PORT       DDRB
#define LCD_RS_PIN            1

/*  RW configuration */
#define LCD_RW_PORT           PORTB
#define LCD_RW_DIR_PORT       DDRB
#define LCD_RW_PIN            2

/* EN configuration */
#define LCD_EN_PORT           PORTB
#define LCD_EN_DIR_PORT       DDRB
#define LCD_EN_PIN            3


/* Options FOR LCD Mode:
1- LCD_8_BIT_MODE
2- LCD_4_BIT_MODE */

#define LCD_MODE              LCD_4_BIT_MODE


#define LCD_DATA_OUT_PORT         PORTA
#define LCD_DATA_DIR_PORT     DDRA
#define LCD_DATA_INP_PORT     DDRA


/* 4 Bit Mode Pins Configuration */

#if LCD_MODE == LCD_8_BIT_MODE

#define LCD_D0_PIN            0
#define LCD_D1_PIN            1
#define LCD_D2_PIN            2
#define LCD_D3_PIN            3

#endif

#define LCD_D4_PIN            4
#define LCD_D5_PIN            5
#define LCD_D6_PIN            6
#define LCD_D7_PIN            7

#endif /* LCD_LCD_CONFIG_H_ */
