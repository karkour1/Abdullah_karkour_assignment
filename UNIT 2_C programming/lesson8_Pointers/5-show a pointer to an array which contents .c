#include <stdio.h>

// definition of employee structure
struct employee
{
	char name [50];
	int Id ;
};

int main ()
{
	setbuf(stdout , NULL);

	// number of employees
	int number ;
	printf("Enter the number of employees : ");
	scanf("%d" , &number);

	struct employee array[number];// array of struct employee
	struct empolyee (*ptr_array[number]); //array of pointers to struct employee
	struct employee** ptr = &ptr_array ; // pointer to an array of struct employee  pointers

	// input Data
	int i ;
	for(i=0 ; i<number ;i++ )
	{
		ptr_array[i] = &array[i];
		printf("Employee %d : \n",i+1);
		printf("Enter name : ");
		scanf("%s",(*(ptr+i))->name);
		printf("Enter id : ");
		scanf("%d", &(*(ptr+i))->Id);
	}

	// output Data
	for(i= 0 ; i<number ; i++)
	{

		printf("Data of Employee %d : \n",i+1);
		printf("name : %s\n",(*(*ptr+i)).name);
		printf("Id : %d\n",(*(*ptr+i)).Id);
	}

}


