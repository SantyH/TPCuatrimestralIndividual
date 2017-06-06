//
// Created by Lucas on 6/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_RECEPTIONIST_H
#define TPCUATRIMESTRALINDIVIDUAL_RECEPTIONIST_H

#include "../Structs/StaticList.h"
#include "Invoice.h"

typedef struct Receptionist{
    char* name;
    char* surname;
    int DNI;
    double income;
    StaticList* reservations;
    StaticList* rooms;
    StaticList* invoices;
}Receptionist;

Receptionist* createReceptionist(char* name,char* surname, int DNI);
void giveInformation(Receptionist* receptionist);
int checkRoom(Receptionist* receptionist,int number);
void checkIn(Receptionist* receptionist,char* hotelName, char* clientName ,char* clientSurname, int clientDNI, int roomNumber);
void freeReceptionist(Receptionist* receptionist);
#endif //TPCUATRIMESTRALINDIVIDUAL_RECEPTIONIST_H
