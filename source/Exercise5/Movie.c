//
// Created by Lucas on 30/5/2017.
//

#include <malloc.h>
#include <time.h>
#include <mem.h>
#include <stdio.h>
#include "Movie.h"

Movie* createMovie(char* title, double price){
    Movie* result = malloc(sizeof(Movie));
    result->title = title;
    result->idMovieCard = 0;
    result->price = price;

    time_t currentTime = time(NULL);
    result->timeStamp=currentTime;
}
void changePrice(Movie *movie, double price){
    movie->price = price;
}

void rentMovie(Movie* movie, Client* client) {
    if (client->movieCard->totalAmount >= movie->price) {

        client->movieCard->totalAmount -= movie->price;

        movie->idMovieCard = client->movieCard->id;


        time_t calendarTime;
        time(&calendarTime);

        movie->rentDate = malloc(sizeof(char*));
        strcpy(movie->rentDate, ctime(&calendarTime));

        addMovie(client,movie);
    }
}

void isAvailable(Movie* movie){
    if(movie->idMovieCard == 0) {
        printf("%s", "Movie is available!");
    }else{
        printf("%s", "Movie is NOT available!");
    }
}

void freeMovie(Movie* movie){
    free(movie->rentDate);
    free(movie->devolutionDate);
    free(movie);
}