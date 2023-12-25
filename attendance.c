#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*This program has a file handling , var declarations , pointer declarations , iterations , array declarations and if else statements*/
int main(void)
{
	char empNo[20], empName[20];
	bool attendance[7];
	int i,j;
	FILE *file;
	
	file = fopen("attendance.dat","w+");
	for(i=0;i<2;i++)
	{
		printf("Enter the %i Emp No :",i+1);
		scanf("%s",empNo);
		
		printf("Enter the %i Emp Name :",i+1);
		scanf("%s",empName);
		
		for(j=1;j<8;j++)
		{
			printf("Day %i:",j);
			if(scanf("%i",&attendance[j])!=1 || (attendance[j] != 0 && attendance[j] != 1))
			{
				printf("invalid Input!! \n");
				while(getchar()!='\n');
				j--;
			}
		}
		
		fprintf(file,"%s\t%s\t",empNo,empName);
		
		for(j=1;j<8;j++)
		{
			fprintf(file,"%i ",attendance[j]);
		}
		fprintf(file,"\n");
				
	}
	fclose(file);
	
	return 0;
}
