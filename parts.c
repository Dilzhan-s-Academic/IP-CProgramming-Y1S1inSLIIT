#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct items
{
	int num;
	char name[50];
};
int main(void)
{
	struct items item[5];
	FILE *file;
	int NUM,i,j;
	char NAME[50];
	int exist=false;
	
	for(i=0;i<5;i++)
	{
		printf("Enter the %i Item Code : ",i+1);
		scanf("%i",&NUM);
		
		printf("Enter the %i Item Name : ",i+1);
		scanf("%s",&NAME);
		
		for(j=0;j<=i;j++)
		{
			if(strcmp(item[j].name, NAME) == 0)
			{
				printf("This Item is already exist..\n");
				exist =true;
				i--;
				break;
				
			}
		}
		if(!exist)
		{
			
			item[i].num = NUM;
			strcpy(item[i].name, NAME);
			
		}
		exist = false;
	}
	file = fopen("items.dat","w+");
	for(i=0;i<5;i++)
	{
		fprintf(file,"%i\t%s\n",item[i].num,item[i].name);
	}
	fclose(file);
	file = fopen("items.dat","r+");
	for(i=0;i<5;i++)
	{
		while(fscanf(file,"%i\t%s",&NUM,&NAME)!=EOF)
			printf("%i\t%s\n",NUM,NAME);
	}
	fclose(file);
}
