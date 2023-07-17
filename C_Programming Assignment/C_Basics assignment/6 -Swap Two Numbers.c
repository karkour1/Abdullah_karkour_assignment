/*
 * Q6.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	float a , b , temp ;
	printf("Enter value of a:  ") ;
	scanf("%f" , &a);
	printf("Enter value of b:  ") ;
	scanf("%f" , &b);
	temp = a ;
	a=b;
	b= temp;
	printf("After swapping, value of a = %f\nAfter swapping, value of b = %f" , a, b);
}
