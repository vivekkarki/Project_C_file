#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2000

int main()
{
    char data[SIZE];
    char fname[5];
    FILE * fPtr;
    char *ch;
    char c;
    printf("Enter text file name\n"); 
    scanf("%5s",fname);
    strcat(fname,".txt");
    fPtr = fopen(fname, "w");
    
    if(fPtr == NULL) 
       {
        printf("Can't create file.\n");
        exit(EXIT_FAILURE);
       }
    while ((c = getchar()) != '\n' && c != EOF)
            continue;
    
    printf("PRESS :wq to save and exit \n");
    printf("Write From Here : \n");
    
    while(1){
    	
    fgets(data, SIZE, stdin);
    ch = data;
    while(*ch != '\n' &&  *ch != '\0') {
        ++ch;
        }
      if (*ch) {
        *ch = '\0';
        } 
	  else {        
        while ((c = getchar()) != '\n' && c != EOF)
            continue;
        }
    
   if (strcmp(data, ":wq") == 0)
        {
            break;
        }
    fputs(data,fPtr);
    fputs("\n", fPtr);
    
  } 

    fclose(fPtr);
    printf("***File created and saved successfully*** \n");
    return 0;
}
