/*
 * Ex3.c
 *
 *  Created on: Jul 18, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int row , column , i ,j;
	printf("Enter rows and column of matrix: ");
	scanf("%d %d", &row , & column);

	int a[row][column];
	int t[column][row];


	printf("Enter the elements of 1st matrix\n" );
	for(i=0 ; i<row ;i++)
	{
		for (j=0 ; j<column ; j++)
		{
			printf("Enter element a%d%d :  " , i+1,j+1);
			scanf("%d" , &a[i][j] );
		}
	}

	printf("Entered matrix\n" );
	for(i=0 ; i<row ;i++)
	{
		for (j=0 ; j<column ; j++)
		{
			printf("%d\t" , a[i][j]);
		}
		printf("\n");
	}

	printf("Transpose of matrix\n" );
	for(i=0 ; i<column ;i++)
	{
		for (j=0 ; j<row ; j++)
		{
			t[i][j] = a[j][i];
			printf("%.d\t" , t[i][j]);
		}
		printf("\n");
	}
}
