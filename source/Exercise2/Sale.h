//
// Created by Lucas on 9/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_SALE_H
#define TPCUATRIMESTRALINDIVIDUAL_SALE_H

#include "../Structs/StaticList.h"

typedef struct Sale{
    long currentTime;
    char* dayCurrentTime;
    StaticList* saleLine;
}Sale;

Sale* createSale();
void freeSale(Sale* sale);
#endif //TPCUATRIMESTRALINDIVIDUAL_SALE_H
