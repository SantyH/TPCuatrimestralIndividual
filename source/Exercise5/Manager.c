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
    addNext(movieClub->clients, createClient(name,surname,DNI));
}
void generateExcess(MovieClub* movieClub){
    goBack(movieClub->excesses);
    addNext(movieClub->excesses, createExcess(movieClub));
}

void generateMovieCard(Client* client, double amount){
    MovieCard* result = createMovieCard(client->DNI,amount);
    client->movieCard = result;
}

void increaseAmountMovieCard(MovieCard* movieCard, double amount){
    movieCard->totalAmount += amount;
}

void freeManager(Manager* manager){
    free(manager);
}