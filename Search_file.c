#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 1000

//optional delay function
void delay(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void search() {
    FILE *fPtr;

    printf("Enter Name: ");
    char account_name[DATA_SIZE];
    scanf("%s", account_name);
    while ((getchar()) != '\n');

    printf("\nSearching File...\n");
    delay(1100); //Made as to not overwhelm the user
    printf("========================================\n\n");

    char suffix[] = ".txt";
    strcat(account_name, suffix);
    fPtr = fopen(account_name, "r");
    
    char c;
    c = fgetc(fPtr);
    while (c != EOF) { //Go through the entire file and display everything
        printf("%c", c);
        c = fgetc(fPtr);
    }

    printf("========================================\n");
    fclose(fPtr);
}