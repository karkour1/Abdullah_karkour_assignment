/*
 * Ex6.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int num ,i , sum=0 ;
	printf("Enter an integer:  ") ;
	scanf("%d" , &num);

	for(i=1 ; i<= num ; i++)
	{
		sum += i ;
	}

	printf("Sum = %d" , sum);


}
