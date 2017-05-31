//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIE_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIE_H

#include "MovieCard.h"

typedef struct Movie{
    char* title;
    int idMovieCard;
    char* rentDate;
    char* devolutionDate;
} Movie;

Movie* createMovie(char* title);
void rentMovie(Movie* movie, MovieCard* movieCard);
void isAvailable(Movie* movie);
void freeMovie(Movie* movie);

#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIE_H

