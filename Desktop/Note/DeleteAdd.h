#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int DeleteAdd()
{
    char* message=(char*)malloc(500*sizeof(char));
    if (message == NULL){
        printf("Memory allocation failed.\n");
        return -1;
    }
    FILE* fptr;
    fptr=fopen("C:\\Users\\Asus\\Desktop\\Note\\MyNote.txt","w");
    if(fptr == NULL ){
        printf("File could not be opened.\n");
        free(message);
        return -1;
    }
    printf("Enter your note line by line. Type 'END' to finish:\n");

    while(1) {
        printf("\n> ");
        fgets(message,256,stdin);

        if(strncmp(message,"END",3) == 0 && strlen(message) == 4){
            break;
        }
        fprintf(fptr, "%s", message);
    }

    fclose(fptr);
    free(message);

    printf("\nYour note has been saved successfully");

    return 0;

}