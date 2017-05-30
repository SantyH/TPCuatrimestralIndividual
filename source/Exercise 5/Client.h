//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_CLIENT_H
#define TPCUATRIMESTRALINDIVIDUAL_CLIENT_H

#include "MovieCard.h"

typedef struct Client{
    char name[];
    char surname[];
    int DNI;
    MovieCard* movieCard;
} Client;

Client* createClient(char name[], char surname[], int DNI);
void giveMovieCard(MovieCard* movieCard);
void returnMovie(char movieTitle[]);
void freeClient(Client* client);

#endif //TPCUATRIMESTRALINDIVIDUAL_CLIENT_H
