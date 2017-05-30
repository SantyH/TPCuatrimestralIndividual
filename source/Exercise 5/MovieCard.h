//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H

#include "Movie.h"

typedef struct MovieCard{
    int id;
    int totalAmount;
    //decidir si un arreglo o una lista de peliculas.

} MovieCard;

MovieCard* createMovieCard(int id, int amount);
void checkAvailableMovie(char movieTitle[]);
//void checkMoviePremiere();
void addMovie(Movie* movie);
void freeMovieCard(MovieCard* movieCard);
#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H
