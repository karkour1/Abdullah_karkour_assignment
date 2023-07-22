/*
 * Ex3.c
 *
 *  Created on: Jul 20, 2023
 *      Author: abdullah
 */


#include <stdio.h>

void Reverse_Sentence(char s[]);
int main ()
{
	setbuf(stdout,NULL);

	char c [100] ;
	printf("Enter a sentence:");
	gets(c);

	Reverse_Sentence(c);


}

void Reverse_Sentence(char s[])
{
	int i =0;
	for(i=0 ; s[i] != '\0' ; i++)
		{
		Reverse_Sentence(&s[i+1]);
		printf("%c" ,s[i]);
		break;
		}

}
