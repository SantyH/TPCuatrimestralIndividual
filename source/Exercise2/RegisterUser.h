//
// Created by Lucas on 9/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_REGISTERUSER_H
#define TPCUATRIMESTRALINDIVIDUAL_REGISTERUSER_H

#include "../Structs/StaticList.h"
#include "PersonShop.h"
#include "Product.h"

typedef struct RegisterUser{
    PersonShop* personShop;
    StaticList* sales;
    double wallet;
}RegisterUser;

RegisterUser* createRegisterUser(char* name, int dni, char* address, int phone, char* location, char* province, char* country,char* postCode);
void buyProduct(RegisterUser* registerUser, char* code, StaticList* accessories, StaticList* cameras);
void increaseWallet(RegisterUser* registerUser, double amount);
void* freeRegisterUser(RegisterUser* registerUser);

#endif //TPCUATRIMESTRALINDIVIDUAL_REGISTERUSER_H
