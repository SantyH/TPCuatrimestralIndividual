//
// Created by Lucas on 9/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_ACCESSORY_H
#define TPCUATRIMESTRALINDIVIDUAL_ACCESSORY_H

#include "Product.h"

typedef struct Accessory{
    Product* product;
    char* type;
    char* comments;
}Accessory;

Accessory* createAccessory(char* name, char* code, double retailPrice, char* type, char* comments);
void showAccessory(Accessory *accessory);
void freeAccessory(Accessory* accessory);
#endif //TPCUATRIMESTRALINDIVIDUAL_ACCESSORY_H
