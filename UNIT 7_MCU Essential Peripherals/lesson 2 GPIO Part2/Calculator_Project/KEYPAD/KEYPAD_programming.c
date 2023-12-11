/*
*	KEYPAD_programming.c
*  	Created on: Dec 10, 2023
*   Author: Adbullah Karkour
*/

#include "KEYPAD_Config.h"
#include "KEYPAD_interface.h"
#include "ATMEGA32_REG.h"
#include "Platform_Types.h"

uint8 KEYPAD_ROW[KEYPAD_ROWS] = {KEYPAD_R0,KEYPAD_R1,KEYPAD_R2,KEYPAD_R3};
uint8 KEYPAD_COLUM[KEYPAD_COLUMS] = {KEYPAD_C0,KEYPAD_C1,KEYPAD_C2,KEYPAD_C3};
uint8 keys[KEYPAD_ROWS][KEYPAD_COLUMS]= KEYPAD_keys ;

void KEYPAD_init(void)
{
	/* Set the ROWS pins  input */
	KEYPAD_DDR &= ~((1<<KEYPAD_R0)|(1<<KEYPAD_R1)|(1<<KEYPAD_R2)|(1<<KEYPAD_R3));

	/* Set The COLUMS pins Output */
	KEYPAD_DDR |= ((1<<KEYPAD_C0)|(1<<KEYPAD_C1)|(1<<KEYPAD_C2)|(1<<KEYPAD_C3));

	/* Set the port of data */
	KEYPAD_PORT = 0xff ;
}
char KEYPAD_GetKey(void)
{
	uint8 i , j ;

	for (i=0 ; i<KEYPAD_COLUMS ; i++)
	{
		KEYPAD_PORT |= ((1<<KEYPAD_COLUM[0])|(1<<KEYPAD_COLUM[1])|(1<<KEYPAD_COLUM[2])|(1<<KEYPAD_COLUM[3]));

		/* clear COLUM number i to check the low voltage when click key */
		KEYPAD_PORT &= ~(1<<KEYPAD_COLUM[i]);

		/* loop for ROWs */
		for(j= 0 ; j<KEYPAD_ROWS ; j++ )
		{
			if (!(KEYPAD_PIN & (1<<KEYPAD_ROW[j])))
			{
				while(!(KEYPAD_PIN & (1<<KEYPAD_ROW[j])));
				return keys[j][i];
			}
		}
	}

	return 0 ;
}
