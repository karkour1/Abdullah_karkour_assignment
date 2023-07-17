/*
 * Ex4.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	float num ;
	printf("Enter a number:  ") ;
	scanf("%f" , &num);

    if (num == 0) printf("You entered zero.");
    if(num>0) printf("%.2f is positive.", num);
    if(num<0) printf("%.2f is negative.", num);



}
