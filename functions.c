#include "functions.h"



int menu(){
    int choice;
    do{
        printf("\n\n\t\t\t\t   ----- WELCOME TO THE MAIN MENU -----");
        printf("\n1. Create new account\n2. Update informations of existing account"
               "\n3. Do a transaction\n4. Check the details of existing account"
               "\n5. Removing existing account\n6. View custumer's list\n7. Exit\n\n\tEnter your choice :_");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice < 1 || choice > 7){
            printf("\nEnter a valid choice from the menu.");
        }
    }while(choice < 1 || choice > 7);
    return choice;
}




custs get_infos(){
    custs customer;

    printf("\nEnter your name :_");
    scanf("%[^\n]s", customer.name);
    fflush(stdin);

    printf("\nEnter your date of birth :_");
    scanf("%s", customer.birth_date);
    fflush(stdin);

    printf("\nEnter your adress :_");
    scanf("%[^\n]s", customer.adress);
    fflush(stdin);

    printf("\nEnter your citizenship id :_");
    scanf("%s", customer.citizenship_id);
    fflush(stdin);

    printf("\nEnter your phone number :_");
    scanf("%s",customer.phone_num);
    fflush(stdin);

    printf("\nHow mush sold you want deposit to create your account :_");
    scanf("%d",&customer.sold);
    fflush(stdin);

    printf("\nChoose a username :_");
    scanf("%s", customer.username); // still have to check if username already exist.
    fflush(stdin);

    printf("\nchoose a strong password :_");
    scanf("%s[^\n]", customer.password);
    fflush(stdin);

    return customer;
}




void new_acc(){
    unsigned long long no,curr;
    custs customer = get_infos();
    FILE *f;
    f = fopen("custlist.txt","a");

    curr = ftell(f);
    fseek(f,0,SEEK_END);
    no = (ftell(f)/sizeof(custs)) + 1;
    fseek(f,(int)curr,SEEK_SET);

    customer.no = (int)no;
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
    custs customer;
    FILE *f = fopen("custlist.txt","r");
    if(f == NULL){
        printf("File doesn't exist.");
    }else{
        while(fread(&customer,sizeof(custs),1,f)){
            printf("\nCUSTOMER %d -->  Name : %s\n\t\tBirth date : %s\n\t\tPhone number : %s"
                   "\n\t\tCitizenship id : %s\n\t\tAdress : %s\n\t\tSold : %d"
                   ,customer.no,customer.name,customer.birth_date,customer.phone_num,customer.citizenship_id
                   ,customer.adress,customer.sold);
        }
        fclose(f);
    }
}
