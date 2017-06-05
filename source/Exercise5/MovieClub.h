//
// Created by Lucas on 4/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H

#include "../Structs/StaticList.h"


typedef struct MovieClub{
    StaticList* clients;
    StaticList* movies;
    StaticList* excesses;
    double income;
}MovieClub;

MovieClub* createMovieClub();
void freeMovieClub(MovieClub* movieClub);
#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H
