#include "functions.h"
#include<string.h>


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



custs *login(){
    int found=0;
    custs *customer;
    customer = (custs*)malloc(sizeof(custs));
    char user[24],pass[24];

    printf("\nEnter Your username :_");
    scanf("%s",user);
    fflush(stdin);

    printf("Enter your password :_");
    scanf("%s",pass);
    fflush(stdin);

    FILE *fp = fopen("custlist.txt","r");
    while(fread(customer,sizeof(custs),1,fp)){
        if(strcmp(customer->username,user)==0 && strcmp(customer->password,pass)==0){
            found = 1;
            break;
        }
        customer = NULL;
    }
    fclose(fp);
    if(!found){
        printf("\nUsername or password are incorrect account not found.");
    }
    return customer;
}



custs update(custs customer){
    short ch;
    do{
        printf("\nWhat information you wand to update :\n1. Name\n2. Birth date"
               "\n3. Adress\n4. Citizenship id\n5. Phone number\n6. Username\n7. Paswword"
               "\n0. Save changes\n\tChoice :_");
        scanf("%hd",&ch);
        fflush(stdin);
        switch(ch) {
            case 1:
                printf("\nEnter new Name :_");
                scanf("%s",customer.name);
                fflush(stdin);
                printf("Name changed.");
                break;
            case 2:
                printf("\nEnter new Birth date :_");
                scanf("%s",customer.birth_date);
                fflush(stdin);
                printf("Birth date changed.");
                break;
            case 3:
                printf("\nEnter new Adress :_");
                scanf("%s",customer.adress);
                fflush(stdin);
                printf("Adress changed.");
                break;
            case 4:
                printf("\nEnter new Citizenship id :_");
                scanf("%s",customer.citizenship_id);
                fflush(stdin);
                printf("Citizenship id changed.");
            case 5:
                printf("\nEnter new Phone number :_");
                scanf("%s",customer.phone_num);
                fflush(stdin);
                printf("Phone number changed.");
                break;
            case 6:
                printf("\nEnter new username :_");
                scanf("%s",customer.username);
                fflush(stdin);
                printf("username changed.");
                break;
            case 7:
                printf("\nEnter new Password :_");
                scanf("%s",customer.password);
                fflush(stdin);
                printf("Password changed.");
                break;
            default :
                break;
        }
    }while(ch!=0);
    return customer;
}



void new_acc(){
    unsigned long long no,curr;
    custs customer = get_infos();
    FILE *f;
    f = fopen("custlist.txt","ab");

    curr = ftell(f);
    fseek(f,0,SEEK_END);
    no = (ftell(f)/sizeof(custs)) + 1;
    fseek(f,(int)curr,SEEK_SET);

    customer.no = (int)no;
    fwrite(&customer,sizeof(custs),1,f);
    fclose(f);
    printf("\nAccount created successfuly.");
}


void edit(){
    custs *customer =login();
    if(customer!=NULL){
        *customer = update(*customer);
    }
}


void transact(){

}

void see(){

}


void delete(){

}


void view_list(){
    custs customer;
    int pin;;
    printf("\nAdministrator PIN :_");
    scanf("%d",&pin);
    if(pin != 123){
        printf("PIN incorrect.");
    }else{
        FILE *f = fopen("custlist.txt","rb");
        if(f == NULL){
            printf("\nFile doesn't exist.");
        }else{
            while(fread(&customer,sizeof(custs),1,f)){
                printf("\n\nCUSTOMER %d -->  Name : %s\n\t\tBirth date : %s\n\t\tPhone number : %s"
                       "\n\t\tCitizenship id : %s\n\t\tAdress : %s\n\t\tSold : %d\n\t\tusername : %s\n\t\tpassword : %s"
                       ,customer.no,customer.name,customer.birth_date,customer.phone_num,customer.citizenship_id
                       ,customer.adress,customer.sold,customer.username,customer.password);
            }
            fclose(f);
        }
    }
}
