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




custs get_infos(){
    custs customer;

    printf("\nEnter your name :_");
    scanf("%s", customer.name);
    fflush(stdin);

    printf("\nEnter your date of birth :_");
    scanf("%s", customer.birth_date);
    fflush(stdin);

    printf("\nEnter your adress :_");
    scanf("%s", customer.adress);
    fflush(stdin);

    printf("\nEnter your citizenship id :_");
    scanf("%s", customer.citizenship_id);
    fflush(stdin);

    printf("\nEnter your phone number :_");
    scanf("%d",&customer.phone_num);
    fflush(stdin);

    printf("\nHow mush sold you want deposit to create your account :_");
    scanf("%d",&customer.sold);
    fflush(stdin);

    printf("\nChoose a username :_");
    scanf("%s", customer.username); // still have to check if username already exist.
    fflush(stdin);

    printf("\nchoose a strong password :_");
    scanf("%s", customer.password);
    fflush(stdin);

    return customer;
}




void new_acc(){
    custs customer = get_infos();
    FILE *f;
    f = fopen("custlist.txt","a");
    fwrite(&customer,sizeof(custs),1,f);
    fclose(f);
}


void edit(){

}


void transact(){

}

void see(){

}


void delete(){

}


void view_list(){

}
