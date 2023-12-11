/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Hello
 */


#include "LCD/LCD_interface.h"
#include "LCD/LCD_Config.h"
#include "KEYPAD/KEYPAD_Config.h"
#include "KEYPAD/KEYPAD_interface.h"

/*Calculator Variables */
uint32 number =0;
double result =0;
uint8 operation =0 ;

/*Calculator APIS */
void DO_Operation(uint8 opp);

int main()
{
	LCD_init();
	KEYPAD_init();
	uint8 pressed_key ;

	while(1)
	{
		pressed_key=KEYPAD_GetKey();
		if (pressed_key != 0)
		{
			LCD_Send_Character(pressed_key);
			if(pressed_key == '/' || pressed_key == '*' || pressed_key == '-' || pressed_key == '+')
			{
				if (operation == 0 )
				{
				result = number ;
				operation = pressed_key ;
				number =0 ;
				}
				else
				{
					DO_Operation(operation);
					operation = pressed_key ;
					number = 0;
				}
			}
			else if (pressed_key == '=')
			{
				DO_Operation(operation);
				LCD_Clear_Screen();
				LCD_Display_Real_Number(result);
				result =0 ;
				number =0 ;
				operation =0 ;
			}
			else if(pressed_key == 'C')
			{
				result =0 ;
				number =0 ;
				LCD_Clear_Screen();
			}
			else
			{
				number = (number*10)+ (pressed_key - '0');
			}

		}


	}
}
void DO_Operation(uint8 opp)
{
	switch(opp)
	{
	case '/' :
		result /= number ;
		break ;
	case '*':
		result *= number ;
		break;
	case '-' :
		result -= number ;
		break ;
	case '+' :
		result += number ;
		break;
	}

}
