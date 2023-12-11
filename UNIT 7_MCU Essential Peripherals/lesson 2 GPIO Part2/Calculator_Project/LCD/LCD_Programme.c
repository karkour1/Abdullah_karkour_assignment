/*
*	LCD_Programme.c
*  	Created on: Dec 10, 2023
*   Author: Adbullah Karkour
*/


#include "LCD_Config.h"
#include "LCD_interface.h"
#include "ATMEGA32_REG.h"
#include "Platform_Types.h"
#include <util/delay.h>



/* LCD APIS */
void LCD_EN_Pluse(void)
{
	LCD_EN_PORT &= ~(1<<LCD_EN_PIN);
	_delay_ms(50);
	LCD_EN_PORT |= (1<<LCD_EN_PIN);
}
void LCD_init(void)
{
	_delay_ms(20);

	// Set LCD Data Port output
	LCD_DATA_DIR_PORT = 0xff ;
	// SET control pins output
	LCD_RS_DIR_PORT |=(1<<LCD_RS_PIN);
	LCD_RW_DIR_PORT |=(1<<LCD_RW_PIN);
	LCD_EN_DIR_PORT |=(1<<LCD_EN_PIN);

	//put the LCD in command mode (RS off)
	LCD_RS_PORT &= ~(1<<LCD_RS_PIN);

	// put the LCD in write mode (RW off)
	LCD_RW_PORT &= ~(1<<LCD_RW_PIN);

	// EN off
	LCD_EN_PORT &= ~(1<<LCD_EN_PIN);

	_delay_ms(15);
	LCD_Clear_Screen();

	/* 8_BIT_MODE_INIT*/
#if LCD_MODE == LCD_8_BIT_MODE
	LCD_Send_Command(LCD_FUNCTION_8BIT_2LINE);

	/*4_BIT_MODE_INIT*/
#elif LCD_MODE == LCD_4_BIT_MODE

	LCD_Send_Command(0x02);
	LCD_Send_Command(LCD_FUNCTION_4BIT_2LINE);

#endif


	LCD_Send_Command(LCD_ENTRY_MODE);
	LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Send_Command(LCD_DISP_ON_CURSOR_BLINK);

}
void LCD_Is_Busy(void)
{
	// set pin connected to D7 to receive data (Data direction as input).
	LCD_DATA_DIR_PORT &= ~(1<<LCD_D7_PIN);

	// put the LCD in read mode (RW on)
	LCD_RW_PORT |= (1<<LCD_RW_PIN);

	//put the LCD in command mode (RS off)
	LCD_RS_PORT &= ~(1<<LCD_RS_PIN);

	while (((LCD_DATA_INP_PORT>>LCD_D7_PIN)&1));

	// set  D7 to receive data (Data direction as output).
	LCD_DATA_DIR_PORT |= (1<<LCD_D7_PIN);

	// put the LCD in write mode (RW off)
	LCD_RW_PORT &= ~(1<<LCD_RW_PIN);

}
void LCD_Send_Command(uint8 command)
{
	// Check if LCD is busy
	LCD_Is_Busy();

	//put the LCD in command mode (RS off)
	LCD_RS_PORT &= ~(1<<LCD_RS_PIN);

	// put the LCD in write mode (RW off)
	LCD_RW_PORT &= ~(1<<LCD_RW_PIN);

#if LCD_MODE == LCD_8_BIT_MODE

	LCD_DATA_OUT_PORT = command ;
	LCD_EN_Pluse();

#elif LCD_MODE == LCD_4_BIT_MODE

	// Write The Most 4 bits Of command on Data Pins
	LCD_DATA_OUT_PORT = (LCD_DATA_OUT_PORT & 0x0f)|(command & 0xf0);
	LCD_EN_Pluse();

	// Write The Least 4 bits Of command on Data Pins
	LCD_DATA_OUT_PORT = (LCD_DATA_OUT_PORT & 0x0f)|(command <<4);
	LCD_EN_Pluse();

#endif


}
void LCD_Send_Character(uint8 character)
{
	//put the LCD in Data mode (RS on)
	LCD_RS_PORT |= (1<<LCD_RS_PIN);

	// put the LCD in write mode (RW off)
	LCD_RW_PORT &= ~(1<<LCD_RW_PIN);

	// to set cursor and count the characters
#if LCD_MODE == LCD_8_BIT_MODE
	LCD_DATA_OUT_PORT = character ;
	LCD_EN_Pluse();

#elif LCD_MODE == LCD_4_BIT_MODE

	// Write The Most 4 bits Of data on Data Pins
	LCD_DATA_OUT_PORT = (LCD_DATA_OUT_PORT & 0x0f)|(character & 0xf0);
	LCD_EN_Pluse();

	// Write The Least 4 bits Of data on Data Pins
	LCD_DATA_OUT_PORT = (LCD_DATA_OUT_PORT & 0x0f)|(character <<4);
	LCD_EN_Pluse();

#endif

}
void LCD_Send_string(uint8* string)
{
	uint8 counter = 0;
	while( *string >0)
	{
		counter++;
		LCD_Send_Character(*string);
		string++;

		if(counter == 16)
		{
			LCD_SET_Cursor(2, 0);
		}
		else if(counter == 32)
		{
			LCD_Clear_Screen();
			LCD_SET_Cursor(1, 0);
			counter =0 ;
		}
	}
}
void LCD_Clear_Screen(void)
{
	LCD_Send_Command(LCD_CLEAR_SCREEN);
}
void LCD_SET_Cursor(uint8 line , uint8 position )
{
	if (line == 1)
	{
		if(position<16)
		LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW + position);
	}
	else if (line == 2)
	{
		if(position<16)
		LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW + position);
	}
}
void LCD_Display_Number(uint32 number)
{
	uint8 str[7];
	sprintf(str,"%d",number);
	LCD_Send_string(str);
}
void LCD_Display_Real_Number(double number)
{
	uint8 str[16];

	uint8 sign = (number<0)? "-":"";
	float Temp = (number<0)? -number:number;

	uint32 temp1 = Temp;
	uint32 temp2 = (Temp - temp1) *10000 ;
	sprintf(str,"%s%d.%04d",sign , temp1, temp2);
	LCD_Send_string(str);
}
