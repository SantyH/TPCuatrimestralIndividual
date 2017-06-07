//
// Created by Lucas on 6/6/2017.
//
#include <stdio.h>
#include <time.h>
#include "stdlib.h"
//#include "memory.h"
#include "Room.h"
Room* createRoom(char* roomType, int roomNumber, double price){
    Room* room = malloc(sizeof(Room));
    room->roomType=roomType;
    room->roomNumber = roomNumber;
    room->price = price;
    room->occupate = "FREE";
    return room;
}

void enterRoom(Room* room, int clientDNI){
    room->clientDNIReservation= clientDNI;
    room->occupate = "OCCUPIED";
}

double leaveRoom(Room* room){
    time_t currentTime = time(NULL);
    long timeStampToday = currentTime;

    double secondsDiff =0;
    if(room->expireDay < timeStampToday){

        double extraDays = (difftime(room->expireDay, timeStampToday))/ 86400 ;

        room->occupate = "FREE";
        room->clientDNIReservation=0;

        return extraDays*room->price;
    }
    room->clientDNIReservation=0;
    room->occupate = "FREE";
    return 0;
}

void freeRoom(Room* room){
    free(room);
}