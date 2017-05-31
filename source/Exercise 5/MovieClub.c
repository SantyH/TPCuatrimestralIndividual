//
// Created by Lucas on 30/5/2017.
//

#include <malloc.h>
#include "MovieClub.h"

MovieClub* createMovieClub(double amountRent){

    MovieClub* result = malloc(sizeof(MovieClub));
    result->income = 0;
    result->amountRent = amountRent;
    result->movies = createStaticList(5);
    result->clients = createStaticList(5);
    result->excesses = createStaticList(5);
}
void changeAmountRent(MovieClub* movieClub, double amountRent){
    movieClub->amountRent = amountRent;
}

void freeMovieClub();