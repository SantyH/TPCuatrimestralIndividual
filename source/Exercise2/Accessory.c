//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include <stdio.h>
#include <memory.h>
#include "Accessory.h"

Accessory* createAccessory(char* name, char* code, double retailPrice, char* type, char* comments){
    Accessory* accessory = malloc(sizeof(Accessory));

    accessory->product=createProduct(name,strcat("A-",code),retailPrice);
    accessory->type=type;
    accessory->comments;

    return accessory;
}

void showAccesory(Accessory* accessory){
    showInformation(accessory->product);
    printf("%s%s\n %s%s\n","Comments: ", accessory->comments,"Type: ", accessory->type);
}

void freeAccessory(Accessory* accessory){
    freeProduct(accessory->product);
    free(accessory);
}