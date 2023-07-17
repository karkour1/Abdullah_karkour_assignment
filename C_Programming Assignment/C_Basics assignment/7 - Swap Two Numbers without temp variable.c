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

	int a , b  ;
	printf("Enter value of a:  ") ;
	scanf("%d" , &a);
	printf("Enter value of b:  ") ;
	scanf("%d" , &b);
	a ^= b;
	b ^= a ;
	a ^= b;
	printf("After swapping, value of a = %d\nAfter swapping, value of b = %d" , a, b);
}
