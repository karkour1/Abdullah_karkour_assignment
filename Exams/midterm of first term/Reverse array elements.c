#include <stdio.h>
#include <string.h>


void Reverse_array_elements(int arr[ ] , int rev[] , int size );
int main ()
{
	setbuf(stdout,NULL);

	int size , i ;
	printf("Enter size of array : ");
	scanf("%d",&size);

	int arr[size] , rev[size] ;
	printf("Enter elements : ");
	for(i=0; i<size ;i++)
	{
		scanf("%d", &arr[i]);
	}

	Reverse_array_elements(arr ,rev , size);

	printf("Revere array : ");
	for(i=0; i<size ;i++)
	{
		printf("%d ", rev[i]);
	}


}

void Reverse_array_elements(int arr[ ] , int rev[] , int size )
{
	int i ;

	for(i=0; i<size ;i++)
	{
		rev[i] = arr[size-i-1];
	}

}
