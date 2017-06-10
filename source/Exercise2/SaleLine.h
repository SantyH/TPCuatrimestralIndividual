//
// Created by Lucas on 9/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_SALELINE_H
#define TPCUATRIMESTRALINDIVIDUAL_SALELINE_H

#include "../Structs/StaticList.h"

typedef struct SaleLine{
    StaticList* cameras;
    StaticList* accessories;
}SaleLine;
SaleLine* createSaleLine();
void showProducts();
void freeSaleLine(SaleLine* saleLine);
#endif //TPCUATRIMESTRALINDIVIDUAL_SALELINE_H
