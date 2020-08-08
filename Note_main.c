#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2000

int main()
{
    char data[SIZE];
    char fname[128];
    FILE * fPtr;

    printf("Enter text file name\n"); 
    scanf("%s",fname);
    strcat(fname,".txt");
    fPtr = fopen(fname, "w");
    
    if(fPtr == NULL) 
       {
        printf("Can't create file.\n");
        exit(EXIT_FAILURE);
       }

    
    printf("To End  Writing on  File  Press Ctrl + D \n");
    printf("Write From Here : \n");
    
    while(1){
    	
    fgets(data, SIZE, stdin);
    
    if(feof(stdin))
    {
      break;
    }
    
    fputs(data, fPtr);
  } 

    fclose(fPtr);
    printf("***File created and saved successfully*** \n");
    return 0;
}