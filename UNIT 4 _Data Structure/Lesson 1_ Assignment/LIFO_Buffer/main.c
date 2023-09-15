/*
 * main.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Abdullah karkour
 */


#include <stdio.h>
#include "Platform_Types.h"
#include "LIFO.h"

element_Type Buffer1[LIFO_Length];

int main ()
{
	LIFO_Buf_t Student ;
	element_Type i , item ;

	// LIFO initialization
	LIFO_init(Student, Buffer1, LIFO_Length);

	// ADD items
	printf("Push Buffer items =  ");
	for (i = 0 ; i< LIFO_Length ; i++)
	{
		printf("%d	" , i);
		LIFO_Add_item(&Student, i);
	}

	// POP items
	printf("\nPOP Buffer items =   ");
	for (i = 0 ; i< LIFO_Length ; i++)
	{
		LIFO_Get_item(&Student, &item);
		printf("%d	" , item);

	}

	return 0;
}
