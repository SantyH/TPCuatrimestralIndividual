//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_EXCESS_H
#define TPCUATRIMESTRALINDIVIDUAL_EXCESS_H

#include "MovieClub.h"

typedef struct Excess{
    int unreturnMovies;
    double amount;
    double income;
    StaticList* clientsPrimiere;
    char* date;
    long timeStamp;
}Excess;


Excess* createExcess();
void determinateUnreturnMovies(MovieClub* movieClub);
void registerIncome(MovieClub* movieClub);
//determinateExcess
void rewardClients(MovieClub* movieClub);
void freeExcess(Excess* excess);

#endif //TPCUATRIMESTRALINDIVIDUAL_EXCESS_H
