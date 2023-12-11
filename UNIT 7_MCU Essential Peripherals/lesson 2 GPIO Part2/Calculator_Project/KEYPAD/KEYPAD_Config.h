/*
*	KEYPAD_Config.h
*  	Created on: Dec 10, 2023
*   Author: Adbullah Karkour
*/


#ifndef KEYPAD_KEYPAD_CONFIG_H_
#define KEYPAD_KEYPAD_CONFIG_H_

/* KETPAD Configuration port */
#define KEYPAD_PORT    PORTD
#define KEYPAD_PIN     PIND
#define KEYPAD_DDR     DDRD

/* KEYPAD PINS */
#define  KEYPAD_R0   0
#define  KEYPAD_R1   1
#define  KEYPAD_R2   2
#define  KEYPAD_R3   3

#define  KEYPAD_C0   4
#define  KEYPAD_C1   5
#define  KEYPAD_C2   6
#define  KEYPAD_C3   7

/*NUMBER OF ROWS AND COLUMS*/
#define  KEYPAD_ROWS   4
#define  KEYPAD_COLUMS 4

/* KEYPAD KEYS */
#define  KEYPAD_keys  {'7','8','9','/','4','5','6','*', '1','2','3','-','C','0','=','+'}


#endif /* KEYPAD_KEYPAD_CONFIG_H_ */
