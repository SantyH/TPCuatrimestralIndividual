//
// Created by Lucas on 30/5/2017.
//

#include <stdlib.h>
#include <stdio.h>
#include <mem.h>
#include "MovieCard.h"


MovieCard* createMovieCard(int id, double amount){
    MovieCard* movieCard = malloc(sizeof(MovieCard));
    movieCard->id=id;
    movieCard->totalAmount=amount;

}
void checkAvailableMovie(MovieClub* movieClub, char* movieTitle){
    for(int i=0; i<movieClub->movies->size;i++){
        goTo(movieClub->movies,i);
        if(((Movie*) getActual(movieClub->movies))->title == movieTitle){
            printf("%s", strcat("Movie Found: ",movieTitle));
            return;
        }
    }
    printf("%s",strcat("Movie not Found: ",movieTitle));
}

void checkMoviePremiere(MovieClub* movieClub){
    for (int i = 0; i < movieClub->movies->size; ++i) {
//        DateTime dateTime = Convert.ToDateTime(movies)
//
//        if()
    }
}
void freeMovieCard(MovieCard* movieCard){
    free(movieCard);
}