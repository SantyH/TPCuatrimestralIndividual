//
// Created by Lucas on 30/5/2017.
//


#include <time.h>
#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include "Excess.h"
#include "Client.h"


Excess* createExcess(){
    Excess* result = malloc(sizeof(Excess));

    time_t calendarTime;
    time(&calendarTime);

    time_t currentTime = time(NULL);
    result->timeStamp=currentTime;

    result->date = malloc(sizeof(char *));
    strcpy(result->date, ctime(&calendarTime));

    result->unreturnMovies=0;
    result->income=0;
    result->numberOfPremiereClients=0;
}
void determinateUnreturnMovies(Excess* excess, MovieClub* movieClub){
    for (int i = 0; i < (int) movieClub->clients; ++i) {
        goTo(movieClub->clients,i);
        excess->unreturnMovies += ((Client*) getActual(movieClub->clients))->movies->size;
    }
}

void registerIncome(Excess* excess, MovieClub* movieClub) {
    double partialAmount = 0;
    for (int i = 0; i < movieClub->clients->size; i++) {
        goTo(movieClub->clients, i);
        for (int j = 0; j < ((Client *) getActual(movieClub->clients))->movies->size; ++j) {
            goTo(((Client *) getActual(movieClub->clients))->movies, j);
//            if(strcmp(excess.date,
//                    ((Movie*) getActual(((Client*) getActual(movieClub->clients))->movies)).)
//            if(excess.timeStamp)
//        }
//        partialAmount +=
        }
    }
}

void determinateExcess(Excess* excess){
    printf("%s", excess->date);
    printf("%s %d","Unreturn Movies: ",excess->unreturnMovies);
    printf("%s %f","Income: ",excess->income);
    printf("%s %d","Number of premiere Clients: ",excess->numberOfPremiereClients);
}
void rewardClients(MovieClub* movieClub){
    for (int i = 0; i < movieClub->clients->size; ++i) {
        double amountPremiere= 0;
        int numberOfPremiere = ((Client*) getActual(movieClub->clients))->movieCard->numberOfPrimiere;
        goTo(movieClub->clients,i);
        if(numberOfPremiere >=3){
            amountPremiere = 5 * numberOfPremiere;
        }
        ((Client*) getActual(movieClub->clients))->movieCard->numberOfPrimiere = 0;
        ((Client*) getActual(movieClub->clients))->movieCard->totalAmount += amountPremiere;
    }
}
void freeExcess(Excess* excess){
    free(excess->date);
    free(excess);
}