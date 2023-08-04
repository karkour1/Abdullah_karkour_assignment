#include <stdio.h>
#include <string.h>

struct Sstudent {
	char name[100] ;
	int  roll ;
	float marks ;
};
int main ()
{
	setbuf(stdout,NULL);

	int size , i ;
	printf("Enter number of students :");
	scanf("%d" , &size) ;

	struct Sstudent student1 [size];

	for (i = 0 ; i<size ;i++)
	{
		student1[i].roll = i+1 ;
		printf("for roll number %d: \n" ,student1[i].roll );
		printf("Enter name : ");
		scanf("%s", student1[i].name);
		printf("Enter marks : ");
		scanf("%f", &student1[i].marks);
	}

	printf("\nDisplay information of students : \n\n");
	for (i = 0 ; i<size ;i++)
	{
		printf("Information for roll %d: \n" ,student1[i].roll );
		printf("Name : %s\n",student1[i].name);
		printf("Marks : %.2f\n\n" , student1[i].marks);
	}

}



