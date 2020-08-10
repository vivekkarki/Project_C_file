#include <stdio.h>
#include <stdlib.h>

int FileCom(FILE * fptr1, FILE * fptr2);

int main()
{
    FILE * fptr1; 
    FILE * fptr2;
    char file1[100];
    char file2[100];

    int flag;
    //int line, col;


    printf(" Enter Program Output File Name \n");
    scanf("%s", file1);
    printf("Enter file name to compare \n");
    scanf("%s", file2);

    fptr1 = fopen(file1, "r");
    fptr2 = fopen(file2, "r");

    if (fptr1 == NULL || fptr2 == NULL)
    {
        printf("\nCannot  open file.\n");
        exit(EXIT_FAILURE);
    }


    flag = FileCom(fptr1, fptr2);



    if (flag == 0)
    {
        printf("\nPASS: ");
    }
    else 
    {
        printf("\nFAIL:\n");
       
    }

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}

int FileCom(FILE * fptr1, FILE * fptr2)
{
    char ch1, ch2;
    do
    {
        ch1 = fgetc(fptr1);
        ch2 = fgetc(fptr2);
       
        if (ch1 != ch2)
            return -1;
    } while (ch1 != EOF && ch2 != EOF);
    if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;
}