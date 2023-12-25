#include<stdio.h>

char inputTransactionType(char *msg,int i)
{
	char type;
	printf(msg,i);
	scanf(" %c",&type);
	switch (type)
	{
		case 'W':
			type='W';
			break;
		case 'w':
			type='W';
			break;
		case 'D':
			type='D';
			break;
		case 'd':
			type='D';
			break;
		default:
			printf("Invalid Transaction Type!!!\n");
			type='X';
			break;
	}
	
	return type;
}
int main(void)
{
	int i,j;
	float totalWithdraw,maxWithdraw,totalDeposit,maxdeposit,array[5][4],maxWithdrawer[8],maxDepositer[8];
	
	for (i=0;i<5;i++)
	{
			printf("Enter the %i Customer Acc Num : ",i+1);
			scanf("%i",&array[i][0]);
			
			printf("Enter the %i Customer Name : ",i+1);
			scanf("%s",&array[i][1]);
			
			while ((array[i][2] = inputTransactionType("Enter the %i Customer Transaction Type : ",i+1))=='X');
			
			printf("Enter the %i Customer Transaction Amount : ",i+1);
			scanf("%f",&array[i][3]);
			
			printf("\n ------------------------------------------------------------------------------------------ \n");
	}
	for (i=0;i<5;i++)
	{
		if (array[i][2] == 'W')
		{
			totalWithdraw += array[i][3];
			if (maxWithdraw<array[i][3])
			{
				*maxWithdrawer = array[i][1];
			}
		}
		else if (array[i][2] == 'D')
		{
			totalDeposit += array[i][3];
			if (maxdeposit<array[i][3])
			{
				*maxDepositer = array[i][1];
			}
		}
	}
	printf("Total Deposit Amount : %.2f\n",totalDeposit);
	printf("Total Withdraw Amount : %.2f\n",totalWithdraw);
	printf("max depositer : %s\n",maxDepositer);
	printf("max withdraw : %s\n",maxWithdrawer);
}
