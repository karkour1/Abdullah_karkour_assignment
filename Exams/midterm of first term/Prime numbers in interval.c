#include <stdio.h>
#include <math.h>

void Prime_numbers(int n1 , int n2 );
int main ()
{
	setbuf(stdout,NULL);

	int num1 , num2 ;
	printf("Enter two numbers (interval) : ");
	scanf("%d %d",&num1 , &num2);

	Prime_numbers(num1 , num2);
}

void Prime_numbers(int n1 , int n2 )
{
	printf("Prime numbers between %d and %d are : " , n1 , n2);

	int i , j , flag = 0 ;
	for (i =n1 ; i<n2 ; i++)
	{
		for(j=2 ; j<= i/2 ; j++)
		{
			if(i%j == 0)
			{
				flag =1 ;
				break ;
			}
		}

		if (flag==0) printf("%d ",i);
		flag = 0 ;
	}
}
