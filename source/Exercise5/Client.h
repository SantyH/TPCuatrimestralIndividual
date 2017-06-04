//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_CLIENT_H
#define TPCUATRIMESTRALINDIVIDUAL_CLIENT_H

#include "MovieCard.h"
#include "../Structs/StaticList.h"
#include "MovieClub.h"

typedef struct Client{
    char* name;
    char* surname;
    int DNI;
    MovieCard* movieCard;
    StaticList* movies;
} Client;

Client* createClient(char* name, char* surname, int DNI);
void giveMovieCard(Client* client, MovieCard* movieCard);
void addMovie(Client* client, Movie* movie);
void returnMovie(Client* client, MovieClub* movieClub,char* movieTitle);
void freeClient(Client* client);


#endif //TPCUATRIMESTRALINDIVIDUAL_CLIENT_H
