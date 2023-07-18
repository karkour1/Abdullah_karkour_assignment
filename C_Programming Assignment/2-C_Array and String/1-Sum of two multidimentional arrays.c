/*
 * Ex1.c
 *
 *  Created on: Jul 18, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	float a[2][2];
	float b[2][2];
	int i , j;

	printf("Enter the elements of 1st matrix\n" );
	for(i=0 ; i<2 ;i++)
	{
		for (j=0 ; j<2 ; j++)
		{
			printf("Enter a%d%d :  " , i+1,j+1);
			scanf("%f" , &a[i][j] );
		}
	}

	printf("Enter the elements of 2nd matrix\n" );
	for(i=0 ; i<2 ;i++)
	{
		for (j=0 ; j<2 ; j++)
		{
			printf("Enter b%d%d :  " , i+1,j+1);
			scanf("%f" , &b[i][j] );
		}
	}

	printf("Sum of matrix\n" );
	for(i=0 ; i<2 ;i++)
	{
		for (j=0 ; j<2 ; j++)
		{
			printf("%.1f\t" , a[i][j] + b[i][j]);
		}
		printf("\n");
	}
}
