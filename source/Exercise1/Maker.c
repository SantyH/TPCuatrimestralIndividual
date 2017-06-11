//
// Created by Santiago Hazana on 6/7/17.
//

#include <malloc.h>
#include "Maker.h"

Maker* newMaker(char* name, char* description, char* direction, char* city, int phone, char* web){
    Maker* maker = malloc(sizeof(Maker));
    maker->name = name;
    maker->description = description;
    maker->direction = direction;
    maker->city = city;
    maker->phone = phone;
    maker->web = web;
    return maker;
}

HouseElectro* makeHouseElectro(int id, char* name, char* model){
    HouseElectro* houseElectro = newElectro(id, name, model, 0);
    return houseElectro;
}

void freeMaker(Maker* maker){
    free(maker->city);
    free(maker->description);
    free(maker->direction);
    free(maker->name);
    free(maker->web);
    free(maker);
}