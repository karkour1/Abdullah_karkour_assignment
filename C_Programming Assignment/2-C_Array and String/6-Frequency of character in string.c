/*
 * Ex6.c
 *
 *  Created on: Jul 18, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	char sen[100] , c;
	printf("Enter a string: ");
	gets(sen);

	printf("Enter a character to find frequency: ");
	scanf("%c",&c);

	int i=0,counter =0;
	while(sen[i] != '\0')
	{
		if (sen[i] == c) counter++;
		i++;
	}

	printf("Frequency of %c = %d " , c, counter);
}
