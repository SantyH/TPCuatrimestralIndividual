//
// Created by Lucas on 6/6/2017.
//

//#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "ClientHotel.h"
#include "Reservation.h"

ClientHotel* createClientHotel(char *name, char *surname, int DNI, double amount){
    ClientHotel* client = malloc(sizeof(ClientHotel));
    client->name=name;
    client->surname=surname;
    client->DNI=DNI;
    client->wallet=amount;
    return client;
}

void makeReservation(ClientHotel* client,Receptionist* receptionist,int roomNumber,int days){
    for (int i = 0; i < receptionist->rooms->size; ++i) {
        goTo(receptionist->rooms,i);
        if (((Room*)getActual(receptionist->rooms))->roomNumber==roomNumber ) {
            if ((client->wallet - ((Room *) getActual(receptionist->rooms))->price) > -1) {
                goBack(receptionist->reservations);
                addNext(receptionist->reservations,
                        createResearvation(client->name, client->surname, client->DNI,
                                           ((Room *) getActual(receptionist->rooms))->roomNumber, days));
                ((Room *) getActual(receptionist->rooms))->occupate = "RESERVE";
            } else {
                printf("%s\n", "You don´t have enough money!");
            }
        }
    }
}

void askForInformation(StaticList* rooms){
    for (int i = 0; i < rooms->size; ++i) {
        printf("%s%s\n %s%f\n ","Room type: ",((Room*)getActual(rooms))->roomType, "Room's number: ",((Room*)getActual(rooms))->price);
    }
}

void increaseWallet(ClientHotel *client, double amount){
    client->wallet += amount;
}

void freeClientHotel(ClientHotel* client){
    free(client);
}