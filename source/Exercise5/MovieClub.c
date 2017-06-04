//
// Created by Lucas on 30/5/2017.
//

#include <malloc.h>
#include "MovieClub.h"

MovieClub* createMovieClub(Manager* manager){

    MovieClub* result = malloc(sizeof(MovieClub));
    result->income = 0;
    result->movies = createStaticList(5, sizeof(Movie));
    result->clients = createStaticList(5, sizeof(Client));
    result->excesses = createStaticList(5, sizeof(Excess));
    result->manager = manager;
}

void freeMovieClub(MovieClub* movieClub){
    free(movieClub->movies);
    free(movieClub->excesses);
    free(movieClub->clients);
    freeManager(movieClub->manager);
    free(movieClub);
}