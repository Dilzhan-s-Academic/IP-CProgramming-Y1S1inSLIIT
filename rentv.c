#include<stdio.h>
double PayableAmount(char vehicleType, int NumDays);
double paymentAfterTax(double payment);
int main(void)
{
	char vehicleType;
	int numDays;
	double payment,afterTax;

	
	printf("Enter Vehical type: ");
	scanf("%c",&vehicleType);
	printf("Enter number of days: ");
	scanf("%d",&numDays);
	
	payment=PayableAmount(vehicleType,numDays);
	afterTax=paymentAfterTax(payment);
	
	printf("payment : %.2f",payment);
	printf("\nPayment After Tax is: %.2f",afterTax);
	
	
	
	return 0;
}

double PayableAmount(char vehicleType, int NumDays)
{
	double payment;
	float rate;
	if(vehicleType=='a')
	{
		if(NumDays >= 1 &&  NumDays <= 3)
		{
			rate=0;
		}
		else if(NumDays >= 4 &&  NumDays <= 6)
		{
			rate=0.10;
		}
		else if(NumDays>=7)
		{
			rate=0.20;
		}
		
		payment=(5000 * NumDays)*rate;
	}
	else if(vehicleType=='b')
	{
		
		if(NumDays >= 1 &&  NumDays <= 3)
		{
			rate=0;
		}
		else if(NumDays >= 4 &&  NumDays <= 6)
		{
			rate=0.10;
		}
		else if(NumDays>=7)
		{
			rate=0.20;
		}
		
		payment += (8000 * NumDays)*rate;	
	}
	return payment;	
}

double paymentAfterTax(double payment)
{
	float taxrate;
	double newpayment;
	
	if(payment>15000)
	{
		taxrate=0.1;
	}
	else if(payment>=10000 && payment<=15000)
	{
		taxrate=0.05;
	}
	else if(payment<10000)
	{
		taxrate=0;
	}
	
	newpayment=payment+(payment*taxrate);
	return newpayment;
	
	
	
}
