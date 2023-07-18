/*
 * Ex4.c
 *
 *  Created on: Jul 18, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int n , num , location ,i;
	printf("Enter no of elements: ");
	scanf("%d", &n);

	int a[n];

	for(i=0 ; i<n ;i++)
	{
		a[i]= i+1;
		printf("%d " , a[i]);
	}

	printf("\nEntered the element to be inserted :" );
	scanf("%d", &num);

	printf("Entered the location :" );
	scanf("%d", &location);

	a[location-1]= num;

	for(i=0 ; i<n ;i++)
	{
		printf("%d " , a[i]);
	}
}
