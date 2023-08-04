/*
 * Ex4.c
 *
 *  Created on: Jul 20, 2023
 *      Author: abdullah
 */


#include <stdio.h>
#include <string.h>

int Unique_number_in_array( int arr[] , int size);
int Number_of_occures(int arr[] , int size , int number);
int main ()
{
	setbuf(stdout,NULL);

	int size ,i, unique_number ;
	printf("Enter the size of array : ");
	scanf("%d", &size);

	int arr[size];
	printf("Enter the array : ");
	for (i = 0 ; i<size ;i++)
	{
		scanf("%d", &arr[i]);
	}

	unique_number = Unique_number_in_array(arr,size);

	printf("output : %d", unique_number);
}

int Unique_number_in_array( int arr[] , int size)
{
	int i ;
	for(i =0 ; i< size ; i++)
	{
		if(Number_of_occures(arr,size, arr[i]) == 1) return arr[i];
	}
	return -1;
}
int Number_of_occures(int arr[] , int size , int number)
{
	int i , counter=0;
	for (i=0 ; i<size ; i++) if(arr[i]== number ) counter++;
	return counter;
}

