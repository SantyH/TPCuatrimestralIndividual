//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include <memory.h>
#include "Provider.h"

Provider* createProvider(char* name, int dni, char* address, int phone, char* location, char* province, char* country,char* postCode){
    Provider* provider = malloc(sizeof(Provider));
    provider->personShop = createPersonShop(name, dni, address, phone, location, province, country, postCode);

    provider->fax= (char *) phone;
    provider->manufacturers = createStaticList(5, sizeof(Manufacturer));

}
StaticList* contactManufacturer(Provider* provider,char* code, int quantity){
    StaticList* products = createStaticList(quantity,sizeof(Product));
    for (int i = 0; i < provider->manufacturers->size; ++i) {
        goTo(provider->manufacturers,i);
        makeProducts(((Manufacturer*) getActual(provider->manufacturers)),products,code,quantity);
        
    }
    return products;
}
void freeProvider(Provider* provider){
    for (int i = 0; i < provider->manufacturers->size; ++i) {
        goTo(provider->manufacturers,i);
        freeManufacurer( (Manufacturer*)getActual(provider->manufacturers));
    }
    freeStaticList(provider->manufacturers);

    freePersonShop(provider->personShop);

    free(provider);
}