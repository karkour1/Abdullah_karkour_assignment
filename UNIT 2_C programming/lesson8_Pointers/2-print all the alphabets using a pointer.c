#include <stdio.h>


int main ()
{
	char alphabet[26] ; // array to store alphabet characters
	char *ptr ;
	ptr = alphabet;// pointer to array of characters
	int i ;

	// assign the characters of alphabet
	for(i =0 ; i<26 ; i++)
	{
		*ptr = 'A'+ i ;
		ptr++;
	}

	// print the alphabet
	printf("The Alphabet are :  \n");
	ptr = alphabet;
	for(i=0 ; i<26 ;i++)
	{
		printf("%c\t" , *ptr);
		ptr++;
	}
}


