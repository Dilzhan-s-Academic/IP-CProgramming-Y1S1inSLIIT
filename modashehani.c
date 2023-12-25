#include <stdio.h>

int main(void)
{
	float total,cost,max,avg,prices[10];
	int i,moreHundred;
	
	for(i=0;i<10;i++)
	{
		printf("Enter the %i price",i+1);
		scanf("%f",&prices[i]);
		total += prices[i];
		if(max<prices[i])
			max=prices[i];
		if(100>prices[i])
			moreHundred++;
		if(500<prices[i])
			cost+=prices[i];
		
	}
	
	avg = total / 10.0;
	
	printf("Average price: %.2f\n",avg);
	printf("Highest price: %.2f\n",max);
	printf("Number of products less than Rs.100:%i \n",moreHundred);
	printf("Total cost of products more than Rs.%500 : Rs.%.2f",cost);
	return 0;
}
