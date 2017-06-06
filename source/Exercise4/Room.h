//
// Created by Lucas on 6/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_ROOM_H
#define TPCUATRIMESTRALINDIVIDUAL_ROOM_H

#include "ClientHotel.h"

typedef struct Room{
    char* roomType;
    int roomNumber;
    double price;
    int clientDNIReservation;
    long expireDay;
    char* occupate;
}Room;

Room* createRoom(char* roomType, int roomNumber, double price);
void enterRoom(Room* room, int clientDNI);
double leaveRoom(Room* room);
void freeRoom(Room* room);
#endif //TPCUATRIMESTRALINDIVIDUAL_ROOM_H
