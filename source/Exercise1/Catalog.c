//
// Created by Santiago Hazana on 6/7/17.
//

#include <opencl-c.h>
#include "Catalog.h"

Catalog* newCatalog(int id, char* name, int discount){
    Catalog* catalog = malloc(sizeof(Catalog));
    catalog->id = id;
    catalog->name = name;
    catalog->discount = discount;
    return catalog;
}

void seeCatalog(StaticList* catalogList, Catalog* catalog){
    printf("Catalog %i %s\n",
            catalog->id,
           catalog->name
    );
    for (int i = 0; i < catalogList->size; ++i) {
        goTo(catalogList, i);
        printf("%i %s %lf\n",
               ((HouseElectro*)getActual(catalogList))->id,
               ((HouseElectro*)getActual(catalogList))->name,
               (((HouseElectro*)getActual(catalogList))->price)*(1-catalog->discount)
        );
    }
}

HouseElectro* addToBag(Catalog* catalog, StaticList* catalogList, int id){
    for (int i = 0; i < catalogList->size; ++i) {
        goTo(catalogList, i);
        if (id == ((HouseElectro*)getActual(catalogList))->id)
            return getActual(catalogList);
    }
    printf("Item not in catalog");
}

void freeCatalog(Catalog* catalog){
    free(catalog->name);
    free(catalog);
}