//
// Created by Santiago Hazana on 6/7/17.
//

#include "HouseElectro.h"

HouseElectro* newElectro(int id, char* name, char* model, double price){
    HouseElectro* houseElectro = malloc(sizeof(HouseElectro));
    houseElectro->id = id;
    houseElectro->name = name;
    houseElectro->model = model;
    houseElectro->price = price;
    houseElectro->label = newLabel(id, name);
    return houseElectro;
}

void changePrice(HouseElectro* electro, double newPrice){
    electro->price = newPrice;
}

void freeElectro(HouseElectro* electro){
    free(electro->model);
    free(electro->name);
    freeLabel(electro->label);
    free(electro);
}