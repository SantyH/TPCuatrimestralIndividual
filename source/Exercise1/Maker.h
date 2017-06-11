//
// Created by Santiago Hazana on 6/7/17.
//

#include "HouseElectro.h"

#ifndef TPCUATRIMESTRALINDIVIDUAL_MAKER_H
#define TPCUATRIMESTRALINDIVIDUAL_MAKER_H

typedef struct Maker Maker;

struct Maker{
    char* name;
    char* description;
    char* direction;
    char* city;
    int phone;
    char* web;
};

Maker* newMaker(char* name, char* description, char* direction, char* city, int phone, char* web);
HouseElectro* makeHouseElectro(int id, char* name, char* model);
void freeMaker(Maker* maker);

#endif //TPCUATRIMESTRALINDIVIDUAL_MAKER_H
