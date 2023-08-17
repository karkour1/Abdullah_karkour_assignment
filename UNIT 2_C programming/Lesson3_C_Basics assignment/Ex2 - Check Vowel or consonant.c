/*
 * Ex2.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	char c  ;
	printf("Enter an alphabet:  ") ;
	scanf("%c" , &c);

	((c=='a') || (c== 'e') || (c == 'i') || (c== 'o') ||(c== 'u') ||
	 (c=='A') || (c== 'E') || (c == 'I') || (c== 'o') ||(c== 'U') ) ? printf("%c is vowel", c) : printf("%c is consonant", c);
}
