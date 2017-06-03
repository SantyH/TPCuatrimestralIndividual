//
// Created by Lucas on 30/5/2017.
//

#include <malloc.h>
#include "MovieClub.h"

MovieClub* createMovieClub(Manager* manager){

    MovieClub* result = malloc(sizeof(MovieClub));
    result->income = 0;
    result->movies = createStaticList(5);
    result->clients = createStaticList(5);
    result->excesses = createStaticList(5);
    result->manager = manager;
}

void freeMovieClub(MovieClub* movieClub){
    free(movieClub->movies);
    free(movieClub->excesses);
    free(movieClub->clients);
    freeManager(movieClub->manager);
    free(movieClub);
}