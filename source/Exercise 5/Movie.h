//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIE_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIE_H

#include "MovieCard.h"
#include "Client.h"

typedef struct Movie{
    char* title;
    double price;
    int idMovieCard;
    char* rentDate;
    char* devolutionDate;
    time_t timeStamp;
} Movie;

Movie* createMovie(char* title, double price);
void changePrice(Movie *movie, double price);
void rentMovie(Movie* movie, Client* client);
void isAvailable(Movie* movie);
void freeMovie(Movie* movie);

#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIE_H

