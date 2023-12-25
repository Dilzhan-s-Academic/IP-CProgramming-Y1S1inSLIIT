#include <stdio.h>
#include <stdbool.h>
#define SIZE 4


int main(void)
{
	int i,j,matrixS[SIZE][SIZE];
	bool isSymmetric = true;
	
	for(i=0;i<4;i++)
	{
		printf("Value for Row %i \n",i+1);
		for(j=0;j<4;j++)
		{
			printf("\tEnter element %i : ",j+1);
			scanf("%i",&matrixS[i][j]);
		}
	}

	for (i=0;isSymmetric==true && i<4;i++)
	{
		for (j=0;isSymmetric==true && j<4;j++)
		{
			if (matrixS[i][j]!=matrixS[j][i])
				isSymmetric=false;
		}
	}
	
	(isSymmetric==true) ? printf("\nThis Matrix is Symmetric Matrix") : printf("\nThis Matrix is not Symmetric Matrix");
}
