/* 
Customer Billing System
By: Yusseff2030
Last updates: 26/12/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Write_file.c"
#include "Search_file.c"

#define DATA_SIZE 1000

void output() {
        char option;
        printf("\n\tCUSTOMER BILLING SYSTEM\t\n");
        printf("========================================\n");
        printf("[1]:   To Add Customer Account\n");
        printf("[2]:   To Search Customer Account\n");
        printf("[3]:   Exit\n");
        printf("========================================\n");
        printf("Select What You Want To Do?\n\n");

        do {
            scanf("%c", &option);
        } while (option <= '0' || option > '4');
        switch (option) {
        case '1':
            write_file();
            break;
        case '2':
            search();
            break;
        case '3':
            printf("Bye...\n");
            exit(EXIT_FAILURE);
        }
}

int main() {
    char y_n;
    do {
    output();
    printf("\nContinue?(y/n)\n");
    scanf("%c", &y_n);
    system("clear");
    } while (strcmp(&y_n, "n") != 0);

    return 0;
}