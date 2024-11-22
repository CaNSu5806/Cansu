#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAXWORD 20
#define MINWORD 3

int password()
{
    char code[MAXWORD];
    char value[MAXWORD];
    int attempts=3;

    printf("\nPlease, creat a password: ");

    int i=0;
    char temp;

    while((temp = getch()) != '\r'){
        if (temp == '\b'){
            if (i>0){
                i--;
                printf("\b \b"); // for erase the last '*'
            }
        }else if(i<MAXWORD-1){
        code[i++] = temp;
        printf("*");
        }
    
    code[i]='\0';
       
    }

    if (i < MINWORD) {
        printf("\nPassword must be at least %d characters long. Try again.\n", MINWORD);
        return password(); 
    }

    printf("\nPassword is ready!\n");

    while (attempts > 0){
        printf("\nEnter the password: ");
        i=0;
        while((temp=getch())!='\r'){
            if(temp == '\b'){
                if(i>0){
                    i--;
                    printf("\b \b");
                }
            }else if (i<MAXWORD-1){
                value[i++]=temp;
                printf("*");
            }
        }
    
         value[i]='\0';
         printf("\n");

        if(strcmp(code,value) == 0){
            printf("Password correct!\n Access granted.\n");
             break;
        }else{
            attempts-=1;
            if(attempts>0){
                printf("The password is not correct!\nYou have %d attemt(s) remaining.\n",attempts);
            }else{
                printf("\nToo many incorrect attempts.\nExiting program...\n\n");
            }
        
         }
    }
         return 0;
    
}
