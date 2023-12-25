#include <stdio.h>
#include <stdbool.h>

struct people
{
	int lNum;
	char name[10];
};

int main(void)
{
	int i=0;
	struct people oldArray [2],newAraay[5];
	
	FILE *file;
	
	
	file = fopen("loyalty.dat","r");
	
	while(fscanf(file,"%i %s",&oldArray[i].lNum,&oldArray[i].name)!=EOF)
	{
		i++;
	}
	fclose(file);
	
	file = fopen("loyalty.dat","a+");
	for(i=0;i<5;i++)	
	{
		do
		{
			
		printf("Enter the Loyality Number : ");
		scanf("%i",&newAraay[i].lNum);
		
		if(oldArray[i].lNum == newAraay[i].lNum )
		{
			printf("loyalty number already exists\n");
		}
		else break;
		}while(true);
		
		printf("Enter the Name : ");
		scanf("%s",&newAraay[i].name);
		
		fprintf(file,"%i %s",newAraay[i].lNum,newAraay[i].name);
		
	}
	
	fclose(file);
	
	return 0;
	
}
