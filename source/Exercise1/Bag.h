//
// Created by Santiago Hazana on 6/10/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_BAG_H
#define TPCUATRIMESTRALINDIVIDUAL_BAG_H

#include "../Structs/StaticList.h"
#include "Bill.h"
#include "HouseElectro.h"

typedef struct Bag Bag;

struct Bag{
    int id;
    double total;
    StaticList* bagLines;
};

Bag* newBag(int id);
void addItem(Bag* bag, HouseElectro* item, int quantity);
void removeItem(Bag* bag, char* item);
Bill* generateBill(Bag* bag, int discount);
void seeBag(StaticList* bagList, Bag* bag);
void freeBag(Bag* bag);

#endif //TPCUATRIMESTRALINDIVIDUAL_BAG_H
