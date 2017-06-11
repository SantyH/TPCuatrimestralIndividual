//
// Created by Santiago Hazana on 6/10/17.
//

#include <opencl-c.h>
#include "Bag.h"
#include "BagLine.h"

Bag* newBag(int id){
    Bag* bag = malloc(sizeof(Bag));
    bag->id = id;
    bag->bagLines = createStaticList(10, sizeof(BagLine));
    bag->total = 0;
    return bag;
}

void addItem(Bag* bag, HouseElectro* item, int quantity){
    addNext(bag->bagLines, newBagLine(item->name, quantity, item->price*quantity));
    bag->total += (quantity*item->price);
}

void removeItem(Bag* bag, char* item){
    for (int i = 0; i < bag->bagLines->size; ++i) {
        goTo(bag->bagLines, i);
        if(((BagLine*)getActual(bag->bagLines))->item == item) {
            freeBagLine(getActual(bag->bagLines));
            removeS(bag->bagLines);
            printf("Item %s removed", item);
            return;
        }
    }
    printf("Item not in bag");
}

Bill* generateBill(Bag* bag, int discount){
    Bill* bill = newBill(bag->id);

    bill->id = bag->id;
    bill->total = (bag->total*discount);

    for (int i = 0; i < bag->bagLines->size; ++i) {
        goTo(bag->bagLines, i);
        addItemToBill(bill, ((BagLine*)getActual(bag->bagLines))->item, ((BagLine*)getActual(bag->bagLines))->quantity, bag->total);
    }
    return bill;
}

void seeBag(StaticList* bagList, Bag* bag){
    printf("Your bag with id %i\n", bag->id);
    for (int i = 0; i < bagList->size; ++i) {
        goTo(bagList, i);
        goTo(bag->bagLines, i);
        printf("%s %i %f\n",
               ((BagLine*)getActual(bag->bagLines))->item,
               ((BagLine*)getActual(bag->bagLines))->quantity,
               ((BagLine*)getActual(bag->bagLines))->subTotal
        );
    }
    printf("%f\n", bag->total);
}

void freeBag(Bag* bag){
    for (int i = 0; i < bag->bagLines->size; ++i) {
        goTo(bag->bagLines, i);
        freeBagLine((BagLine*)getActual(bag->bagLines));
    }
    free(bag);
}