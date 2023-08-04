#include <stdio.h>
#include<string.h>

int main ()
{
	setbuf(stdout , NULL);
	char alphabet[100] ; // array of characters
	printf("Enter the string to be reversed : ");
	gets(alphabet); // input string

	char *ptr ;
	ptr = &alphabet[strlen(alphabet)-1];// pointer to end of array
	int i ;

	// print the reverse string
	printf("The string is : ");
	for(i=0 ; i<strlen(alphabet) ;i++)
	{
		printf("%c" , *ptr);
		ptr--; // move pointer in reverse order from end of array to it's start
	}
}


