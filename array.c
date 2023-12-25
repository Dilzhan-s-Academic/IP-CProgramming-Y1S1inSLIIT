#include <stdio.h>
int main()
{
	int block,i,n,array[8] = {10,11,12,13,14,15,16,17};
	
	printf("n:");
	scanf("%i",&n);
	block=8-n;
	for (i=0;i<8;i++)
	{
		if (i<n)
			array[i]=array[i+block];
		else
			array[i]=array[i-n];
	}
	for (i=0;i<8;i++)
	{
		printf("%i\t",array[i]);
	}
}
