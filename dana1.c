#include<stdio.h>

int main(void){
	
	float rainArr[7];
	int i,j;
	float avg=0,min,max,total;
	for(i=0; i<7; i++){
		
	printf("Input the rainfall of day %d :" , i+1);
	scanf("%f" , &rainArr[i]);	
}
for(i=0;i<7;i++)
    {
    	total = 0;
        min=0;
        max=0;
	printf("Day 1 to %d\n" , i+1);
	
	for(j=0;j<=i;j++)
        {
        	total += rainArr[j];
		 
		 if(j == 0)
		 	min = rainArr[j];
		 	
		if(max < rainArr[j])
		 	max = rainArr[j];
		 	
		 if(min > rainArr[j])
		 	min = rainArr[j];
	}
		 avg = total/i+1;
		 printf("Average rainfall :%.2f\n" , avg);
		 printf("Maximum rainfall :%.2f\n" , max);
		 printf("Minimilm rainfall :%.2f\n" , min);
}
return 0;	
}
