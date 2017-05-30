//
// Created by Lucas on 30/5/2017.
//

#include <rpcndr.h>

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIE_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIE_H
typedef struct Movie{
    char title[];
    int id;
    char* rentDate;
    char* devolutionDate;
} Movie;

Movie* createMovie(char title[], int id);
void rentMovie(Movie* movie);
boolean isAvailable(Movie* movie);
void freeMovie(Movie* movie);
#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIE_H
