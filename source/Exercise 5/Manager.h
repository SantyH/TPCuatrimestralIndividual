//
// Created by Lucas on 30/5/2017.
//
#include "MovieClub.h"

#ifndef TPCUATRIMESTRALINDIVIDUAL_MANAGER_H
#define TPCUATRIMESTRALINDIVIDUAL_MANAGER_H

#include "Client.h"
#include "Excess.h"

typedef struct Manager{
    char* name;
    char* surname;
    int DNI;
}Manager;


Manager* createManager(char* name,char* surname, int DNI);
Client* registerClient(MovieClub* movieClub, Client* client);
Excess* generateExcess(MovieClub* movieClub);
void generateMovieCard(Client* client, double amount);
void increaseAmountMovieCard(MovieCard* movieCard, double amount);
void freeManager(Manager* manager);

#endif //TPCUATRIMESTRALINDIVIDUAL_MANAGER_H
