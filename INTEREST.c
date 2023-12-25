#include <stdio.h>
#include <assert.h>

float calcAnnualInterest(float interestRate, float amount)
{
	float interest = amount * interestRate/100.0;
	if(amount>1000000)
		interest += amount * 0.5 / 100;
	return interest;
}

float findTotalAmount(float interestRate, float amount )
{
	float interest = calcAnnualInterest(interestRate,amount);
	float totalAmount = interest + amount;
	
	return totalAmount;
}
void testTotalAmount()
{
	//test 1
	float amount1=1000.0;
	float iRate1 =10;
	float expectedTotal1 = 1100;
	assert(findTotalAmount(iRate1, amount1) == expectedTotal1);
	
	//test 2
	float amount2=2000000.0;
	float iRate2 =15;
	float expectedTotal2 = 2310000;
	assert(findTotalAmount(iRate2, amount2) == expectedTotal2);
}
int main()
{
	float amount,interest,totalAmount;
	int year;
	
	testTotalAmount();
	
	printf("Amount : ");
	scanf("%f",&amount);
	
	printf("Interest Rate : ");
	scanf("%f",&interest);
	
	for (year = 1; year <= 5; year++) {
        totalAmount = findTotalAmount(interest, amount);
        printf("Total amount at the end of year %d: %.2f\n", year, totalAmount);
        amount = totalAmount; // Invest the new total amount for the next year
    }
	
	
}
