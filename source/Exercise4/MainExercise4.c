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
    hotelName =  scanChar();
    StaticList* clients = createStaticList(5, sizeof(ClientHotel));
    char* name;
    char* surname;
    int DNI;

    printf("%s\n","Insert name, surname and DNI for receptionist in charge:");
    name = scanChar();
    surname= scanChar();
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
                    if(((ClientHotel*) getActual(clients))->DNI == DNI){
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
                name = scanChar();
                surname = scanChar();
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
        printf("\n %s\n %s\n %s\n %s\n %s\n  %s\n %s\n\n",
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
                for (int i = 0; i < receptionist->invoices->size; ++i) {
                    goTo(receptionist->invoices,i);
                    if(((Invoice*)getActual(receptionist->invoices))->clientDNI == client->DNI &&
                            strcmp (((Invoice*)getActual(receptionist->invoices))->payState,"NO PAYMENT")==0){
                        receptionist->income += payRoom(((Invoice*)getActual(receptionist->invoices)),client->wallet);
                        for (int j = 0; j < receptionist->rooms->size; ++j) {
                            goTo(receptionist->rooms,j);
                            if ( ((Room*)getActual(receptionist->rooms))->roomNumber == roomNumber ){
                                enterRoom(((Room*)getActual(receptionist->rooms)),client->DNI);
                                printf("%s\n","You enter to the room! ");
                                break;
                            }
                        }
                    }
                }
                printf("%s\n", "Invalid check in operation!");
                break;
            case 3:
                askForInformation(receptionist->rooms);
                break;
            case 4:
                printf("%s\n","Increase client's wallet: ");
                double amount = scanInt();
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
                roomType = scanChar();
                price = scanInt();
                goBack(receptionist->rooms);
                addNext(receptionist->rooms, createRoom(roomType, receptionist->rooms->size + 1, price));
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

