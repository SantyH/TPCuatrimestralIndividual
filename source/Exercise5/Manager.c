//
// Created by Lucas on 30/5/2017.
//

#include <malloc.h>
#include "Manager.h"

Manager* createManager(char* name,char* surname, int DNI){
    Manager* result = malloc(sizeof(Manager));
    result->name=name;
    result->surname = surname;
    result->DNI = DNI;
}
void registerClient(MovieClub* movieClub, char* name, char* surname, int DNI){
    addNext(movieClub, createClient(name,surname,DNI));
}
void generateExcess(MovieClub* movieClub){
    goBack(movieClub->excesses);
    addNext(movieClub->excesses, createExcess(movieClub));
}

void generateMovieCard(Client* client, double amount){
    giveMovieCard(client, createMovieCard(client->DNI,amount));
}

void increaseAmountMovieCard(MovieCard* movieCard, double amount){
    movieCard->totalAmount += amount;
}

void freeManager(Manager* manager){
    free(manager);
}