//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H

#include "Movie.h"
#include "../LinkedList.h"

typedef struct MovieCard{
    int id;
    double totalAmount;

} MovieCard;

MovieCard* createMovieCard(int id, double amount);
void checkAvailableMovie(MovieClub* movieClub, char* movieTitle);
void checkMoviePremiere(MovieClub* movieClub);
void freeMovieCard(MovieCard* movieCard);
#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H

