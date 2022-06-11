#include <stdio.h>
#include<stdlib.h>
#include"functions.h"



int main() {
    int choice;
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    choice = menu();
    switch(choice){
        case 1 :
//            new_acc();
            break;
        case 2 :
//            edit();
            break;
        case 3 :
//            transact();
            break;
        case 4 :
//            see();
            break;
        case 5 :
//            delete();
            break;
        case 6 :
//            view_list();
            break;
        default:
            return 0;
    }



}
