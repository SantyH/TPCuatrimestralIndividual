//
// Created by Lucas on 6/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_CLIENT_H
#define TPCUATRIMESTRALINDIVIDUAL_CLIENT_H

#include "Receptionist.h"
#include "Room.h"

typedef struct ClientHotel{
    char* name;
    char* surname;
    int DNI;
    double wallet;
}ClientHotel;

ClientHotel* createClientHotel(char *name, char *surname, int DNI, double amount);
void makeReservation(ClientHotel* client,Receptionist* receptionist,int roomNumber,int days);
void askForInformation(StaticList* rooms);
void increaseWallet(ClientHotel *client, double amount);
void freeClientHotel(ClientHotel* client);
#endif //TPCUATRIMESTRALINDIVIDUAL_CLIENT_H
