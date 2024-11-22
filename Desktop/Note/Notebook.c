#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "password.h"
#include "menu.h"
#include "openFile.h"
#include "AddNote.h"
#include "DeleteAdd.h"

int main()
{
    char* name=(char*)malloc(50*sizeof(char));
    int control=0;
    int choice;

    password();

    if(name == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }
    do{
        printf("Enter your name: ");
        fgets(name,50,stdin);

        if (name[strlen(name) - 1] == '\n') {
            name[strlen(name) - 1] = '\0';
           }
        control =1;
        for(int i = 0; name[i]!= '\0';i++){
            if(!isalpha(name[i])){
                control=0;
                printf("Characters only!\n");
                break;
            }
        }
        }while(control == 0);

        printf("\nWELCOME ");
        for(int i=0;name[i] != '\0';i++){
            printf("%c",toupper(name[i]));
        }
        printf("!\n");

    menu();

    do{
        printf("\nSelect a number in the menu:");
        scanf("%d",&choice);

        if(choice < 1 || choice > 4){
            printf("\nInvaid Value! Please, enter a number in the desired range.");
        }else{
            switch(choice){
                case 1: openFile();
                break;

                case 2: Addnote();
                break;

                case 3: DeleteAdd();
                break;

                case 4:
                      printf("Goodbye %s :)",name);
                      return 0;
                default:
                      printf("Please enter a value between 1-4");
    }
        }
        
           }while((choice != 4));
            free(name);

    return 0;
}

