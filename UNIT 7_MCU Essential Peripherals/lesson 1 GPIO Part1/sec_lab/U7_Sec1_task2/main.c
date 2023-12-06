/*
 *  main.c
 *  Created on: Dec 6, 2023
 *  Author: Abdullah karkour
 */

// Read bit in REG
#define READ_BIT(REG , BIT_NUM)   ((REG>>BIT_NUM) & 1)
#define SET_BIT(REG , BIT_NUM)   REG |=(1<<BIT_NUM)
#define CLEAR_BIT(REG , BIT_NUM) REG &=(~(1<<BIT_NUM))

//PortD REG
#define DDRD  (*(volatile unsigned char*)0x31)
#define PORTD  (*(volatile unsigned char*)0x32)
#define PIND  (*(volatile unsigned char*)0x30)


void GPIO_init()
{
	// set direction of PD pins output
	SET_BIT(DDRD , 5);
	SET_BIT(DDRD , 6);
	SET_BIT(DDRD , 7);

	// set pin0 PB input
	CLEAR_BIT(DDRD , 0);
	CLEAR_BIT(DDRD , 1);
	CLEAR_BIT(DDRD , 2);

}

int main()
{
	GPIO_init();
	while(1)
	{
		// Pull_Down Button
		if(READ_BIT(PIND , 0))
		{
			SET_BIT(PORTD , 5);
			while(READ_BIT(PIND , 0));
		}

		// Pull_up Button
		if( ! READ_BIT(PIND , 1))
		{
			SET_BIT(PORTD , 6);
			while(! READ_BIT(PIND , 1));
		}


	}
}
