/*
 * Ex5.c
 *
 *  Created on: Jul 18, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	int n , num ,i;
	printf("Enter no of elements: ");
	scanf("%d", &n);

	int a[n];

	for(i=0 ; i<n ;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("\nEntered the element to be searched :" );
	scanf("%d", &num);

	for(i=0 ; i<n ;i++)
	{
		if(num == a[i])
			{
			   printf("Number found at the location = %d" , i+1);
			   break;
			}
	}
	if(i==n) printf("Number does not exist!");
}
