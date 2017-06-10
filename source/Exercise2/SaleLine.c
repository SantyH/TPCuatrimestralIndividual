//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include "SaleLine.h"
#include "Camera.h"
#include "Accessory.h"

SaleLine* createSaleLine(){
    SaleLine* saleLine = malloc(sizeof(SaleLine));
    saleLine->cameras = createStaticList(3, sizeof(Camera));
    saleLine->accessories= createStaticList(3, sizeof(Accessory));

}
void showProducts(SaleLine* saleLine){
    for (int i = 0; i < saleLine->cameras->size; ++i) {
        goTo(saleLine->cameras,i);
        showCamera((Camera*)getActual(saleLine->cameras));
    }
    for (int j = 0; j < saleLine->accessories->size; ++j) {
        goTo(saleLine->accessories,j);
        showAccesory( (Accessory*)getActual(saleLine->accessories));
    }
}
void freeSaleLine(SaleLine* saleLine){
    for (int i = 0; i < saleLine->cameras->size; ++i) {
        goTo(saleLine->cameras,i);
        freeCamera((Camera*)getActual(saleLine->cameras));
    }
    for (int j = 0; j < saleLine->accessories->size; ++j) {
        goTo(saleLine->accessories,j);
        freeAccessory((Accessory*)getActual(saleLine->accessories));
    }
    free(saleLine);
}