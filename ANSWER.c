#include <stdio.h>
#include <stdbool.h>

int main(){
	
	char studentID[];
	int answers[4];
	bool valid = true;
	int i, j, numberOfCorrectAnswers;
	
	FILE *fptr;
	fptr = fopen("answers.dat", "w");
	
	
	for (j = 1; j <= 2; j++){
		
		
		
		printf("Enter user ID : ");
		
		scanf("%s", studentID);
		
		
		
		for(i = 0; i < 4; i++){
		
			//do{--->code bloat
			
				printf("  Question %d : ", i + 1);
				scanf("%d", &answers[i]);
			
				if(answers[i] > 5 || answers[i] < 1){
					printf("Answer Shuld be in between 1 to 5, Try again !\n");
					i--; // Preventing storing the wrong answer
				}
			
			//}while(answers[i] > 5 || answers[i] < 1); --->code bloat
		}
		
		fprintf(fptr, "%s  %d %d %d %d \n", studentID, answers[0], answers[1], answers[2], answers[3]); // \n
		
		if(j < 2){
			
			fprintf(fptr, "\n");
			
		}
	}
	
	fclose(fptr);
	
	//FILE *fptr2; //---> we can use fpr.. memory management
	fptr = fopen("answers.dat", "r");
	
	while(!feof(fptr)){
		
		numberOfCorrectAnswers = 0;
		
		fscanf(fptr, "%8s  %d %d %d %d", studentID, &answers[0], &answers[1], &answers[2], &answers[3]);
		
		if(answers[0] == 1){
			
			numberOfCorrectAnswers++;
			
		}
		
		if(answers[1] == 4){
			
			numberOfCorrectAnswers++;
			
		}
		
		if(answers[2] == 2){
			
			numberOfCorrectAnswers++;
			
		}
		
		if(answers[3] == 3){
			
			numberOfCorrectAnswers++;
			
		}
		
		printf("\nStident ID   Marks\n");
		printf("%s      %d\n", studentID, numberOfCorrectAnswers);
			
		
    }


	fclose(fptr);
	
	return 0;
}
