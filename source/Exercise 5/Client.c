//
// Created by Lucas on 30/5/2017.
//

#include <stdlib.h>
#include <mem.h>
#include <stdio.h>
#include "Client.h"


Client* createClient(char* name, char* surname, int DNI){
    Client* resultClient = malloc(sizeof(Client));
    resultClient->name = name;
    resultClient->surname = surname;
    resultClient->DNI = DNI;
    resultClient->movieCard = NULL;
    resultClient->movies = createStaticList(5);
    return resultClient;
}
void giveMovieCard(Client* client, MovieCard* movieCard){
    client->movieCard=movieCard;
}

void addMovie(Client* client, Movie* movie){
    addNext(client->movies, movie);
}

void returnMovie(Client* client,MovieClub* movieClub, char* movieTitle){
    for(int i=0; i<client->movies->size;i++){
        goTo(movieClub->movies,i);
        if(strcmp(movieTitle, ((Movie*) getActual(client->movies))->title )){
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

