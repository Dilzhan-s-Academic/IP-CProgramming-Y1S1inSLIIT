#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct loyalty
{
    int loyaltyNum;
    char *Name;
};


int main(void)
{
    FILE *file;
    int i,j,loyaltyNum,rows = 0;
	char name[50];
	bool valid;
	char a;
	
    file = fopen("loyalty.dat","r");

    while(fscanf(file,"%i %s",&name,&loyaltyNum)!= EOF)
    {
        rows++;
    }
    fclose(file);
    struct loyalty oldmem[rows];
    struct loyalty newMem[5];

    file = fopen("loyalty.dat","r+");

    for(i=0;i<rows;i++)
    {
        fscanf(file,"%i %s",&oldmem[i].loyaltyNum,&oldmem[i].Name);
    }
    fclose(file);
    
    for(i=0;i<5;i++)
    {
        printf("Enter the Name %i:",i);
        scanf("%s",&name);

        printf("Enter the Loyalty Number %i : ",i);
        scanf("%i",&loyaltyNum);

		printf("\n");
        for (j=0;j<rows;j++)
        {
            if(oldmem[j].loyaltyNum == loyaltyNum)
            {
                printf("Existing old\n");
                valid = false;
                i--;
                break;
            }
            else
            	valid = true;
        }
        if(valid)
        {
            for (j=0;j<5;j++)
            {
                if(newMem[j].loyaltyNum == loyaltyNum)
                {
                    printf("Existing new\n");
                    valid = false;
                    i--;
                    break;
                }
        	}
        }
        if(valid)
        {
        	newMem[i].Name = strdup(name);
			newMem[i].loyaltyNum = loyaltyNum;
		}
		
	}

    file = fopen("loyalty.dat","a+");
    if(a!='\n')
    		fprintf(file,"\n");
    for(i=0;i<5;i++)
    {
    	printf("%s",newMem[i].Name);
        fprintf(file,"\n%i\t%s",newMem[i].loyaltyNum,newMem[i].Name);
        printf("1");
    }
    fclose(file);

    return 0;
}
