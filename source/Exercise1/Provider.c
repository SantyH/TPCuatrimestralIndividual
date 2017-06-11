//
// Created by Santiago Hazana on 6/7/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "Provider.h"

Provider* newProvider(char* name, char* description, char* direction, char* city, int phone, char* web){
    Provider* provider = malloc(sizeof(Provider));
    provider->name = name;
    provider->description = description;
    provider->direction = direction;
    provider->city = city;
    provider->phone = phone;
    provider->web = web;
    return provider;
}

HouseElectro * sellHouseElectro(StaticList* makerProducts, int id){
    for (int j = 0; j < makerProducts->size; ++j) {
        goTo(makerProducts, j);
        if(id == ((HouseElectro*)getActual(makerProducts))->id)
            return getActual(makerProducts);
    }
    printf("Product not in list");
}

void freeProvider(Provider* provider){
    free(provider->name);
    free(provider->description);
    free(provider->direction);
    free(provider->city);
    free(provider->web);
    free(provider);
}