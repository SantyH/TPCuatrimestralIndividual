//
// Created by Santiago Hazana on 6/10/17.
//

#include "BillLine.h"

BillLine* newBillLine(char* item, int quantity, double price){
    BillLine* billLine = malloc(sizeof(BillLine));
    billLine->item = item;
    billLine->quantity = quantity;
    billLine->subTotal = quantity*price;
    return billLine;
}

void freeBillLine(BillLine* billLine){
    free(billLine->item);
    free(billLine);
}