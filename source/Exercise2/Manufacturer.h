//
// Created by Lucas on 9/6/2017.
//

#include "../Structs/StaticList.h"
#include "Product.h"

#ifndef TPCUATRIMESTRALINDIVIDUAL_MANUFACTURER_H
#define TPCUATRIMESTRALINDIVIDUAL_MANUFACTURER_H
typedef struct Manufacturer{
    char* name;
    char* productCode;
    Product* productSample;
}Manufacturer;

Manufacturer* createManufacturer(char* name, Product* productSample);
void makeProducts(Manufacturer* manufacturer, StaticList* products, char* productCode, int quantity);
void freeManufacurer(Manufacturer* manufacturer);
#endif //TPCUATRIMESTRALINDIVIDUAL_MANUFACTURER_H
