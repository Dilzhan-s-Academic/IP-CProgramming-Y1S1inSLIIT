#include <stdio.h>
#include<assert.h>

float calcPayment(int pType,float totalData)
{
	float payment,extraUsage,dataBundle,exUsageCharges,monthlysub;
	switch (pType)
	{
		case 1:
			dataBundle = 1.5;
			exUsageCharges = 2;
			monthlysub = 120.0;
			break;
		case 2:
			dataBundle = 5;
			exUsageCharges = 1.5;
			monthlysub = 350.0;
			break;
		case 3:
			dataBundle = 10;
			exUsageCharges = 1;
			monthlysub = 660.0;
			break;
		case 4:
			dataBundle = 20;
			exUsageCharges = 0.5;
			monthlysub = 1200.0;
			break;
	}
	if (totalData > dataBundle)
	{
		extraUsage = totalData - dataBundle;
		payment = ((extraUsage*1024)*exUsageCharges) + monthlysub;
	}
	else 
		payment = monthlysub;
	
	return payment;
}

float calcTax(float payment)
{
	return payment*5/100;
}

void displayDetails(float payment,float tax)
{
	printf("%s %15s%26s","Payment","Tax Amount","Monthly Bill Payment\n");
	printf("%.2f %11.2f%16.2f\n\n\n",payment,tax,payment+tax);
}

int main(void)
{
	int i,type;
	float totalData,payment,tax;
	assert(calcPayment(1,2)==1144);
	assert(calcPayment(2,2)==350);
	for (i=0;i<3;i++)
	{
		printf("Package Type : ");
		if (scanf("%i",&type)==1)
		{
			printf("Total Data Usage :");
			if (scanf("%f",&totalData)==1)
			{
				printf("\n");
				payment = calcPayment(type,totalData);
				tax = calcTax(payment);
				displayDetails(payment,tax);
			}
			else
			{
				while(getchar()=='\n');
				i--;
				printf("Invalid Input Try Again!!\n\n");
			}
		}
		else
		{
			while(getchar()=='\n');
			i--;
			printf("Invalid Input Try Again!!\n\n");
		}
		
	}
	
}
