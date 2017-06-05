//
// Created by Lucas on 30/5/2017.
//

#include <malloc.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <mem.h>
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
    Excess* excess =createExcess();
    determinateUnreturnMovies(excess, movieClub);
    registerIncome(excess, movieClub);
    rewardClients(movieClub);
    determinateExcess(excess);

    goBack(movieClub->excesses);
    addNext(movieClub->excesses, excess);
}

void generateMovieCard(Client* client, double amount){
    MovieCard* result = createMovieCard(client->DNI,amount);
    client->movieCard = result;
}
void saveMovie(MovieClub* movieClub, MovieCard* movieCard, Movie* movie){
    time_t calendarTime;
    time(&calendarTime);

    movie->devolutionDate = malloc(sizeof(char *));
    strcpy(movie->devolutionDate, ctime(&calendarTime));

    time_t currentTime = time(NULL);
    long timeStampToday = currentTime;

    // COMPARE DAYS AND INCREASE PREMIERE CONTABILITIES IN MOVIECARD
    double secondsDiff = difftime(movie->timeStamp, timeStampToday);
    if ( secondsDiff <= 86400){ // Seconds per day.
        movieCard->numberOfPrimiere++;
    }else{
        double punishmentCost = fabs(secondsDiff-86400) * 10;
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