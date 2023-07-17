/*
 * Q4.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	float num1 , num2 ;
	printf("Enter two numbers: ") ;
	scanf("%f\n%f" , &num1 ,&num2);
	printf("Product: %f" , num1 * num2);
}
