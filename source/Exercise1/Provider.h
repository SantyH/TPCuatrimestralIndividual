//
// Created by Santiago Hazana on 6/7/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_PROVIDER_H
#define TPCUATRIMESTRALINDIVIDUAL_PROVIDER_H

#include "HouseElectro.h"
#include "../Structs/StaticList.h"

typedef struct Provider Provider;

struct Provider{
    char* name;
    char* description;
    char* direction;
    char* city;
    int phone;
    char* web;
};

Provider* newProvider(char* name, char* description, char* direction, char* city, int phone, char* web);
HouseElectro* sellHouseElectro(StaticList* makerProducts, int id);
void freeProvider(Provider* provider);

#endif //TPCUATRIMESTRALINDIVIDUAL_PROVIDER_H
