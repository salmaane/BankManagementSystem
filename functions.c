//
// Created by Salmane on 6/11/2022.
//

#include "functions.h"


int menu(){
    int choice;
    do{
        printf("\n\n\t\t\t\t   ----- WELCOME TO THE MAIN MENU -----");
        printf("\n1. Create new account\n2. Update informations of existing account"
               "\n3. Do a transaction\n4. Check the details of existing account"
               "\n5. Removing existing account\n6. View custumer's list\n7. Exit\n\n\tEnter your choice :_");
        scanf("%d",&choice);
        if(choice < 1 || choice > 7){
            printf("\nEnter a valid choice from the menu.");
        }
    }while(choice < 1 || choice > 7);
    return choice;
}