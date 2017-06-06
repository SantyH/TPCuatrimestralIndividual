//
// Created by Lucas on 6/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_RESERVATION_H
#define TPCUATRIMESTRALINDIVIDUAL_RESERVATION_H
typedef struct Reservation{
    char* clientName;
    char* clientSurname;
    int clientDNI;
    int roomNumber;
    long daysInSeconds;
}Reservation;

Reservation* createResearvation(char* clientName, char* clientSurname, int clientDNI, int roomNumber, int numberOfDays);
void freeReservation(Reservation* reservation);
#endif //TPCUATRIMESTRALINDIVIDUAL_RESERVATION_H
