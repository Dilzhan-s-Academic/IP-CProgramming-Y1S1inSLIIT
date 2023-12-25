#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
double payableAmount(char vehicleType , int numDays)
{
	double rent,amount,discount;
	
	switch (vehicleType)
	{
		case 'a':
			rent = 4000;
			break;
		case 'b':
			rent = 8000;
			break;
	}
	
	
	if (numDays >= 3 && numDays <= 5 )
		discount = 0.1;
	else if (numDays >= 6)
		discount = 0.2;
	
	rent *= numDays;
	amount = rent - rent * discount;
	return amount; 
}

double paymentAfterTax(double payment)
{
	double rate;
	if (payment > 15000)
		rate = 0.2;
	else if (payment <= 15000 && payment > 10000)
		rate = 0.1;
	else if (payment < 10000)
		rate = 0.05;
	
	payment += payment * rate;
	
	return payment;
}

void testPaymentAfterTax()
{
	assert(paymentAfterTax(18000) == 21600.00);
	assert(paymentAfterTax(13000) == 14300.00);
	assert(paymentAfterTax(5000) == 5250.00);
}

int main(void)
{
	char type;
	int numDays;
	double payment;
	bool valid;
	
	testPaymentAfterTax();
	
	do
	{
		valid = true;
		printf("Vehicle Type : ");
		if (scanf(" %c",&type)!=1 || (type != 'a' && type != 'b'))
		{
			printf("Invalid Input !!\n");
			while(getchar()!='\n');
			valid = false;
		}
	}while(!valid);
	
	do
	{
		valid = true;
		printf("Num.of.Days :");
		if (scanf("%i",&numDays)!=1)
		{
			printf("Invalid Input !!\n");
			while(getchar()!='\n');
			valid = false;
		}
	}while(!valid);
	
	if(valid)
	{
		payment = paymentAfterTax (payableAmount(type,numDays));
		printf("Payment : %.2f",payment);
	}
	return 0;
}
