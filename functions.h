#include <stdio.h>
#include<stdlib.h>

#ifndef BANKMANAGEMENTSYSTEM_FUNCTIONS_H
#define BANKMANAGEMENTSYSTEM_FUNCTIONS_H


typedef struct customers{
    int no;
    char name[50];
    char birth_date[10];
    char adress[80];
    char citizenship_id[10];
    int phone_num;
    int sold;
    char username[24];
    char password[24];
}custs;


int menu();

void new_acc();

void edit();

void transact();

void see();

void delete();

void view_list();

custs get_infos();



#endif //BANKMANAGEMENTSYSTEM_FUNCTIONS_H
