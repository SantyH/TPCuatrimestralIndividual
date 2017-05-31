//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H

#include "../StaticList.h"

typedef struct MovieClub{
    StaticList* movies;
    StaticList* clients;
    StaticList* excesses;
    double income;
    double amountRent;

}MovieClub;

MovieClub* createMovieClub(double amountRent);
void changeAmountRent(MovieClub* movieClub, double amountRent);
void freeMovieClub();
#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H

