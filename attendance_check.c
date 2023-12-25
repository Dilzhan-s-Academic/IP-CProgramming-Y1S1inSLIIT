#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char employeeNumber[10] ,empNo[10],empName[20];
    char attendance[8];
    int i,totalDaysWorked = 0;
    
    // Open the file for reading
    file = fopen("attendance.dat", "r");
    
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }
    
    // Input the employee number for which you want to calculate attendance
    printf("Enter employee number: ");
    scanf("%s", employeeNumber);
    
    // Search for the employee's record and calculate total days worked
    while (fscanf(file, "%s %s %i %i %i %i %i %i %i",empNo, empName , attendance[0], attendance[1], attendance[2], attendance[3], attendance[4], attendance[5], attendance[6]) != EOF) {
        if (strcmp(employeeNumber, empNo) == 0) {
            for ( i = 0; i < 7; i++) {
                totalDaysWorked += (attendance[i] == '1');
            }
            break; // Employee found, no need to continue reading the file
        }
    }
    
    // Close the file
    fclose(file);
    
    printf("Total days worked by employee %s: %d\n", empNo , totalDaysWorked);
    
    return 0;
}

