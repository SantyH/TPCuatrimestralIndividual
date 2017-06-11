//
// Created by Santiago Hazana on 6/10/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_BILL_H
#define TPCUATRIMESTRALINDIVIDUAL_BILL_H

#include "../Structs/StaticList.h"
#include "HouseElectro.h"

typedef struct Bill Bill;

struct Bill{
    int id;
    double total;
    StaticList* billLines;
};

Bill* newBill (int id);
void addItemToBill(Bill* bill, char* item, int quantity, double subTotal);
void freeBill(Bill* bill);

#endif //TPCUATRIMESTRALINDIVIDUAL_BILL_H
