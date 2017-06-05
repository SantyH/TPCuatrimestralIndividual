//
// Created by Lucas on 4/6/2017.
//

#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include "Client.h"
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
        goTo(movieClub->movies,i);
        if(strcmp(movieTitle, ((Movie*) getActual(client->movies))->title )){
            // COMPARE DAYS AND INCREASE PREMIERE CONTABILITIES IN MOVIECARD
            goBack(movieClub->movies);
            addNext(movieClub->movies,(Movie*) getActual(client->movies));
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