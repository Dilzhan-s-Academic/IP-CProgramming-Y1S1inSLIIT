#include <stdio.h>
#define SIZE 3
void inputMatrix(int row,char matName,int mat[row][SIZE])
{
	int j,i;
	for(i=0;i<row;i++)
	{
			printf("Enter the %c matrix %i Row (Ex: 12 13 14) :",matName,i+1);
			scanf("%i %i %i",&mat[i][0],&mat[i][1],&mat[i][2]);
			
	}
}

void mulMat(int mat1[][SIZE],int mat2[][SIZE],int mat3[][SIZE])
{
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
			mat3[i][j]=(mat1[i][0]*mat2[0][j])+(mat1[i][1]*mat2[1][j])+(mat1[i][2]*mat2[2][j]);
	}
}

int main(void)
{
	int A[2][SIZE],B[3][SIZE],C[2][SIZE],i,j;
	inputMatrix(2,'A',A);
	printf("-----------------------------------------------------------\n");
	inputMatrix(3,'B',B);
	printf("-----------------------------------------------------------\n");
	mulMat(A,B,C);
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<SIZE;j++)
			printf("%i\t",C[i][j]);
		printf("\n");
	}
	
	return 0;
}
	

