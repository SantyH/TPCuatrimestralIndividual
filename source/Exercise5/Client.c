//
// Created by Lucas on 4/6/2017.
//

#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include "Client.h"
#include "Manager.h"

Client* createClient(char* name, char* surname, int DNI){
    Client* resultClient = malloc(sizeof(Client));
    resultClient->name = name;
    resultClient->surname = surname;
    resultClient->DNI = DNI;
    resultClient->movieCard= malloc(sizeof(MovieCard));
    resultClient->movies = createStaticList(5, sizeof(Movie));
    return resultClient;
}
void pickUpMovies(Client* client, StaticList* movies){
    goBack(client->movies);
    for (int i = 0; i < movies->size; ++i) {
        if(client->movieCard->idMovieCard == ((Movie*) getActual(movies))->idMovieCard ){
            addNext(client->movies, ((Movie*) getActual(movies)));
        }
    }
}

void returnMovie(Client* client,MovieClub* movieClub, char* movieTitle){
    for(int i=0; i<client->movies->size;i++){
        goTo(client->movies,i);
        if(strcmp(movieTitle, ((Movie*) getActual(client->movies))->title )){
            saveMovie(movieClub,client->movieCard,((Movie*) getActual(client->movies)));
            return;
        }
    }
    printf("%s","You don't have this movie!");
}

void freeClient(Client* client){
    free(client->movieCard);
    free(client->movies);
    free(client);
}