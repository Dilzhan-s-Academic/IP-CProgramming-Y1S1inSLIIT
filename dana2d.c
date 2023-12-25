#include<stdio.h>

int main()
{
	int array [4][4];
	int flag = 1;
	int i,j;
	for(i=0;i<4;i++)
	{
		printf("row %i\n",i);
		for(j=0;j<4;j++)
		{
			printf("\telement %i : ",j);
			scanf("%i",&array[i][j]);
	}
	}
	for(i=0;i<4 && flag == 1;i++)
	{
		for(j=0;j<4;j++)
		{
			if(array[i][j]!=array[j][i])
			{
				flag = 0;
				break;
			}
		}
	}

	if(flag == 1)
		printf("s");
	else
		printf("Ns");
				
				
	return 0;
}
