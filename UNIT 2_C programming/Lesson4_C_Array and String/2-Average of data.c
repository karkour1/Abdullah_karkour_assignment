/*
 * Ex2.c
 *
 *  Created on: Jul 18, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int n ,i;
	printf("Enter the numbers of data : ");
	scanf("%d", &n);

	float Data[n];
	float sum=0;

	for(i=0 ; i<n ;i++)
	{
		printf("%d.Enter number :  " , i+1);
		scanf("%f" , &Data[i] );
		sum += Data[i];
	}

	printf("Average = %.2f" , sum/n);

}
