#include <stdlib.h>
#include <stdio.h>

int openFile()
{
    FILE* fptr;

    fptr=fopen("C:\\Users\\Asus\\Desktop\\Note\\MyNote.txt","r");

    if (fptr==NULL){
        printf("File could not be opened");
        return -1;
    }

    char line[256];

    printf("Here is the file content:\n\n");
    while(fgets(line,sizeof(line),fptr)!=NULL){
        printf("%s",line);
    }
    fclose(fptr);
    return 0;
}