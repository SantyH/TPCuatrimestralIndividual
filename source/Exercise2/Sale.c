//
// Created by Lucas on 9/6/2017.
//

#include <malloc.h>
#include <time.h>
#include <mem.h>
#include "Sale.h"
#include "SaleLine.h"

Sale* createSale(){
    Sale* sale = malloc(sizeof(Sale));

    time_t currentTime = time(NULL);
    sale->currentTime = currentTime;

    time_t calendarTime;
    time(&calendarTime);

    sale->dayCurrentTime = malloc(sizeof(char *));
    strcpy(sale->dayCurrentTime, ctime(&calendarTime));

    sale->saleLine = createStaticList(5, sizeof(SaleLine));
    return sale;
}

void freeSale(Sale* sale){
    for (int i = 0; i < sale->saleLine->size; ++i) {
        freeSaleLine(getActual(sale->saleLine));
    }
}