#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct CONTACTS
{
	int num;
	char name[50];
};
int main(void)
{
	struct CONTACTS contact[5];
	FILE *file;
	int NUM,i,j;
	char NAME[50],NAME_S[50];
	int exist=false,valid=true;
	
	for(i=0;i<5;i++)
	{
		printf("Enter the %i Contact Name : ",i+1);
		scanf("%s",&NAME);
		
		do
		{
			printf("Enter the %i Contact Num : ",i+1);
			if(scanf("%i",&NUM)!=1)
			{
				printf("Please Enter the Valid Contact Number!!\n");
				while(getchar()!='\n');
				valid = false;
			}
			else
				valid = true;
		}while(!valid);
		
		for(j=0;j<=i;j++)
		{
			if(strcmp(contact[j].name, NAME) == 0)
			{
				printf("This Contact is already exist..\n");
				exist =true;
				i--;
				break;
				
			}
		}
		if(!exist)
		{
			
			contact[i].num = NUM;
			strcpy(contact[i].name, NAME);
			
		}
		exist = false;
	}
	file = fopen("Directory.dat","w+");
	for(i=0;i<5;i++)
	{
		fprintf(file,"%i\t%s\n",contact[i].num,contact[i].name);
	}
	fclose(file);
	
	printf("\n-----------------------------------------------------------------------\n");
		
	while(true)
	{
		valid= false;
		printf("Enter the Contact Name :");
		scanf("%s",&NAME);
		file = fopen("Directory.dat","r+");
		while(fscanf(file,"%i\t%s",&NUM,&NAME_S)!=EOF)
		{
			if(strcmp(NAME,NAME_S)==0)
			{
				printf("Contact Num : %i\n\n",NUM);
				valid = true;
				break;
			}
		}
		fclose(file);
		if(!valid)
			printf("This Contact is dosnt exist...\n\n");
	}
	
}
