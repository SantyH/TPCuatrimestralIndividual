//
// Created by Lucas on 30/5/2017.
//

#include <malloc.h>
#include <time.h>
#include <mem.h>
#include <stdio.h>
#include "Movie.h"

Movie* createMovie(char* title){
    Movie* result = malloc(sizeof(Movie));
    result->title= title;
    result->idMovieCard=0;
}
/**
 * EL precio de la pelicula lo deberia conocer el movieclub o la propia pelicula ????
 */
void rentMovie(Movie* movie, MovieCard* movieCard){
    if(movieCard->totalAmount)
    movie->idMovieCard= movieCard->id;

    time_t calendarTime;
    time(&calendarTime);

    movie->rentDate= malloc(sizeof(char*));
    strcpy(movie->rentDate,ctime(&calendarTime));
}

void isAvailable(Movie* movie){
    if(movie->idMovieCard == 0) {
        printf("%s", "Movie is available!");
    }else{
        printf("%s", "Movie is NOT available!");
    }


}

void freeMovie(Movie* movie){
    free(movie->rentDate);
    free(movie->devolutionDate);
    free(movie);
}