#include <stdio.h>
#include <math.h>
double Square_root(int number);
int main ()
{
	setbuf(stdout,NULL);

	int number ;
	double Result ;
	printf("Enter the number : ");
	scanf("%d",&number);

	Result = Square_root(number);
	printf("Result = %.3lf" , Result);
}

double Square_root(int number)
{
	return sqrt(number) ;
}
