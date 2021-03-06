#include <stdio.h>
#include "../ScannerUtil/ScanUtil.h"
#include "stdlib.h"
#include "memory.h"
#include "Receptionist.h"
#include "ClientHotel.h"

void HotelAdministrationMain(Receptionist* receptionist,char *name);

void ClientHotelMain(ClientHotel *client, Receptionist* receptionist,char* hotelName);

//
// Created by Lucas on 6/6/2017.
//
int main(){
    printf("%s\n","Insert Hotel's name: ");
    char* hotelName;
    hotelName =  scanArrayOfChar();
    StaticList* clients = createStaticList(5, sizeof(ClientHotel));
    char* name;
    char* surname;
    int DNI;

    printf("%s\n","Insert name, surname and DNI for receptionist in charge:");
    name = scanArrayOfChar();
    surname= scanArrayOfChar();
    DNI=scanInt();
    Receptionist* receptionist = createReceptionist(name,surname,DNI);

    int loop=1;
    while (loop){
        printf("%s\n %s\n %s\n %s\n \n",
               "PRINCIPAL MENU",
               "1) Client.",
               "2) Hotel Administration.",
               "0) Close."
        );
        int command=0;
        command = scanInt();
        switch (command){
            case 1:
                printf("%s\n","Insert your DNI:");
                DNI = scanInt();
                for(int i=0; i<clients->size; ++i){
                    if(DNI == ((ClientHotel*) getActual(clients))->DNI){
                        if(receptionist->rooms->size>0){
                            ClientHotelMain(((ClientHotel*) getActual(clients)), receptionist,hotelName);
                        }
                        else{
                            printf("%s\n","There are no rooms loaded!");
                        }
                        break;
                    }
                }
                printf("%s\n %s\n","DNI not found! Initialize new Client:",
                "Insert name, surname and amount of Cash.");
                name = scanArrayOfChar();
                surname = scanArrayOfChar();
                double amount = scanInt();
                goBack(clients);
                addNext(clients, createClientHotel(name,surname,DNI,amount));
                if(receptionist->rooms->size>0) {
                    ClientHotelMain(((ClientHotel *) getActual(clients)), receptionist, hotelName);
                }else{
                    printf("%s\n","There are no rooms loaded!");
                }
                break;
            case 2:
                HotelAdministrationMain(receptionist,hotelName);
                break;
            case 0:
                freeReceptionist(receptionist);
                for (int j = 0; j < clients->size; ++j) {
                    goTo(clients,j);
                    freeClientHotel((ClientHotel*)getActual(clients));
                }
                freeStaticList(clients);
                loop=0;
                break;
            default:break;
        }
    }
}

void ClientHotelMain(ClientHotel *client, Receptionist* receptionist, char* hotelName) {
    int loop=1;
    int roomNumber;
    while (loop){
        printf("\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n\n",
               "CLIENT MENU",
               "1) Make reservation.",
               "2) Check in.",
               "3) Get rooms information.",
               "4) Increase wallet's client.",
               "5) Leave room.",
               "0) Back."
        );
        int command=0;
        command = scanInt();
        switch (command) {
            case 1:
                printf("%s\n","Insert room number for the reservation: ");
                roomNumber = scanInt();
                if (checkRoom(receptionist, roomNumber)) {
                    printf("%s\n","Insert quantity of days for the reservation: ");
                    int days = scanInt();
                    makeReservation(client, receptionist,roomNumber, days);
                } else{
                    printf("%s\n","Room not Found!");
                }
                break;
            case 2:
                printf("%s\n","Insert room number for check in: ");
                roomNumber=scanInt();
                checkIn(receptionist,hotelName,client->name,client->surname,client->DNI,roomNumber);
                char operation[] = "Invalid Operation!";
                for (int i = 0; i < receptionist->invoices->size; ++i) {
                    goTo(receptionist->invoices,i);
                    if(((Invoice*)getActual(receptionist->invoices))->clientDNI == client->DNI &&
                            strcmp (((Invoice*)getActual(receptionist->invoices))->payState,"NO PAYMENT")==0){
                        receptionist->income += payRoom(((Invoice*)getActual(receptionist->invoices)),client->wallet);

                        printf("%s\n", ((Invoice*)getActual(receptionist->invoices))->payState);

                        for (int j = 0; j < receptionist->rooms->size; ++j) {
                            goTo(receptionist->rooms,j);
                            if ( ((Room*)getActual(receptionist->rooms))->roomNumber == roomNumber ){
                                enterRoom(((Room*)getActual(receptionist->rooms)),client->DNI);
                                printf("%s\n","You enter to the room! ");
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            case 3:
                askForInformation(receptionist->rooms);
                break;
            case 4:
                printf("%s\n","Increase client's wallet: ");
                double amount = scanDouble();
                increaseWallet(client, amount);
            case 5:
                for (int k = 0; k < receptionist->rooms->size; ++k) {
                    goTo(receptionist->rooms, k);
                    if (((Room *) getActual(receptionist->rooms))->clientDNIReservation == client->DNI) {
                        double extraCost = leaveRoom( ((Room *) getActual(receptionist->rooms)));
                        receptionist->income += extraCost;
                        client->wallet -= extraCost;
                    }
                }
            case 0:
                loop = 0;
                break;
            default:break;
        }
    }
}

void HotelAdministrationMain(Receptionist* receptionist,char *name) {

    char *roomType;
    double price;
    int loop = 1;
    while (loop) {
        printf("\n %s\n %s\n %s\n %s\n %s\n \n",
               "HOTEL ADMINISTRATION MENU",
               "1) Insert room.",
               "2) Delete last room.",
               "3) Give information. ",
               "0) Back."
        );
        int command = 0;
        command = scanInt();
        switch (command) {
            case 1:
                printf("%s\n","Insert your room type and price:");
                roomType = scanArrayOfChar();
                price = scanDouble();
                goBack(receptionist->rooms);
                Room* room;
                room = createRoom(roomType, receptionist->rooms->size + 1, price);
                addNext(receptionist->rooms, room);
                break;
            case 2:
                goBack(receptionist->rooms);
                freeRoom(((Room *) getActual(receptionist->rooms)));
                removeS(receptionist->rooms);
                break;
            case 3:
                giveInformation(receptionist);
                break;
            case 0:
                loop = 0;
                break;
            default:
                break;
        }
    }
}

