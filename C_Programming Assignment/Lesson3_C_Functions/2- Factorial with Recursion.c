/*
 * Ex2.c
 *
 *  Created on: Jul 20, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int factorial(int n);
int main ()
{
	setbuf(stdout,NULL);

	int num ;
	printf("Enter an positive integer :");
	scanf("%d", &num);

	printf("Factorial of %d = %d ", num ,factorial(num));


}

int factorial(int n)
{
	if(n ==0) return 1 ;
	else 
	{
		n *= factorial(n-1);
	    return n;
	}	
}
