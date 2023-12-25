#include<stdio.h>

int main(void)
{
	int i,customId;
	char name[10],newNic[20],nic[20];
	
	FILE * fPtr;
	
	fPtr = fopen("employee.txt","r+");
	if(fPtr==NULL)
	{
		printf("file cant be contact.");
		return -1;
	}
	
	for(i=1;i<=2;i++)
	{
		printf("enter the customore id:");
		scanf("%d", &customId);
		
		printf("enter the empkoyee name:");
		scanf("%s", name);
		
		printf("enter the nic number:");
		scanf("%s", &newNic);
		
    

		
		while(!feof(fPtr))
		{
		 fscanf(fPtr,"%d %s %s", &customId, name, &nic);
		}
	
    }
		
		fclose(fPtr);
		
		fPtr= fopen("employee.txt","a+");
			if(fPtr==NULL)
        	{
		     printf("file cant be contact.");
		     return -1;
        	}
		
		
		if(newNic==nic)
		{
			
		}
		else
		{
			fprintf(fPtr,"\n %d    %s    %s",customId,name,newNic);
		}
		
		
		
	
	fclose(fPtr);
	
	return 0;
}
