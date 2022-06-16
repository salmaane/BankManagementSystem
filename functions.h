#include <stdio.h>
#include<stdlib.h>

#ifndef BANKMANAGEMENTSYSTEM_FUNCTIONS_H
#define BANKMANAGEMENTSYSTEM_FUNCTIONS_H


typedef struct customers{
    int no;
    char name[50];
    char birth_date[11];
    char adress[80];
    char citizenship_id[11];
    int sold;
    char phone_num[11];
    char username[25];
    char password[25];
}custs;


int menu();

void new_acc();

void edit();

void transact();

void see();

void delete();

void view_list();

custs *get_infos();

custs *login();

custs update(custs customer);

void deposit(custs *custo);

void soldout(custs *custo);



#endif //BANKMANAGEMENTSYSTEM_FUNCTIONS_H
