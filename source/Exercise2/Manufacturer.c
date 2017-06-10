//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include "Manufacturer.h"


Manufacturer* createManufacturer(char* name, Camera* cameraSample, Accessory* accessorySample){
    Manufacturer* manufacturer = malloc(sizeof(Manufacturer));
    manufacturer->name=name;
    manufacturer->cameraSample = cameraSample;
    manufacturer->accessorySample = accessorySample;

    return manufacturer;
}

void makeProducts(Manufacturer* manufacturer,StaticList* products,char* productCode,int quantity){
    goBack(products);
    printf("%s\n",manufacturer->name);
    if(strcmp(productCode,manufacturer->cameraSample->product->code) ==0 ) {
        for (int i = 0; i < quantity; ++i) {
            goTo(products, i);
            addNext(products, createCamera(manufacturer->cameraSample->product->name,
                                           manufacturer->cameraSample->product->code,
                                           manufacturer->cameraSample->product->retailPrice,
                                           manufacturer->cameraSample->megapixels,
                                           manufacturer->cameraSample->LCDScreen,
                                           manufacturer->cameraSample->opticalZoom,
                                           manufacturer->cameraSample->type));
        }
    } else if(strcmp(productCode,manufacturer->accessorySample->product->code) ==0 ){
        for (int i = 0; i < quantity; ++i) {
            goTo(products, i);
            addNext(products, createAccessory(manufacturer->accessorySample->product->name,
                                           manufacturer->accessorySample->product->code,
                                           manufacturer->accessorySample->product->retailPrice,
                                           manufacturer->accessorySample->type,
                                              manufacturer->accessorySample->comments));
        }
    } else{
        printf("%s\n","Code no match with any product!");
    }
}

void freeManufacurer(Manufacturer* manufacturer){
    freeCamera(manufacturer->cameraSample);
    freeAccessory(manufacturer->accessorySample);
    free(manufacturer);

}