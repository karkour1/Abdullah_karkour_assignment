/*
 *  main.c
 *  Created on: Dec 6, 2023
 *  Author: Abdullah karkour
 */

// Read bit in REG
#define READ_BIT(REG , BIT_NUM)   ((REG>>BIT_NUM) & 1)
#define SET_BIT(REG , BIT_NUM)   REG |=(1<<BIT_NUM)
#define CLEAR_BIT(REG , BIT_NUM) REG &=(~(1<<BIT_NUM))
//PortA Reg
#define DDRA  (*(volatile unsigned char*)0x3A)
#define PORTA  (*(volatile unsigned char*)0x3B)
#define PINA  (*(volatile unsigned char*)0x39)

// PortB REG
#define DDRB  (*(volatile unsigned char*)0x37)
#define PORTB  (*(volatile unsigned char*)0x38)
#define PINB  (*(volatile unsigned char*)0x36)

void GPIO_init()
{
	// set direction of PA pins output
	DDRA |= 0b11111111 ;

	// set pin0 PB input
	DDRB &= ~(1<<0);

}

// counter to Led
unsigned int counter ;
int main()
{
	GPIO_init();
	while(1)
	{
		if(READ_BIT(PINB , 0))
		{
			counter++;
			if(counter == 9)
			{
				PORTA = 0;
				counter =0;
			}
			else
			SET_BIT(PORTA,counter-1);
			while(READ_BIT(PINB , 0));
		}

	}
}
