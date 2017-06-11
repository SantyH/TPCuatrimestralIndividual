//
// Created by Santiago Hazana on 6/10/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_BILLLINE_H
#define TPCUATRIMESTRALINDIVIDUAL_BILLLINE_H

typedef struct BillLine BillLine;

struct BillLine{
    char* item;
    int quantity;
    double subTotal;
};

BillLine* newBillLine(char* item, int quantity, double price);
void freeBillLine(BillLine* billLine);

#endif //TPCUATRIMESTRALINDIVIDUAL_BILLLINE_H
