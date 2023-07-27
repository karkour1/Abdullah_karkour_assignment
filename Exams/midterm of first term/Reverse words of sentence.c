#include <stdio.h>
#include <string.h>

int  words;
void Get_words(char sen[100][14]);

int main ()
{
	setbuf(stdout,NULL);

	char sen [100][14];
	printf("Enter the sentence : ");

    Get_words(sen);

	int i ;
	printf("Output : ");
	for(i= words ; i>=0 ; i--)
	{
		printf("%s" , sen[i]);
	}
}

void Get_words(char sen[100][14])
{
	int i , j  ;
	for(i=0 ; i<100 ; i++)
	{
		for(j=0 ; j<14 ;j++)
		{
			scanf("%c" , &sen[i][j]);
			if(sen[i][j] == ' ' || sen[i][j] == '\n')
			{
				sen[i][j+1] = '\0';
				break ;
			}
		}

		if(sen[i][j] == '\n')
		{
			sen[i][j] = '\0';
			words = i ;
			break ;
		}
	}
}

