/*
 * Ex1.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int num  ;
	printf("Enter an integer you want to check:  ") ;
	scanf("%d" , &num);

	(num%2 == 0)? printf("%d is even", num) : printf("%d is odd", num);
}
