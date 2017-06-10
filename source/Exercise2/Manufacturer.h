//
// Created by Lucas on 9/6/2017.
//

#include "../Structs/StaticList.h"
#include "Product.h"
#include "Camera.h"
#include "Accessory.h"

#ifndef TPCUATRIMESTRALINDIVIDUAL_MANUFACTURER_H
#define TPCUATRIMESTRALINDIVIDUAL_MANUFACTURER_H
typedef struct Manufacturer{
    char* name;
    char* code;
    Camera* cameraSample;
    Accessory* accessorySample;
}Manufacturer;

Manufacturer* createManufacturer(char* name, Camera* cameraSample, Accessory* accessorySample);
void makeProducts(Manufacturer* manufacturer, StaticList* products, char* productCode, int quantity);
void freeManufacurer(Manufacturer* manufacturer);
#endif //TPCUATRIMESTRALINDIVIDUAL_MANUFACTURER_H
