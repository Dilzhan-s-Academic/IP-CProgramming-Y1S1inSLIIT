#include <stdio.h>
#include <stdbool.h>
int main (void)
{
	int i,j,ratings[3][4];
	
	for (i=0;i<3;i++)
	{
		printf("Movie %i :\n",i+1);
		for (j=0;j<4;j++)
		{
			do
			{
				printf("\t %i Review :",j+1);
				if(scanf("%i",&ratings[i][j])!=1 || ratings[i][j] < 0 || ratings[i][j]>10 )
				{
					printf("\t Invalid Input !");
					while(getchar()!='\n');
				}
				else break;
				puts("");
			}while(true);
		}
	}
	for (i=0;i<3;i++)
	{
		for (j=0;j<4;j++)
		{
			printf("%i\t",ratings[i][j]);
		}
		puts("");
	}
}
