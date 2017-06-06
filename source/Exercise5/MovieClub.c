//
// Created by Lucas on 4/6/2017.
//

//#include <malloc.h>
#include <stdlib.h>
#include "MovieClub.h"
#include "Client.h"
#include "Excess.h"

MovieClub* createMovieClub(){
    MovieClub* result = malloc(sizeof(MovieClub));
    result->movies = createStaticList(20, sizeof(Movie));
    result->clients = createStaticList(5, sizeof(Client));
    result->excesses = createStaticList(5, sizeof(Excess));
    result->income=0;
}
void freeMovieClub(MovieClub* movieClub){
    free(movieClub->movies);
    free(movieClub->clients);
    free(movieClub->excesses);
    free(movieClub);
}