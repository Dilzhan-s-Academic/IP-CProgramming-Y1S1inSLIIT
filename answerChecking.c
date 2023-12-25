#include <stdio.h>
#define SIZE 4
int main(void)
{
	FILE *file;
	
	int ans[SIZE], i , correctAns[SIZE] = { 1 , 4 , 2 , 3};
	char index[8];
	
	file = fopen("answers.dat","r");
	
	if(file == NULL)
	{
		printf("Unable to open the file");
		return -1;
	}
	while(fscanf(file, "%s %i %i %i %i" , index ,&ans[0],&ans[1],&ans[2],&ans[3] ) != EOF)
	{
		int numOfCorrectAns = 0;
		
		for(i=0;i<SIZE;i++)
		{
			if(ans[i] == correctAns[i])
				numOfCorrectAns ++;
		}
		printf("%s : %i\n",index , numOfCorrectAns);
		
	}
	fclose(file);
	return 0;
}
