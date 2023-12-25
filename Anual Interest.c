#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

float calcAnnualInterest(float interestRate, float amount);
float findTotalAmount(float interestRate, float amount);
void testTotalAmount();

int main(void)
{
	float rate,amount,total;
	int i;
	
	testTotalAmount();
	
	do
	{
	printf("Enter Initial Amount to be invested : ");
	if(scanf("%f",&amount)!=1)
	{
		printf("Invalid Input !!");
		while(getchar()!='\n');
	}
	else break ;
	}while(true);
	
	do
	{
	printf("Enter Annual interest Rate(in percentage) : ");
	if(scanf("%f",&rate)!=1)
	{
		printf("Invalid Input !!");
		while(getchar()!='\n');
	}
	else break ;
	}while(true);
	
	for(i=1;i<6;i++)
	{
		total = findTotalAmount(rate,amount);
		amount += calcAnnualInterest(rate,amount);
		printf("Amount after year 1 : %.2f \n",total);
		
	}
	
	return 0;
}

float calcAnnualInterest(float interestRate, float amount)
{
	float AnnualInterest = amount * (interestRate/100);
	if (amount>1000000)
		AnnualInterest += amount * 0.005;
	
	return AnnualInterest;
}

float findTotalAmount(float interestRate, float amount)
{
	float totalAmount,interest;
	interest = calcAnnualInterest(interestRate,amount);
	totalAmount = interest + amount;
	
	return totalAmount;
}

void testTotalAmount()
{
	assert(findTotalAmount(10,1000)==1100);
	assert(findTotalAmount(10,2000000)==2210000);
}

