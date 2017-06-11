//
// Created by Santiago Hazana on 6/7/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_CATALOG_H
#define TPCUATRIMESTRALINDIVIDUAL_CATALOG_H

#include "../Structs/StaticList.h"
#include "HouseElectro.h"

typedef struct Catalog Catalog;

struct Catalog{
    int id;
    char* name;
    int discount;
};

Catalog* newCatalog(int id, char* name, int discount);
void seeCatalog(StaticList* catalogList, Catalog* catalog);
HouseElectro* addToBag(Catalog* catalog, StaticList* catalogList, int id);
void freeCatalog(Catalog* catalog);

#endif //TPCUATRIMESTRALINDIVIDUAL_CATALOG_H
