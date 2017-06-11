//
// Created by Santiago Hazana on 6/10/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_BAGLINE_H
#define TPCUATRIMESTRALINDIVIDUAL_BAGLINE_H

typedef struct BagLine BagLine;

struct BagLine{
    char* item;
    int quantity;
    double subTotal;
};

BagLine* newBagLine(char* item, int quantity, double price);
void freeBagLine(BagLine* bagLine);

#endif //TPCUATRIMESTRALINDIVIDUAL_BAGLINE_H
