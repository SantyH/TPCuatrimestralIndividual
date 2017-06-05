//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_EXCESS_H
#define TPCUATRIMESTRALINDIVIDUAL_EXCESS_H

//#include "MovieClub.h"

#include "MovieClub.h"
#include "../Structs/StaticList.h"

typedef struct Excess{
    int unreturnMovies;
    double income;
    int numberOfPremiereClients;
    char* date;
    long timeStamp;
}Excess;


Excess* createExcess();
void determinateUnreturnMovies(Excess* excess, MovieClub* movieClub);
void registerIncome(Excess* excess, MovieClub* movieClub);
void determinateExcess(Excess* excess);
void rewardClients(MovieClub* movieClub);
void freeExcess(Excess* excess);

#endif //TPCUATRIMESTRALINDIVIDUAL_EXCESS_H
