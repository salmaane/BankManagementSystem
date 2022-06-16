#include "functions.h"
#include<string.h>


int menu(){
    int choice;
    do{
        printf("\n\n\t\t\t\t   ----- WELCOME TO THE MAIN MENU -----");
        printf("\n1. Create new account\n2. Update informations of existing account"
               "\n3. Do a transaction\n4. Check the details of existing account"
               "\n5. Removing existing account\n6. View custumer's list(Administrator)\n7. Exit\n\n\tEnter your choice :_");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice < 1 || choice > 7){
            printf("\nEnter a valid choice from the menu.");
        }
    }while(choice < 1 || choice > 7);
    return choice;
}


custs *get_infos(){
    custs *customer = (custs*)malloc(sizeof(custs));

    printf("\nEnter your name :_");
    scanf("%[^\n]s", customer->name);
    fflush(stdin);

    printf("\nEnter your date of birth :_");
    scanf("%10s", customer->birth_date);
    fflush(stdin);

    printf("\nEnter your adress :_");
    scanf("%[^\n]s", customer->adress);
    fflush(stdin);

    printf("\nEnter your citizenship id :_");
    scanf("%10s", customer->citizenship_id);
    fflush(stdin);

    printf("\nEnter your phone number :_");
    scanf("%10s",customer->phone_num);
    fflush(stdin);

    printf("\nHow mush sold you want deposit to create your account :_");
    scanf("%d",&customer->sold);
    fflush(stdin);

    printf("\nChoose a username :_");
    scanf("%s", customer->username); // still have to check if username already exist.
    fflush(stdin);

    printf("\nchoose a strong password :_");
    scanf("%s[^\n]", customer->password);
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

    FILE *fp = fopen("custlist.txt","rb");
    rewind(fp);
    while(fread(customer,sizeof(custs),1,fp)){
        if(strcmp(customer->username,user)==0 && strcmp(customer->password,pass)==0){
            found = 1;
            break;
        }
    }
    fclose(fp);
    if(!found){
        printf("\nUsername or password are incorrect account not found.");
        customer = NULL;
    }
    return customer;
}


custs update(custs customer){
    short ch;
    do{
        printf("\nWhat information you want to update :\n1. Name\n2. Birth date"
               "\n3. Adress\n4. Citizenship id\n5. Phone number\n6. Username\n7. Paswword"
               "\n0. Save changes\n\tChoice :_");
        scanf("%hd",&ch);
        fflush(stdin);
        switch(ch) {
            case 1:
                printf("\nEnter new Name :_");
                scanf("%[^\n]s",customer.name);
                fflush(stdin);
                printf("Name changed.");
                break;
            case 2:
                printf("\nEnter new Birth date :_");
                scanf("%10s",customer.birth_date);
                fflush(stdin);
                printf("Birth date changed.");
                break;
            case 3:
                printf("\nEnter new Adress :_");
                scanf("%[^\n]s",customer.adress);
                fflush(stdin);
                printf("Adress changed.");
                break;
            case 4:
                printf("\nEnter new Citizenship id :_");
                scanf("%10s",customer.citizenship_id);
                fflush(stdin);
                printf("Citizenship id changed.");
                break;
            case 5:
                printf("\nEnter new Phone number :_");
                scanf("%10s",customer.phone_num);
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
                scanf("%[^\n]s",customer.password);
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
    custs *customer = get_infos();
    FILE *f;
    f = fopen("custlist.txt","ab");

    curr = ftell(f);
    fseek(f,0,SEEK_END);
    no = (ftell(f)/sizeof(custs)) + 1;
    fseek(f,(int)curr,SEEK_SET);

    customer->no = (int)no;
    fwrite(customer,sizeof(custs),1,f);
    fclose(f);
    printf("\nAccount created successfuly.");
}


void edit(){
    custs *customer =login();
    if(customer!=NULL){
        *customer = update(*customer);

        FILE *fp = fopen("custlist.txt","rb");

        fseek(fp,0,SEEK_END);
        int i=0,size = (int)(ftell(fp)/sizeof(custs));
        rewind(fp);

        custs *customers=(custs*)malloc(size*sizeof(custs));
        while(fread(&customers[i],sizeof(custs),1,fp)){
            i++;
        }
        fclose(fp);

        FILE *f = fopen("custlist.txt","w");
        customers[customer->no-1] = *customer;
        for(i=0;i<size;i++){
            fwrite(&customers[i],sizeof(custs),1,fp);
        }
        printf("\nChanges saved.");
        fclose(f);
        free(customers);
        customers = NULL;
    }
}


void transact(){
    custs *customer = login();
    if(customer != NULL){
        int ch;
        printf("\nWhat operation you want to do :\n1. Deposit\n2. soldout\n0. exit\n\tChoice :_");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                deposit(customer);
                break;
            case 2:
                soldout(customer);
                break;
            default:
                break;
        }

    }

}


void deposit(custs *custo){
    FILE *fp = fopen("custlist.txt","rb");

    fseek(fp,0,SEEK_END);
    int i=0,size = (int)(ftell(fp)/sizeof(custs));
    rewind(fp);

    custs *customers=(custs*)malloc(size*sizeof(custs));
    while(fread(&customers[i],sizeof(custs),1,fp)){
        i++;
    }
    fclose(fp);

    int transact;
    printf("\n How mush sold you want to deposit :_");
    scanf("%d",&transact);
    fflush(stdin);

    custo->sold += transact;
    customers[custo->no-1] = *custo ;

    FILE *f = fopen("custlist.txt","w");
    for(i=0;i<size;i++){
        fwrite(&customers[i],sizeof(custs),1,fp);
    }
    printf("\nOperation done.");
    fclose(f);
    free(customers);
    customers = NULL;

}


void soldout(custs *custo){
    FILE *fp = fopen("custlist.txt","rb");

    fseek(fp,0,SEEK_END);
    int i=0,size = (int)(ftell(fp)/sizeof(custs));
    rewind(fp);

    custs *customers=(custs*)malloc(size*sizeof(custs));
    while(fread(&customers[i],sizeof(custs),1,fp)){
        i++;
    }
    fclose(fp);

    int transact;
    printf("\n How mush sold you want to out :_");
    scanf("%d",&transact);
    fflush(stdin);

    if(transact > custo->sold){
        printf("\nOeration failed. You have only %d in your account .",custo->sold);
    }else{
        custo->sold = custo->sold - transact;
        customers[custo->no - 1] = *custo ;

        FILE *f = fopen("custlist.txt","w");
        for(i=0;i<size;i++){
            fwrite(&customers[i],sizeof(custs),1,fp);
        }
        printf("\nOperation done.");
        fclose(f);
        free(customers);
        customers = NULL;
    }
}


void see(){
    custs *customer= login();
    if(customer!=NULL){
        printf("\n\tName : %s\n\tBirth date : %s\n\tPhone number : %s"
               "\n\tCitizenship id : %s\n\tAdress : %s\n\tSold : %ddh"
                ,customer->name,customer->birth_date,customer->phone_num,customer->citizenship_id
                ,customer->adress,customer->sold);
    }
}


void delete(){
    custs *customer =login();
    if(customer!=NULL){
        FILE *fp = fopen("custlist.txt","rb");

        fseek(fp,0,SEEK_END);
        int i=0,j,size = (int)(ftell(fp)/sizeof(custs));
        rewind(fp);

        custs *customers=(custs*)malloc(size*sizeof(custs));
        while(fread(&customers[i],sizeof(custs),1,fp)){
            i++;
        }
        fclose(fp);


        FILE *f = fopen("custlist.txt","w");
        for(i=0;i<size;i++){
            if(strcmp(customers[i].name,customer->name) == 0){
                j = i;
                while(j<size){
                    customers[j].no = customers[j].no - 1;
                    j++;
                }
                continue;
            }
            fwrite(&customers[i],sizeof(custs),1,fp);
        }
        printf("\nAccount deleted.");
        fclose(f);
        free(customers);
        customers = NULL;
    }
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
                       "\n\t\tCitizenship id : %s\n\t\tAdress : %s\n\t\tSold : %ddh\n\t\tusername : %s\n\t\tpassword : %s"
                       ,customer.no,customer.name,customer.birth_date,customer.phone_num,customer.citizenship_id
                       ,customer.adress,customer.sold,customer.username,customer.password);
            }
            fclose(f);
        }
    }
}
