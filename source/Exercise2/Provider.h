//
// Created by Lucas on 9/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_PROVIDER_H
#define TPCUATRIMESTRALINDIVIDUAL_PROVIDER_H

#include "PersonShop.h"
#include "../Structs/StaticList.h"
#include "Manufacturer.h"

typedef struct Provider{
    PersonShop* personShop;
    double wallet;
    StaticList* manufacturers;
}Provider;

Provider* createProvider(char* name, int dni, char* address, int phone, char* location, char* province, char* country,char* postCode);
StaticList* contactManufacturer(Provider* provider,char* code, int quantity);
void freeProvider(Provider* provider);

#endif //TPCUATRIMESTRALINDIVIDUAL_PROVIDER_H
