/*
 * main.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Abdullah karkour
 */

#include "FIFO.h"
#include <string.h>
#include<stdlib.h>


// Create Data Buffer
element_type buffer1[FIFO_length];

void Operation ();
int main ()
{
	setbuf(stdout , NULL);

	FIFO_Buf_t fifo ;
	// initialization of FIFO
	FIFO_init(&fifo, buffer1, FIFO_length);

	element_type item ;
	uint8 temp_text[40] ;
	uint32 op_number ;

	while(1)
{
	// show options
	Operation();
	DPRINTF("\nEnter the number of choice you want :");
	gets(temp_text);
	op_number = atoi(temp_text);

	switch(op_number)
	{
	case 1 :
		DPRINTF("\nEnter the item : ");
		gets(temp_text);
		item = atoi(temp_text);
		FIFO_enqueue(&fifo, item);
		break;
	case 2 :
		FIFO_dequeue(&fifo, &item);
		DPRINTF("\nthe item:\n	%d\n" , item);
		break;
	case 3 :
		FIFO_Print(&fifo);
		break ;
	case 4:
		return 0;
	default :
		DPRINTF("\nEnter correct Number from choice\n");
	}
}
}

void Operation ()
{
	DPRINTF("\n1. Add item to FIFO \n2. pop item from FIFO \n3. Show the FIFO items \n4. Quit");
}
