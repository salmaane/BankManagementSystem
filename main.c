#include <stdio.h>
#include<stdlib.h>
#include"functions.h"


int main() {
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    int choice;

    do{
        choice = menu();
        switch(choice){
            case 1 :
                new_acc();
                break;
            case 2 :
                edit();
                break;
            case 3 :
                transact();
                break;
            case 4 :
                see();
                break;
            case 5 :
                delete();
                break;
            case 6 :
                view_list();
                break;
            default:
                break;
        }
    }while(choice != 7);

}
