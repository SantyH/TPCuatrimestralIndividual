//
// Created by Lucas on 30/5/2017.
//

#include <stdlib.h>
#include <stdio.h>
#include <mem.h>
#include <time.h>
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
        if(strcmp(((Movie*) getActual(movies))->title,movieTitle) == 0){
            printf("%s%s\n","Movie Found: ",movieTitle);
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
    time_t currentTime = time(NULL);
    long timeStampToday = currentTime;

    for (int i = 0; i <movies->size; ++i) {
        goTo(movies,i);

        double secondsDiff = difftime( ((Movie*)getActual(movies))->creationDate, timeStampToday);
        if ( secondsDiff <= 86400){ //Compare to 1 day in seconds
            printf("%s%s\n","Movie Title: ",((Movie*)getActual(movies))->title);
        }
    }
}

void freeMovieCard(MovieCard* movieCard){
    free(movieCard);
}