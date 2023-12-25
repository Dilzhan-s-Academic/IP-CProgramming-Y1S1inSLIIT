#include <stdio.h>

int main()
{
    float rain[7],avg =0,total,max,min;
    int i,j;

    for(i=0;i<7;i++)
    {
        printf("day %i :",i+1);
        scanf("%f",&rain[i]);

    }

    for(i=0;i<7;i++)
    {
    	total = 0;
        min=0;
        max=0;
		printf("1 to %i\t",i+1);
        
        for(j=0;j<=i;j++)
        {
        	total += rain[j];
        	
        	if(j==0)
        		min=rain[j];
        		
        	if(max<rain[j])
        		max=rain[j];
        	if (min>rain[j])
        		min = rain[j];
		}
		
		avg = total/(i+1);
		printf("%.2f \n",avg);
		printf ("min : %.2f \n",min);
		printf ("max : %.2f \n",max);
    }

    return 0;
}
