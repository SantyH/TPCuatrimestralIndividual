//
// Created by Santiago Hazana on 6/7/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_HOUSEELECTRO_H
#define TPCUATRIMESTRALINDIVIDUAL_HOUSEELECTRO_H

#include "Label.h"

typedef struct HouseElectro HouseElectro;

struct HouseElectro{
    int id;
    char* name;
    char* model;
    double price;
    Label* label;
};

HouseElectro* newElectro(int id, char* name, char* model, double price);
void changePrice(HouseElectro* electro, double newPrice);
void freeElectro(HouseElectro* electro);

#endif //TPCUATRIMESTRALINDIVIDUAL_HOUSEELECTRO_H
