//
// Created by Lucas on 30/5/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H

#include "Movie.h"
#include "MovieClub.h"


typedef struct MovieCard{
    int idMovieCard;
    double totalAmount;
    int numberOfPrimiere;

}MovieCard;

MovieCard* createMovieCard(int id, double amount);
int checkAvailableMovie(StaticList* movies, char* movieTitle);
void showMovies(StaticList* movies);
void checkMoviePremiere(StaticList* movies);
void freeMovieCard(MovieCard* movieCard);
#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIECARD_H

