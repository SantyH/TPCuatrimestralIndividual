//
// Created by Lucas on 30/5/2017.
//
#include "MovieClub.h"

#ifndef TPCUATRIMESTRALINDIVIDUAL_MANAGER_H
#define TPCUATRIMESTRALINDIVIDUAL_MANAGER_H

#include "Client.h"
#include "Excess.h"

typedef struct Manager{
    char name[];
    char surName[];
    int DNI;
}Manager;


Manager* createManager(char name[],char surName[], int DNI);
Client* registerClient();
Excess* generateExcess();
void generateMovieCard(Client* client);
void increaseAmountMovieCard(MovieCard* movieCard);
void freeManager(Manager* manager);

#endif //TPCUATRIMESTRALINDIVIDUAL_MANAGER_H
