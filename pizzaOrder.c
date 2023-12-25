#include <stdio.h>
#include <stdbool.h>
#define INVALID_INPUT -404
#define INVALID_charIn 'X'
int inputPizzaType()
{
	int type;
	printf("Input pizza type : ");
	if(scanf("%i",&type)!=1)
	{	
		printf("Invalid Pizza Type !!\n");
		while(getchar() == '\n');
		type = INVALID_INPUT;
	}
	else if (type != 1 && type != 2 && type != -1)
	{
		type = INVALID_INPUT;
		printf("Invalid Pizza Type !!\n");
	}
	return type;
}

char inputPizzaSize()
{
	char size;
	printf("Input the pizza size : ");
	scanf(" %c",&size);
	switch (size)
	{
		case 'L':
			size = 'L';
			break;
		case 'l':
			size = 'L';
			break;
		case 'M':
			size = 'M';
			break;
		case 'm':
			size = 'M';
			break;
		default :
			printf("Invalid Pizza Size !!\n");
			size = INVALID_charIn;
			break;
	}
	return size;
}

int inputPizzaQty()
{
	int qty;
	printf("Input the number of pizzas : ");
	if(scanf("%i",&qty)!=1)
	{
		printf("Invalid Pizza Qty !!\n");
		while(getchar() == '\n');
		qty = INVALID_INPUT;
	}
	return qty;
}

char inputYN(char *msg)
{
	char input;
	printf(msg);
	scanf(" %c",&input);
	switch (input)
	{
		case 'Y':
			input = 'Y';
			break;
		case 'y':
			input = 'Y';
			break;
		case 'N':
			input = 'N';
			break;
		case 'n':
			input = 'N';
			break;
		default :
			printf("Invalid Input !!\n");
			input = INVALID_charIn;
	}
	return input;
}

int main(void)
{
	int type,qty;
	char size,paymentType,customerType,orderType;
	float total,discount,netAmount,price;
	
	do
	{
	while ((type = inputPizzaType()) == INVALID_INPUT);
	if(type == -1)
		break;
	while ((size = inputPizzaSize()) == INVALID_charIn);
	while ((qty = inputPizzaQty()) == INVALID_INPUT);
	
	switch(type)
	{
		case 1:
			if (size == 'L')
				price = 1720.00;
			else
				price = 975.00;
			break;
		case 2:
			if (size == 'L')
				price = 1820.00;
			else
				price = 1000.00;
			break;
	}
	total += price * qty;
	printf("\n");
	
	}while(true);
	
	while((paymentType = inputYN("\n\nAre you paying by credit card (Y/N) ? ")) == INVALID_charIn);
	while((customerType = inputYN("Are you a loyalty customer (Y/N)? ")) == INVALID_charIn);
	while((orderType = inputYN("Is this an online order (Y/N)? ")) == INVALID_charIn);
	
	if (paymentType == 'Y')
		discount += total *0.2;
	if (customerType == 'Y')
		discount += total * 0.15;
	if (orderType == 'Y')
		discount += total * 0.05;
	
	netAmount = total - discount ;
	
	printf("\n\nTotal bill amount: %.2f\n",total);
	printf("Discount: %.2f\n",discount);
	printf("Net Amount: %.2f\n",netAmount);
	
	return 0;
}
