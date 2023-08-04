/*
 * Q5.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	char c ;
	printf("Enter a character: ") ;
	scanf("%c" , &c);
	printf("ASCII value of G = %d" , c);
}
