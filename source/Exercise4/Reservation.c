//
// Created by Lucas on 6/6/2017.
//

//#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include "Reservation.h"

Reservation* createResearvation(char* clientName, char* clientSurname, int clientDNI, int roomNumber, int numberOfDays){
    Reservation* reservation = malloc(sizeof(Reservation));
    reservation->clientName = clientName;
    reservation->clientSurname = clientSurname;
    reservation->clientDNI = clientDNI;
    reservation->roomNumber = roomNumber;

    time_t currentTime = time(NULL);
    reservation->daysInSeconds=currentTime + (86400*numberOfDays); // 1 day == 86400 seconds
}
void freeReservation(Reservation* reservation){
    free(reservation->clientName);
    free(reservation->clientSurname);
    free(reservation);
}