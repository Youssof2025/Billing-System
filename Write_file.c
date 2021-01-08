#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 1000

//optional delay function
void delay2(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

//Writing the account for each customer
void write_file() {
    FILE *fPtr;
    char account_name[DATA_SIZE];
    printf("Enter Account Name: ");
    scanf("%s", account_name);
    while ((getchar()) != '\n');

    char file_suffix[] = ".txt";
    strcat(account_name, file_suffix); //adding a '.txt' at the end of each file
    fPtr = fopen(account_name, "w");

    if (fPtr == NULL) {
        printf("Operation Unsuccessful\n");
        exit(EXIT_FAILURE);
    }
    time_t s, val = 1;
    struct tm *current_time;
    s = time(NULL);
    current_time = localtime(&s);

    char Address[DATA_SIZE];
    printf("Enter Address: ");
    fgets(Address, DATA_SIZE, stdin);
    char prefix_address[] = "Address          : ";
    fputs(prefix_address, fPtr);
    fputs(Address, fPtr);

    char Phone_Num[DATA_SIZE];
    printf("Enter Phone Number: ");
    fgets(Phone_Num, DATA_SIZE, stdin);
    char prefix_phone[] = "Phone Number     : ";
    fputs(prefix_phone, fPtr);
    fputs(Phone_Num, fPtr);

    char Old_Balance[DATA_SIZE];
    printf("Enter Old Balance: ");
    fgets(Old_Balance, DATA_SIZE, stdin);
    float customer_old_balance = atoi(Old_Balance);
    char prefix_old_balance[] = "Current Balance  : ";
    fputs(prefix_old_balance, fPtr);
    fprintf(fPtr, "%.2f", customer_old_balance);
    fputs("\n", fPtr);

    char Amount_Needed[DATA_SIZE];
    printf("Enter Amount Needed: ");
    fgets(Amount_Needed, DATA_SIZE, stdin);
    float customer_needed = atoi(Amount_Needed);
    char prefix_needed[] = "Needed To Pay    : ";
    fputs(prefix_needed, fPtr);
    fprintf(fPtr, "%.2f", customer_needed);
    fputs("\n", fPtr);

    float customer_new_balance = customer_old_balance - customer_needed;
    char prefix_new_balance[] = "New Balance      : ";
    fputs(prefix_new_balance, fPtr);
    fprintf(fPtr, "%.2f", customer_new_balance);
    fputs("\n", fPtr);

    char prefix_over_due[] = "Overdue By       : ";
    if (customer_new_balance < 0) {
        fputs(prefix_over_due, fPtr);
        fprintf(fPtr, "%.2f\n", customer_new_balance + -customer_new_balance * 2);
    } else {
        fputs(prefix_over_due, fPtr);
        fputs("False\n", fPtr);
    }

    char prefix_date_paid[] = "Date Paid        : ";
    fputs(prefix_date_paid, fPtr);
    //Date
    fprintf(fPtr, "%02d.", current_time->tm_mday);
    fprintf(fPtr, "%02d.", current_time->tm_mon + 1);
    fprintf(fPtr, "%02d ", current_time->tm_year + 1900);
    //Time
    fprintf(fPtr, "%02d:", current_time->tm_hour);
    fprintf(fPtr, "%02d\n\n", current_time->tm_min);

    customer_old_balance = customer_new_balance;

    printf("Writing File...\n");
    delay2(1100); //Added as to now overwhelm the user

    fclose(fPtr);

    printf("Operation Successful\n");
}