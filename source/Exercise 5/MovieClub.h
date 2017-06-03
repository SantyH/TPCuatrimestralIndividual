//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H

#include "../StaticList.h"
#include "Manager.h"

typedef struct MovieClub{
    StaticList* movies;
    StaticList* clients;
    StaticList* excesses;
    double income;
    Manager* manager;

}MovieClub;

MovieClub* createMovieClub(Manager* manager);
void freeMovieClub(MovieClub* movieClub);
#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIECLUB_H

