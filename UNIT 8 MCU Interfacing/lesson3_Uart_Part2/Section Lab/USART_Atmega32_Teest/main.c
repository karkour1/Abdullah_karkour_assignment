/*
 *  main.c
 *  Created on: Feb 15, 2024
 *  Author: ABDUALLAH KARKOUR
 */

#include <util/delay.h>

#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Atmega32_USART_interface.h"
#include "DIO_interface.h"

USART_Config_t usart_cfg ;
uint16_t a , x ;
uint8_t d[50];

int main(void)
{
	DIO_SetPinDirection(DIO_PORTD , DIO_PIN0 , DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTD , DIO_PIN1 , DIO_PIN_OUTPUT);

	usart_cfg.BaudRate = USART_BaudRate_9600;
	usart_cfg.Fosc = 8000000;
	usart_cfg.Mode = USART_Normal_Mode;
	usart_cfg.Parity_status = USART_Parity_Disable;
	usart_cfg.Stop_bits = USART_StopBit_1bit;
	usart_cfg.data_bits = USART_DataBit_8bits;
	MCAL_USART_Init(&usart_cfg);
	LCD_init();
	GI_Enable;


//    a = 'A' ;
//    MCAL_USART_Send(&a , disable);
//    a = 'I';
//    MCAL_USART_Send(&a , disable);
//    a = 'K';
//    MCAL_USART_Send(&a , disable);
    MCAL_USART_SendString("Abdullah");
    MCAL_USART_SendString("karkour");
	LCD_SET_Cursor(2,0);
	uint32_t x = 0 ;
	while(1)
	{
		MCAL_USART_ResiveString(d);
		LCD_SET_Cursor(2,0);
		LCD_Send_string(d);




		  if(x==9)	x = 0;
		  x++;
		  LCD_SET_Cursor(1,0);
		  LCD_Display_Number(x);
		 _delay_ms(2000);


	}
}
