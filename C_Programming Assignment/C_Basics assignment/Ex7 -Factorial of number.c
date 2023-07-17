/*
 * Ex7.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int num ,i , Factorial=1 ;
	printf("Enter an integer:  ") ;
	scanf("%d" , &num);

	if(num >= 0)
	{
	for(i=1 ; i<= num ; i++)
	{
		Factorial *= i ;
	}

	printf("Factorial = %d" , Factorial);
	}

	else printf("Error!!! Factorial of negative number doesn't exist.") ;

}
