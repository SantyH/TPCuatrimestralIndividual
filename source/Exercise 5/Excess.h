//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_EXCESS_H
#define TPCUATRIMESTRALINDIVIDUAL_EXCESS_H

#include "MovieClub.h"

typedef struct Excess{
    // lista o arreglo de peliculas no de vueltas
    double amount;
    double income;
    // lista o arreglo de clientes mas activos
    char* date;
}Excess;


Excess* createExcess();
void determinateUnreturnMovies(MovieClub* movieClub);
void registerIncome(MovieClub* movieClub);
//determinateExcess
void rewardClients(MovieClub* movieClub);
void freeExcess(Excess* excess);

#endif //TPCUATRIMESTRALINDIVIDUAL_EXCESS_H
