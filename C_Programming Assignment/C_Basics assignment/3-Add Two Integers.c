/*
 * Q3.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int num1 , num2 ;
	printf("Enter two integer: ") ;
	scanf("%d\n%d" , &num1 ,&num2);
	printf("Sum: %d" , num1 + num2);
}
