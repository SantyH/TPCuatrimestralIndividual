//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "RegisterUser.h"
#include "Sale.h"
#include "Accessory.h"
#include "Camera.h"
#include "SaleLine.h"

RegisterUser* createRegisterUser(char* name, int dni, char* address, int phone, char* location, char* province, char* country,char* postCode){
    RegisterUser* registerUser = malloc(sizeof(RegisterUser));
    registerUser->personShop = createPersonShop(name, dni, address, phone, location, province, country, postCode);

    registerUser->wallet=0;
    registerUser->sales= createStaticList(5, sizeof(Sale));

    return registerUser;

}
void buyProduct(RegisterUser* registerUser, char* code, StaticList* accessories,StaticList* cameras){
    char sub[2];
    strncpy(sub, code, 2);
    if(strcmp("A-",sub)==0) {
        goBack(registerUser->sales);
        addNext(registerUser->sales,createSale());
        for (int i = 0; i < accessories->size; ++i) {
            goTo(accessories, i);
            double amount = registerUser->wallet - ((Accessory *) getActual(accessories))->product->retailPrice;
            if(  strcmp(((Accessory *) getActual(accessories))->product->code,code)==0 &&  amount > -1){
                registerUser->wallet = amount;
                goBack( ((SaleLine*) ((Sale*) getActual(registerUser->sales))->saleLine)->accessories);
                addNext( ((SaleLine*) ((Sale*) getActual(registerUser->sales))->saleLine)->accessories,
                         ((Accessory *) getActual(accessories)));

                ((Sale*) getActual(registerUser->sales))->retailPriceTotal+= ((Accessory *) getActual(accessories))->product->retailPrice;
                registerUser->wallet += ((Sale*) getActual(registerUser->sales))->retailPriceTotal * ((Sale*) getActual(registerUser->sales))->discount;
                return;
            }
        }
    }else if(strcmp("C-",sub)==0) {
        goBack(registerUser->sales);
        addNext(registerUser->sales,createSale());
        for (int i = 0; i < cameras->size; ++i) {
            goTo(cameras, i);
            double amount = registerUser->wallet - ((Camera *) getActual(cameras))->product->retailPrice;
            if(  strcmp(((Camera *) getActual(cameras))->product->code,code)==0 &&  amount > -1){
                registerUser->wallet = amount;
                goBack( ((SaleLine*) ((Sale*) getActual(registerUser->sales))->saleLine)->accessories);
                addNext( ((SaleLine*) ((Sale*) getActual(registerUser->sales))->saleLine)->accessories,
                         ((Camera *) getActual(cameras)));

                ((Sale*) getActual(registerUser->sales))->retailPriceTotal+= ((Accessory *) getActual(accessories))->product->retailPrice;
                registerUser->wallet += ((Sale*) getActual(registerUser->sales))->retailPriceTotal * ((Sale*) getActual(registerUser->sales))->discount;
                return;
            }
        }
    }
    else{
        printf("%s\n","Product not found or you have enough money in your wallet!");
    }

}
void increaseWallet(RegisterUser* registerUser, double amount){
    registerUser->wallet += amount;
}
void* freeRegisterUser(RegisterUser* registerUser){
    for (int i = 0; i < registerUser->sales->size; ++i) {
        freeSale( (Sale*) getActual(registerUser->sales));

    }
    freePersonShop(registerUser->personShop);
}