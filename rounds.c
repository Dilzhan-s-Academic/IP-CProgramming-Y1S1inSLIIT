#include <stdio.h>
#include <stdbool.h>
#define rounds 3

char inputYN(char *msg)
{
	char input;
	bool valid = false;
	do
	{
		printf(msg);
		scanf(" %c",&input);
		switch (input)
		{
			case 'Y':
				input='Y';
				valid=false;
				break;
			case 'y':
				input='Y';
				valid=false;
				break;
			case 'N':
				input='N';
				valid=false;
				break;
			case 'n':
				input='N';
				valid=false;
				break;
			default :
				valid=true;
				printf("Please Enter the valid Input");
		}
	}while(valid);
	
	return input;
}
int main (void)
{
	int i,score,totalScore=0,count=1;
	float avg=0;
	char newPlayer;
	
	while(true)
	{
		avg = 0;
		totalScore = 0;
		printf("Enter the score of Player %i (between 0-4)\n",count);
		for(i=0;i<3;i++)
		{
			score = 0;
			printf("round %i : ",i+1);
			if (scanf("%i",&score)==1 && score<5 && score>=0)
			{
				totalScore += score;
			}
			else 
			{
				while (getchar() != '\n');
				i--;
				printf("Input Valid Score!!\n");
			}
		}
		avg = totalScore/3.0;
		printf("Average Score : %.2f",avg);
		
		newPlayer = inputYN("\nDo You want to enter the score of anther player :");
		if (newPlayer == 'N')
			break;
		else
			count++;
				
	}
}
