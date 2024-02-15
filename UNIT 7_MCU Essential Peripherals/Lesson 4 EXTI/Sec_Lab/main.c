/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Hello
 */


#include "LCD_interface.h"
#include "LCD_Config.h"


int main()
{
	LCD_init();
	LCD_Send_string("Learn in Depth");

	while(1)
	{
	}
}

