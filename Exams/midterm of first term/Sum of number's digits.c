#include <stdio.h>

int Sum_digits_of_number(int number);
int main ()
{
	setbuf(stdout,NULL);

	int number , Result ;
	printf("Enter the number : ");
	scanf("%d",&number);

	Result = Sum_digits_of_number(number);
	printf("Result = %d" , Result);
}

int Sum_digits_of_number(int number)
{
	int Result = 0 , rem ;
	while(number != 0)
	{
		rem = number%10;
		Result += rem ;
		number /= 10 ;
	}

	return Result ;
}
