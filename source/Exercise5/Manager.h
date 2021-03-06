//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MANAGER_H
#define TPCUATRIMESTRALINDIVIDUAL_MANAGER_H

#include "MovieClub.h"
#include "Client.h"
#include "Excess.h"

typedef struct Manager{
    char* name;
    char* surname;
    int DNI;
}Manager;


Manager* createManager(char* name,char* surname, int DNI);
void registerClient(MovieClub* movieClub, Client* client);
void generateMovieCard(Client* client, double amount);
void generateExcess(MovieClub* movieClub);
void increaseAmountMovieCard(MovieCard* movieCard, double amount);
void saveMovie(MovieClub* movieClub, MovieCard* movieCard, Movie* movie);
void freeManager(Manager* manager);

#endif //TPCUATRIMESTRALINDIVIDUAL_MANAGER_H
