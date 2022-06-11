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




customers get_infos(){
    customer[count].no = count+1;

    printf("\nEnter your name :_");
    scanf("%s",customer[count].name);

    printf("\nEnter your date of birth :_");
    scanf("%s",customer[count].birth_date);

    printf("\nEnter your adress :_");
    scanf("%s",customer[count].adress);

    printf("\nEnter your citizenship id :_");
    scanf("%d",&customer[count].citizenship_id);

    printf("\nEnter your phone number :_");
    scanf("%d",&customer[count].phone_num);

    printf("\nHow mush sold you want deposit to create your account :_");
    scanf("%d",&customer[count].sold);

    printf("\nChoose a username :_");
    scanf("%s",customer[count].username); // still have to check if username already exist.

    printf("\nchoose a strong password :_");
    scanf("%s",customer[count].password);

    return customer[count];
}




void new_acc(){
    if(count == size){
        size +=5;
        customer = (customers*)realloc(customer,size*sizeof(customers));
    }


}
