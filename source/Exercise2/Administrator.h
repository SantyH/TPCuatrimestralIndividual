//
// Created by Lucas on 9/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_ADMINISTRATOR_H
#define TPCUATRIMESTRALINDIVIDUAL_ADMINISTRATOR_H


#include "PersonShop.h"
#include "../Structs/StaticList.h"
#include "Provider.h"

typedef struct Administrator{
    PersonShop* personShop;
}Administrator;

Administrator* createAdministrator(char* name, int dni, char* address, int phone, char* location, char* province, char* country, char* postCode);
StaticList* callProvider(Provider* provider,char* code, int quantity);
void freeAdministrator(Administrator* administrator);

#endif //TPCUATRIMESTRALINDIVIDUAL_ADMINISTRATOR_H
