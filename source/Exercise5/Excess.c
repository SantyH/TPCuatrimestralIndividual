//
// Created by Lucas on 30/5/2017.
//


#include <time.h>
#include <malloc.h>
#include <mem.h>
#include "Excess.h"


Excess* createExcess(MovieClub* movieClub){
    Excess* result = malloc(sizeof(Excess));

    time_t calendarTime;
    time(&calendarTime);

    time_t currentTime = time(NULL);
    result->timeStamp=currentTime;

    result->date = malloc(sizeof(char *));
    strcpy(result->date, ctime(&calendarTime));

    result->unreturnMovies=0;
//    result->income
}
void determinateUnreturnMovies(Excess* excess, MovieClub* movieClub){
    for (int i = 0; i < movieClub->clients; ++i) {
        goTo(movieClub->clients,i);
        excess->unreturnMovies += ((Client*) getActual(movieClub->clients))->movies->size;
    }
}
void registerIncome(Excess excess, MovieClub* movieClub){
    double partialAmount = 0;
    for(int i = 0; i<movieClub->clients->size,i++){
        goTo(movieClub->clients,i);
        for (int j = 0; j < ((Client*) getActual(movieClub->clients))->movies->size; ++j) {
            goTo(((Client*) getActual(movieClub->clients))->movies,j);
//            if(strcmp(excess.date,
//                    ((Movie*) getActual(((Client*) getActual(movieClub->clients))->movies)).)
            if(excess.timeStamp)
        }
        partialAmount +=
    }
}
//determinateExcess
void rewardClients(MovieClub* movieClub);
void freeExcess(Excess* excess);