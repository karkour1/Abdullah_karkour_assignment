/*
*	LCD_Programme.c
*  	Created on: Dec 10, 2023
*   Author: Adbullah Karkour
*/


#include "LCD_Config.h"
#include "LCD_interface.h"
#include "Platform_Types.h"

// global variables
GPIO_PinConfig_t pincofg  ;

// LCD global functions
void wait_ms(uint32 time )
{
	uint32 i,j;
	for(i=0 ; i<time ; i++)
		for(j=0 ; j<255 ; j++);
}
void LCD_EN_Pluse(void)
{
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
	wait_ms(50);
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_SET);
}

/* LCD APIS */
void LCD_init(void)
{
	wait_ms(20);

	// Set LCD Data Port output
	pincofg.GPIO_PinNumber = LCD_D0_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_D1_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_D2_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_D3_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_D4_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_D5_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_D6_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_D7_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	// SET control pins output (Rs , RW , EN)
	pincofg.GPIO_PinNumber = LCD_RS_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_RS_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_RW_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_RW_PORT, &pincofg);

	pincofg.GPIO_PinNumber = LCD_EN_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_EN_PORT, &pincofg);

	//put the LCD in command mode (RS =0 off)
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);

	// put the LCD in write mode (RW =0 off)
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

	// EN off
	MCAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);

	wait_ms(15);
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
	pincofg.GPIO_PinNumber = LCD_D7_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	// put the LCD in read mode (RW =1 on)
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_SET);

	//put the LCD in command mode (RS =0 off)
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);

	while (((MCAL_GPIO_ReadPin(LCD_DATA_PORT, LCD_D7_PIN))&1));

	// set  D7 to receive data (Data direction as output).
	pincofg.GPIO_PinNumber = LCD_D7_PIN;
	pincofg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pincofg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pincofg);

	// put the LCD in write mode (RW =0 off)
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

}
void LCD_Send_Command(uint8 command)
{
	// Check if LCD is busy
	LCD_Is_Busy();

	//put the LCD in command mode (RS =0 off)
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);

	// put the LCD in write mode (RW off)
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

#if LCD_MODE == LCD_8_BIT_MODE
//  Write on the 8bit connected to LCD data 8 pins
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D0_PIN, ((command >>LCD_D0_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D1_PIN, ((command >>LCD_D1_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D2_PIN, ((command >>LCD_D2_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D3_PIN, ((command >>LCD_D3_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, ((command >>LCD_D4_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, ((command >>LCD_D5_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, ((command >>LCD_D6_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, ((command >>LCD_D7_PIN) & 1));
	LCD_EN_Pluse();

#elif LCD_MODE == LCD_4_BIT_MODE

	// Write The Most 4 bits Of command on Data Pins
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, ((command >>LCD_D4_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, ((command >>LCD_D5_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, ((command >>LCD_D6_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, ((command >>LCD_D7_PIN) & 1));
	LCD_EN_Pluse();

	// Write The Least 4 bits Of command on Data Pins
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, (((command<<4) >>LCD_D4_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, (((command<<4) >>LCD_D5_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, (((command<<4) >>LCD_D6_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, (((command<<4) >>LCD_D7_PIN) & 1));
	LCD_EN_Pluse();

#endif


}
void LCD_Send_Character(uint8 character)
{
	//put the LCD in Data mode (RS=1 on)
	MCAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_SET);

	// put the LCD in write mode (RW =0 off)
	MCAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

	// to set cursor and count the characters
#if LCD_MODE == LCD_8_BIT_MODE

	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D0_PIN, ((character >>LCD_D0_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D1_PIN, ((character >>LCD_D1_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D2_PIN, ((character >>LCD_D2_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D3_PIN, ((character >>LCD_D3_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, ((character >>LCD_D4_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, ((character >>LCD_D5_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, ((character >>LCD_D6_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, ((character >>LCD_D7_PIN) & 1));
	LCD_EN_Pluse();

#elif LCD_MODE == LCD_4_BIT_MODE

	// Write The Most 4 bits Of data on Data Pins
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, ((character >>LCD_D4_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, ((character >>LCD_D5_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, ((character >>LCD_D6_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, ((character >>LCD_D7_PIN) & 1));
	LCD_EN_Pluse();

	// Write The Least 4 bits Of data on Data Pins
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, (((character<<4) >>LCD_D4_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, (((character<<4) >>LCD_D5_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, (((character<<4) >>LCD_D6_PIN) & 1));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, (((character<<4) >>LCD_D7_PIN) & 1));
	LCD_EN_Pluse();

#endif

}
void LCD_Send_string(uint8* string)
{
	uint8 counter = 0;
	while( *string > 0)
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
