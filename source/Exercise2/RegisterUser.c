//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include <stdio.h>
#include "RegisterUser.h"
#include "Sale.h"

RegisterUser* createRegisterUser(char* name, int dni, char* address, int phone, char* location, char* province, char* country,char* postCode){
    RegisterUser* registerUser = malloc(sizeof(RegisterUser));
    registerUser->personShop = createPersonShop(name, dni, address, phone, location, province, country, postCode);

    registerUser->wallet=0;
    registerUser->sales= createStaticList(5, sizeof(Sale));

    return registerUser;

}
void buyProduct(RegisterUser* registerUser, Product* product){
    double amount = registerUser->wallet - product->retailPrice;
    if(amount>-1){
        for (int i = 0; i < registerUser->sales->size; ++i) {
            goTo(registerUser->sales,i);
            if( (()))
        }
        registerUser->wallet = amount;
        addNext(createSale(),)
    }
    else{
        printf("%s\n","Enough money in your wallet!");
    }

}
void increaseWallet(RegisterUser* registerUser, double amount){
    registerUser->wallet += amount;
}
//TODO
void* freeRegisterUser(RegisterUser* registerUser){
}