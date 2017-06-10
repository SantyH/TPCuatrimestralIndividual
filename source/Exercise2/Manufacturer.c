//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include <memory.h>
#include "Manufacturer.h"

Manufacturer* createManufacturer(char* name, Product* productSample){
    Manufacturer* manufacturer = malloc(sizeof(Manufacturer));
    manufacturer->name=name;
    manufacturer->productSample = productSample;
    manufacturer->productCode= productSample->code;

    return manufacturer;
}

void makeProducts(Manufacturer* manufacturer,StaticList* products,char* productCode,int quantity){
    if(strcmp(productCode,manufacturer->productCode) ==0 ) {
        for (int i = 0; i < products->size; ++i) {
            goTo(products, i);
            Product *result = createProduct(manufacturer->productSample->name, manufacturer->productCode,
                                            manufacturer->productSample->retailPrice);
            addNext(products, result);
        }
    }
}

void freeManufacurer(Manufacturer* manufacturer){
    freeProduct(manufacturer->productSample);

}