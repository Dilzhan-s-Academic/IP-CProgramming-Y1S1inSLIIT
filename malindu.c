#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int i,j,length,flag=0;
    char input[10];

    while(true)
    {

        printf("Enter 4 digit :");
        scanf(" %s",input);

        int length = strlen(input);

        if(length !=4)
        {
            printf("invalid");

        }
        else
        {
            for(i=0;i<2;i++)
            {

                if(input[i]==input[length-1-i])
                {
                    flag = 1;
                    break;
                }
                else
                	flag = 0;
                	break;
            }
            if (flag == 1)
            {
                printf("plandrom");
            }
            else
                printf("not plandrom");
            break;
        }
    }

}
