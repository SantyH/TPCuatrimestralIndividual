//
// Created by Lucas on 30/5/2017.
//

#include <stdlib.h>
#include <mem.h>
#include "Client.h"


Client* createClient(char name[], char surname[], int DNI){
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
void returnMovie(Client* client,MovieClub* movieClub,char* movieTitle){
    for(int i=0; i<client->movies->size;i++){
        if(strcmp(movieTitle, getActual(client->movies)))
            movieClub.getActual(client->movies)
    }
}
void freeClient(Client* client){
    free(client->movieCard);
    free(client->movies)
    free(client);
}

