//
// Created by Lucas on 30/5/2017.
//

#include <malloc.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "Manager.h"

Manager* createManager(char* name,char* surname, int DNI){
    Manager* result = malloc(sizeof(Manager));
    result->name=name;
    result->surname = surname;
    result->DNI = DNI;
}
void registerClient(MovieClub* movieClub, Client* client){
    addNext(movieClub->clients,client);
}
void generateExcess(MovieClub* movieClub){
    goBack(movieClub->excesses);
    addNext(movieClub->excesses, createExcess(movieClub));
}

void generateMovieCard(Client* client, double amount){
    MovieCard* result = createMovieCard(client->DNI,amount);
    client->movieCard = result;
}
void saveMovie(MovieClub* movieClub, MovieCard* movieCard, Movie* movie){
    time_t currentTime = time(NULL);
    long timeStampToday = currentTime;
    // COMPARE DAYS AND INCREASE PREMIERE CONTABILITIES IN MOVIECARD
    double secondDiff = ( difftime(movie->timeStamp, timeStampToday));
    if ( secondDiff <= 86400){ // Seconds per day.
        movieCard->numberOfPrimiere++;
    }else{
        double punishmentCost = fabs(secondDiff-86400) * 10;
        movieCard->totalAmount -= punishmentCost;
        printf("%s %f","PunismentCost: ", punishmentCost);
    }
    goBack(movieClub->movies);
    addNext(movieClub->movies,movie);
}

void increaseAmountMovieCard(MovieCard* movieCard, double amount){
    movieCard->totalAmount += amount;
}

void freeManager(Manager* manager){
    free(manager);
}