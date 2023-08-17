#include <stdio.h>


int main ()
{

	int m = 10;
	int* ptr = &m ;

	// address of m and it's value
	printf("Address of  m : %p\n" , &m);
	printf("Value of m : %d\n" , m);

	// ptr is assigned with the address of m
	ptr = &m ;
	printf("Address of  ptr pointer : %p\n" , ptr);
	printf("content of ptr pointer : %d\n" , *ptr);

	m = 34 ; //m assigned to 34
	printf("Address of  ptr pointer : %p\n" , ptr);
	printf("content of ptr pointer : %d\n" , *ptr);

	*ptr = 7 ; //ptr is assigned with the value 7
	printf("Address of  ptr pointer : %p\n" , ptr);
	printf("content of ptr pointer : %d\n" , *ptr);



}


