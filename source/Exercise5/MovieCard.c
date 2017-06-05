//
// Created by Lucas on 30/5/2017.
//

#include <stdlib.h>
#include <stdio.h>
#include <mem.h>
#include "MovieCard.h"


MovieCard* createMovieCard(int id, double amount){
    MovieCard* movieCard = malloc(sizeof(MovieCard));
    movieCard->idMovieCard=id;
    movieCard->totalAmount=amount;
    movieCard->numberOfPrimiere=0;

}
int checkAvailableMovie(StaticList* movies, char* movieTitle){
    for(int i=0; i<movies->size;i++){
        goTo(movies,i);
        if(((Movie*) getActual(movies))->title == movieTitle){
            printf("%s", strcat("Movie Found: ",movieTitle));
            isAvailable(((Movie*) getActual(movies)));
            return 1;
        }
    }
    printf("%s",strcat("Movie not Found: ",movieTitle));
    showMovies(movies);
    return 0;
}

void showMovies(StaticList* movies){
    printf("%s", "All availables Movies!");
    for(int i=0; i<movies->size;++i){
        printf("%s",((Movie*)(getActual(movies)))->title);
    }
}

void checkMoviePremiere(StaticList* movies){
    for (int i = 0; i <movies->size; ++i) {
//        DateTime dateTime = Convert.ToDateTime(movies)
//
//        if()
    }
}

void freeMovieCard(MovieCard* movieCard){
    free(movieCard);
}