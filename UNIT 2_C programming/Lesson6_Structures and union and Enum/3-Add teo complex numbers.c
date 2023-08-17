#include <stdio.h>
#include <string.h>

struct Scomplex {
	float  real ;
	float imag ;
};
struct Scomplex Summation( struct Scomplex num1 , struct Scomplex num2 );
int main ()
{
	setbuf(stdout,NULL);

	struct Scomplex num1 ,num2,sum;

	printf("Enter real and imaginary respectively :");
	scanf("%f",&num1.real);
	scanf("%f" , &num1.imag);

	printf("Enter real and imaginary respectively :");
	scanf("%f",&num2.real);
	scanf("%f" , &num2.imag);

	sum = Summation(num1, num2);

	printf("Sum = %.1f + %.1f i", sum.real , sum.imag);

}
struct Scomplex Summation( struct Scomplex num1 , struct Scomplex num2 )
{
	struct Scomplex sum ;
	sum.real = num1.real + num2.real ;
	sum.imag = num1.imag + num2.imag ;

	return sum ;

}


