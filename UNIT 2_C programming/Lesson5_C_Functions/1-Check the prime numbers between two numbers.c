/*
 * Ex1.c
 *
 *  Created on: Jul 20, 2023
 *      Author: abdullah
 */


#include <stdio.h>

void prime_Numbers(int n1 , int n2);
int main ()
{
	setbuf(stdout,NULL);

	int num1 , num2 ;
	printf("Enter two numbers(intervals) :");
	scanf("%d %d", &num1 , &num2);
	prime_Numbers(num1,num2);


}

void prime_Numbers(int n1 , int n2)
{
	printf("Prime numbers between %d and %d are :  ", n1,n2);

	int i , j , flag =0;
	for( i= n1 ; i<= n2 ; i++)
	{
		for(j=2 ; j<= (i/2) ; j++)
		{
			if(i%j == 0)
			{
			flag =1;
			break;
			}
		}
		if(flag==0) printf("%d " , i );
		flag=0;
	}
}
