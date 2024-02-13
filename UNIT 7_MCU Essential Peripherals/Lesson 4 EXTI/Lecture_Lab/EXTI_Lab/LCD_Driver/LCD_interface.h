/*
*	LCD_interface.h
*  	Created on: Dec 10, 2023
*   Author: Adbullah Karkour
*/


#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#include "Platform_Types.h"
/* Options FOR LCD Mode:*/
#define LCD_8_BIT_MODE          1
#define LCD_4_BIT_MODE          2

/* LCD interface commands */

#define LCD_RS_ENABLE              1
#define LCD_RS_DISABLE             0
#define LCD_READ       		       1
#define LCD_WRITE      		       0
#define LCD_ENABLE          	   1
#define LCD_DISABLE           	   0
#define LCD_FIRST_LINE             1
#define LCD_SECOND_LINE            0
#define LCD_FUNCTION_8BIT_2LINE    0X38
#define LCD_FUNCTION_4BIT_2LINE    0X28
#define LCD_MOVE_DISP_RIGHT        0X1C
#define LCD_MOVE_DISP_LEFT         0X18
#define LCD_MOVE_CURSOR_RIGHT      0X14
#define LCD_MOVE_CURSOR_LEFT       0X10
#define LCD_DISP_OFF               0X08
#define LCD_DISP_ON_CURSOR         0X0E
#define LCD_DISP_ON_CURSOR_BLINK   0X0F
#define LCD_DISP_ON_BLINK          0X0D
#define LCD_DISP_ON                0X0C
#define LCD_ENTRY_DEC              0X04
#define LCD_ENTRY_DEC_SHIFT        0X05
#define LCD_ENTRY_INC              0X06
#define LCD_ENTRY_INC_SHIFT        0X07
#define LCD_BEGIN_AT_FIRST_RAW     0X80
#define LCD_BEGIN_AT_SECOND_RAW    0XC0
#define LCD_CLEAR_SCREEN           0X01
#define LCD_ENTRY_MODE             0X06


/* LCD APIS */
void LCD_init(void);
void LCD_Is_Busy(void);
void LCD_Clear_Screen(void);
void LCD_Send_Command(uint8 command);
void LCD_Send_Character(uint8 character);
void LCD_Send_string(uint8* string);
void LCD_SET_Cursor(uint8 line , uint8 position );
void LCD_Display_Number(uint32 number);
void LCD_Display_Real_Number(double number);




#endif /* LCD_LCD_INTERFACE_H_ */
