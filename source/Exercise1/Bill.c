//
// Created by Santiago Hazana on 6/10/17.
//

#include "Bill.h"
#include "BillLine.h"

Bill* newBill (int id){
    Bill* bill = malloc(sizeof(Bill));
    bill->id = id;
    bill->total = 0;
    bill->billLines = createStaticList(10, sizeof(BillLine));
}

void addItemToBill(Bill* bill, char* item, int quantity, double subTotal){
    addNext(bill->billLines, newBillLine(item, quantity, subTotal));
}

void freeBill(Bill* bill){
    for (int i = 0; i < bill->billLines->size; ++i) {
        goTo(bill->billLines, i);
        freeBillLine(getActual(bill->billLines));
    }
    free(bill);
}