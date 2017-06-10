//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include "PersonShop.h"

PersonShop* createPersonShop(char* name, int dni, char* address, int phone, char* location, char* province, char* country, char* postCode){
    PersonShop* personShop = malloc(sizeof(PersonShop));
    personShop->name=name;
    personShop->address= address;
    personShop->dni= dni;
    personShop->phone = phone;
    personShop->location = location;
    personShop->province = province;
    personShop->country = country;
    personShop->postCode = postCode;

    return personShop;
}

void freePersonShop(PersonShop* personShop){
    free(personShop);
}