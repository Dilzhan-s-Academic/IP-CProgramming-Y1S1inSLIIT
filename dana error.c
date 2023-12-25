#include<stdio.h>

int main(void){
	
	int identityArr[4][4];
	int i,j;
	int flag = 1;
	
	for(i=1; i<5; i++){
		printf("Values for row %d\n" , i);
		
		for(j=1; j<4; j++)
		{
			printf("\tEnter element %d :" , j);
			scanf("%d" , &identityArr[i][j]);
		}
	}
	if(identityArr[1][1] == identityArr[2][2] && identityArr[2][2] == identityArr[3][3] && identityArr[3][3] == identityArr[4][4] && identityArr[1][1] == 1){
		for(i=1; i<5&&flag == 1;i++){
		for(j=1; j<5; j++){
			if(identityArr[i][j] != identityArr[j][i]){
				flag = 0;
				break;
	        }
	    }
    }
    if(flag == 1){
		printf("it is a symmetric matrix\n");
	}else{
		printf("it is not a symmetric matrix\n");
	}
}
return 0; 
}
