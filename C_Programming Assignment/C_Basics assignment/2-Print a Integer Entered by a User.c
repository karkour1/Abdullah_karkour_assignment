/*
 * Q2.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int num ;
	printf("Enter a integer: ") ;
	scanf("%d" , &num);
	printf("You entered: %d" , num);
}
