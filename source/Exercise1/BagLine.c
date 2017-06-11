//
// Created by Santiago Hazana on 6/10/17.
//

#include "BagLine.h"

BagLine* newBagLine(char* item, int quantity, double price){
    BagLine* bagLine = malloc(sizeof(BagLine));
    bagLine->item = item;
    bagLine->quantity = quantity;
    bagLine->subTotal = quantity*price;
    return bagLine;
}

void freeBagLine(BagLine* bagLine){
    free(bagLine->item);
    free(bagLine);
}
