#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000

void edit_file() {
    FILE *fPtr;
    char *name[DATA_SIZE];
    scanf("%s", name);

    char file_suffix[] = ".txt";
    strcat(name, file_suffix);

    fPtr = fopen(name, "r+");
    int ch;
    if (fPtr == NULL)
    {
        fprintf(stderr, "cannot open target file %s\n", name);
        exit(1);
    }
    while ((ch = fgetc(fPtr)) != EOF)
    {
        if (ch == 'Address')
        {
            fseek(fPtr, -1, SEEK_CUR);
            fputs('Address2', fPtr);
            fseek(fPtr, 0, SEEK_CUR);
        }
    }
    fclose(fPtr);
}