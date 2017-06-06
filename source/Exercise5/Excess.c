//
// Created by Lucas on 30/5/2017.
//


#include <time.h>
//#include <malloc.h>
//#include <mem.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
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
        for (int j = 0; j < ((Client*) getActual(movieClub->clients))->movies->size; ++j) {
            excess->unreturnMovies++;
        }
    }
}

void registerIncome(Excess* excess, MovieClub* movieClub) {
    time_t currentTime = time(NULL);
    long timeStampToday = currentTime;

    for (int i = 0; i < movieClub->clients->size; i++) {
        goTo(movieClub->clients, i);

        for (int j = 0; j < ((Client *) getActual(movieClub->clients))->movies->size; ++j) {
            goTo(((Client *) getActual(movieClub->clients))->movies,j);
            getActual(((Client *) getActual(movieClub->clients))->movies);

            double secondsDiff = difftime(((Movie*)getActual(((Client *) getActual(movieClub->clients))->movies))->rentDate, timeStampToday);
            if ( secondsDiff <= 86400){ //Compare to 1 day in seconds
                excess->income += ((Movie*)getActual(((Client *) getActual(movieClub->clients))->movies))->price;
            }
        }
    }
    for (int k = 0; k < movieClub->movies->size; ++k) {
        goTo(movieClub->movies,k);
        if(((Movie*)getActual(movieClub->movies))->idMovieCard !=0){
            excess->income += ((Movie*)getActual(movieClub->movies))->price;
        }
    }
}

void determinateExcess(Excess* excess){
    printf("\n%s\n %s%d\n %s%f\n %s%d\n", excess->date,
           "Unreturn Movies: ",excess->unreturnMovies,
           "Income: ",excess->income,
           "Number of premiere Clients: ",excess->numberOfPremiereClients
    );
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