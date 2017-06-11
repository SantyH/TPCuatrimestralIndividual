//
// Created by Santiago Hazana on 6/7/17.
//

#include <opencl-c.h>
#include "Maker.h"
#include "Provider.h"
#include "Catalog.h"
#include "../ScannerUtil/ScanUtil.h"
#include "Bag.h"

int main(){
    Maker* maker = newMaker("ATMA", "Electrodomesticos", "Roque Perez 3650, CABA", "Buenos Aires", 420423, "atma.com");
    Provider* provider = newProvider("ATMA distribucion", "Distribuidor electrodomesticos ATMA", "Roque Perez 3650, CABA", "Buenos Aires", 420423, "atma.com");
    StaticList* makerProducts = createStaticList(10, sizeof(HouseElectro*));
    StaticList* providerProducts = createStaticList(10, sizeof(HouseElectro*));
    StaticList* catalogList = createStaticList(10, sizeof(HouseElectro));
    Catalog* catalog;

    int operate = 1;

    while (operate) {

        printf("Main Menu: choose an option%s\n %s\n %s\n %s\n\n",
               "1. Admin",
               "2. User",
               "0. Exit"
        );

        int command = scanInt();

        switch (command){
            case 1:
                admin(catalog, makerProducts, providerProducts, catalogList, provider);
                break;
            case 2:
                user(catalog, makerProducts, providerProducts, catalogList, provider);
                break;
            case 0:
                operate = 0;
            default:
                break;
        }
    }
}

void admin(Catalog* catalog, StaticList* makerProducts, StaticList* providerProducts, StaticList* catalogList, Provider* provider){
    int operate = 1;

    while (operate){
        printf("Administrator menu: choose an option\n %s\n %s\n %s\n %s\n\n",
               "1. Create catalog",
               "2. Create product",
               "3. Load product to catalog",
               "0. Exit"
        );

        int command = scanInt();

        switch (command){
            case 1:
                printf("Enter catalog id, name and discount\n");
                catalog = newCatalog(scanInt(), scanArrayOfChar(), scanInt());
                break;
            case 2:
                printf("Enter product id, name, model\n");
                addNext(makerProducts, makeHouseElectro(scanInt(), scanArrayOfChar(), scanArrayOfChar()));
                break;
            case 3:
                printf("Select product\n");
                for (int i = 0; i < makerProducts->size; ++i) {
                    goTo(makerProducts, i);
                    printf("%i %s %s",
                           ((HouseElectro*)getActual(makerProducts))->id,
                           ((HouseElectro*)getActual(makerProducts))->name,
                           ((HouseElectro*)getActual(makerProducts))->model
                    );
                }
                addNext(providerProducts, sellHouseElectro(makerProducts, scanInt()));
                printf("Enter selling price\n");
                changePrice(((HouseElectro*)getActual(providerProducts)), scanInt());
                addNext(catalogList, getActual(providerProducts));
            case 0:
                operate = 0;
                break;
            default:
                break;
        }
    }
}

void user(Catalog* catalog, StaticList* makerProducts, StaticList* providerProducts, StaticList* catalogList, Provider* provider){
    int operate = 1;
    int bagCount = 1;

    Bag* bag = newBag(1);

    while (operate){
        printf("Welcome to Garbarino\n Choose your option\n %s\n %s\n %s\n %s\n %s\n\n",
               "1. See catalog",
               "2. Add item to bag",
               "3. Remove item from bag",
               "4. Check out",
               "0. Exit"
        );

        int command = scanInt();

        switch (command){
            case 1:
                seeCatalog(catalogList, catalog);
                break;
            case 2:
                printf("Enter item id to add to bag and quantity\n");
                addItem(bag, addToBag(catalog, catalogList, scanInt()), scanInt());
                break;
            case 3:
                printf("Enter item name to delete\n");
                removeItem(bag, scanArrayOfChar());
                break;
            case 4:
                generateBill(bag, catalog->discount);
                break;
            default:
                break;
        }
    }
}
