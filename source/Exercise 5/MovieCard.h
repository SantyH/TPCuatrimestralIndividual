//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H

#include "Movie.h"
#include "../LinkedList.h"

typedef struct MovieCard{
    int id;
    int totalAmount;
    //decidir si un arreglo o una lista de peliculas.
    LinkedList* movies;

} MovieCard;

MovieCard* createMovieCard(int id, int amount);
void checkAvailableMovie(MovieCard* movieCard, char movieTitle[]);
//void checkMoviePremiere(MovieCard* movieCard);
void freeMovieCard(MovieCard* movieCard);
#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H

