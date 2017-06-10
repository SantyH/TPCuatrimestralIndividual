//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include "Administrator.h"

Administrator* createAdministrator(char* name, int dni, char* address, int phone, char* location, char* province, char* country, char* postCode){
    Administrator* administrator = malloc(sizeof(Administrator));
    administrator->personShop = createPersonShop(name, dni, address, phone, location, province, country, postCode);

    return administrator;

}

StaticList* callProvider(Provider* provider,char* code ,int quantity){
    return contactManufacturer(provider,code,quantity);
}

void freeAdministrator(Administrator* administrator){
    freePersonShop(administrator->personShop);
}