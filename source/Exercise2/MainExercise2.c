//
// Created by Lucas on 6/6/2017.
//

#include <stdio.h>
#include <memory.h>
#include "../ScannerUtil/ScanUtil.h"
#include "Administrator.h"
#include "RegisterUser.h"

void administratorMain(Administrator *administrator, StaticList *cameras, StaticList *accessories, Provider *provider);

void registerUserMain(RegisterUser *registerUser, StaticList *cameras, StaticList *accessories);

void providerMain(Provider *provider, StaticList *list, StaticList *staticList);

int main() {

    printf("%s\n %s\n","Set Manager.", "Introduce: Name, DNI, Address, Phone, Location, Province, Country and PostCode in this order");
    char* name = scanArrayOfChar();
    int dni = scanInt();
    char* address= scanArrayOfChar();
    int phone= scanInt();
    char* location= scanArrayOfChar();
    char* province= scanArrayOfChar();
    char* country= scanArrayOfChar();
    char* postCode= scanArrayOfChar();

    Administrator* administrator = createAdministrator(name, dni,address,phone,location, province, country, postCode);

    printf("%s\n %s\n","Set Provider.", "Introduce: Name, DNI, Address, Phone, Location, Province, Country and PostCode in this order");
    name = scanArrayOfChar();
    dni = scanInt();
    address= scanArrayOfChar();
    phone= scanInt();
    location= scanArrayOfChar();
    province= scanArrayOfChar();
    country= scanArrayOfChar();
    postCode= scanArrayOfChar();

    Provider* provider = createProvider(name, dni,address,phone,location, province, country, postCode);

    StaticList* cameras = createStaticList(5, sizeof(Camera));
    StaticList* accessories  = createStaticList(5, sizeof(Accessory));
    StaticList* clients = createStaticList(5, sizeof(RegisterUser));

    int loop = 1;
    while (loop) {
        printf("\n %s\n %s\n %s\n %s\n %s\n \n",
               "SHOP MENU",
               "1) ADMINISTRATOR MENU.",
               "2) CLIENT MENU.",
               "3) PROVIDER MENU.",
               "0) CLOSE."
        );
        int command = 0;
        command = scanInt();
        switch (command) {
            case 1:
                administratorMain(administrator,cameras,accessories,provider);
                break;
            case 2:
                printf("%s\n","Insert your DNI:");
                dni = scanInt();
                for(int i=0; i<clients->size; ++i){
                    if(dni == ((RegisterUser*) getActual(clients))->personShop->dni){
                        if(cameras->size>0 && accessories->size>0){
                            registerUserMain( ((RegisterUser*)getActual(clients)), accessories,cameras);
                            break;
                        }else{
                            printf("%s\n","There are no cameras and accessories loaded!");
                        }
                    }
                }
                printf("%s\n","DNI not found! Initialize new user:");
                printf("%s\n %s\n","Set RegisterUser.", "Introduce: Name, DNI, Address, Phone, Location, Province, Country and PostCode in this order");
                name = scanArrayOfChar();
                dni = scanInt();
                address= scanArrayOfChar();
                phone= scanInt();
                location= scanArrayOfChar();
                province= scanArrayOfChar();
                country= scanArrayOfChar();
                postCode= scanArrayOfChar();
                goBack(clients);
                addNext(clients, createRegisterUser(name, dni,address,phone,location, province, country, postCode));
                if(cameras->size>0 && accessories->size>0){
                    registerUserMain( ((RegisterUser*)getActual(clients)), accessories,cameras);
                    break;
                }else{
                    printf("%s\n","There are no cameras and accessories loaded!");
                }
                break;
            case 3:
                providerMain(provider,accessories,cameras);
                break;
            case 0:
                loop = 0;
                freeAdministrator(administrator);
                freeProvider(provider);
                for (int j = 0; j < clients->size; ++j) {
                    goTo(clients,j);
                    freeRegisterUser( (RegisterUser*)getActual(clients));
                }
                for (int k = 0; k < cameras->size; ++k) {
                    goTo(cameras,k);
                    freeRegisterUser( (RegisterUser*)getActual(cameras));
                }
                for (int l = 0; l < accessories->size; ++l) {
                    goTo(accessories,l);
                    freeRegisterUser( (RegisterUser*)getActual(accessories));
                }
                break;
            default:
                break;
        }
    }
}

void providerMain(Provider *provider, StaticList *accessories, StaticList *cameras) {
    int loop = 1;
    while (loop) {
        printf("\n %s\n %s\n %s\n %s\n \n",
               "SHOP MENU",
               "1) Contact Manufacturer.",
               "2) Add Manufacturer.",
               "0) Back."
        );
        int command = 0;
        command = scanInt();
        switch (command) {
            case 1:
                if(provider->manufacturers->size>0) {
                    printf("%s\n",
                           "Remember if you want an accesories you must add in front of the code A- or for camera C- .");
                    printf("%s\n", "Set code: ");
                    char *productCode = scanArrayOfChar();
                    int quantity = scanInt();
                    char sub[2];
                    strncpy(sub, productCode, 2);
                    if (strcmp("A-", sub) == 0) {
                        StaticList *accessoriesAux = contactManufacturer(provider, productCode, quantity);
                        goBack(accessories);
                        for (int i = 0; i < accessoriesAux->size; ++i) {
                            goTo(accessoriesAux, i);
                            addNext(accessories, ((Accessory *) getActual(accessoriesAux)));
                        }
                    } else if (strcmp("C-", sub) == 0) {
                        StaticList *camerasAux = contactManufacturer(provider, productCode, quantity);
                        goBack(cameras);
                        for (int i = 0; i < camerasAux->size; ++i) {
                            goTo(camerasAux, i);
                            addNext(cameras, ((Accessory *) getActual(camerasAux)));
                        }
                    } else {
                        printf("%s\n", "Product with this code not found!");
                    }
                }else{
                    printf("%s\n","Provider has no manufacturers to call!");
                }
                break;
            case 2:
                printf("%s\n", "Insert name:");
                char* name = scanArrayOfChar();
                printf("%s\n", "Insert Camera's name, code (C- not necessary), retail price, megapixels,LCD Screen, optical Zoom, type: ");
                char* nameProduct = scanArrayOfChar();
                char* code = scanArrayOfChar();
                double retailPrice = scanDouble();
                int megapixels = scanInt();
                int LCDScreen = scanInt();
                int opticalZoom = scanInt();
                char* type = scanArrayOfChar();

                Camera* camera = createCamera(nameProduct,code,retailPrice,megapixels,LCDScreen,opticalZoom,type);

                printf("%s\n", "Insert Accessory's name, code (A- not necessary), retail price, ,LCD Screen, optical Zoom, type: ");
                nameProduct = scanArrayOfChar();
                code = scanArrayOfChar();
                retailPrice = scanDouble();
                type = scanArrayOfChar();
                char* comments = scanArrayOfChar();

                Accessory* accessory = createAccessory(nameProduct,code,retailPrice,type,comments);

                goBack(provider->manufacturers);
                addNext(provider->manufacturers,createManufacturer(name,camera,accessory));
                break;
            case 0:
                loop = 0;
                break;
            default:
                break;
        }
    }
}

void registerUserMain(RegisterUser *registerUser, StaticList* accessories,StaticList* cameras) {
    int loop = 1;
    while (loop) {
        printf("\n %s\n %s\n %s\n %s\n %s\n \n",
               "SHOP MENU",
               "1) Buy Product.",
               "2) Get all information.",
               "3) Increase wallet.",
               "0) Back."
        );
        int command = 0;
        command = scanInt();
        switch (command) {
            case 1:
                printf("%s\n",
                       "Remember if you want an accesories you must add in front of the code A- or for camera C- .");
                printf("%s\n", "Set code: ");
                char *productCode = scanArrayOfChar();
                buyProduct(registerUser, productCode, accessories, cameras);
            case 2:
                for (int i = 0; i < cameras->size; ++i) {
                    goTo(cameras, i);
                    showCamera(((Camera *) getActual(cameras)));
                }
                for (int j = 0; j < accessories->size; ++j) {
                    goTo(accessories, j);
                    showAccessory(((Accessory *) getActual(accessories)));
                }
                break;
            case 3:
                printf("%s\n", "Insert amount of money for your wallet .");
                int amount = scanInt();
                increaseWallet(registerUser, amount);
                break;
            case 0:
                loop = 0;
                break;
            default:
                break;
        }
    }
}

void administratorMain(Administrator *administrator, StaticList *cameras, StaticList *accessories, Provider *provider) {
    int loop = 1;
    while (loop) {
        printf("\n %s\n %s\n %s\n %s\n \n",
               "ADMINISTRATOR MENU",
               "1) Call provider for more Cameras.",
               "2) Call provider for more Accessories .",
               "0) Back."
        );
        int command = 0;
        command = scanInt();
        int quantity;
        switch (command) {
            case 1:
                if(provider->manufacturers->size>0) {
                    printf("%s\n", "Remember not to include 'C-'. Camera Code: ");
                    char *codeCamera = "C-";
                    strcat(codeCamera, scanArrayOfChar());
                    printf("%s\n", "Quantity: ");
                    quantity = scanInt();
                    StaticList *camerasAUX = callProvider(provider, codeCamera, quantity);
                    goBack(cameras);
                    for (int i = 0; i < camerasAUX->size; ++i) {
                        goTo(camerasAUX, i);
                        addNext(cameras, ((Camera *) getActual(camerasAUX)));
                    }
                    freeStaticList(camerasAUX);
                }else{
                    printf("%s\n","Provider has no manufacturers to call!");
                }
                break;
            case 2:
                if(provider->manufacturers->size>0) {
                    printf("%s\n", "Remember not to include 'A-'. Camera Code: ");
                    char *codeAccessory = "A-";
                    strcat(codeAccessory, scanArrayOfChar());
                    printf("%s\n", "Quantity: ");
                    quantity = scanInt();
                    StaticList *accessoriesAUX = callProvider(provider, codeAccessory, quantity);
                    goBack(accessories);
                    for (int i = 0; i < accessoriesAUX->size; ++i) {
                        goTo(accessoriesAUX, i);
                        addNext(accessories, ((Accessory *) getActual(accessoriesAUX)));
                    }
                    freeStaticList(accessoriesAUX);
                }else{
                    printf("%s\n","Provider has no manufacturers to call!");
                }
                break;
            case 0:
                loop = 0;
                break;
            default:
                break;
        }
    }
}

