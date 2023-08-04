#include <stdio.h>


int main ()
{
	setbuf(stdout , NULL);

	// input the size of array
	int size ;
	printf("Enter the number of elements of array : ");
	scanf("%d" , &size);


	// input elements of array
	int array[size] ;
	int *ptr ;
	ptr = array;// pointer to array
	int i ;
	for(i=0 ; i<size ; i++)
	{
		printf("Element number %d : " , i+1);
		scanf ("%d" , ptr+i);
	}


	// print the reverse array
	printf("The reverse array is : \n");
	for(i=size-1 ; i>=0 ;i--)
	{
		printf("Element number %d :  %d\n" , i+1 ,*(ptr + i));
	}
}


