//
// Created by Lucas on 6/6/2017.
//

#include <malloc.h>
#include <stdio.h>
#include "memory.h"
#include "Receptionist.h"
#include "Reservation.h"
#include "Room.h"


Receptionist* createReceptionist(char* name,char* surname, int DNI){
    Receptionist* receptionist = malloc(sizeof(Receptionist));
    receptionist->income = 0;
    receptionist->name=name;
    receptionist->surname=surname;
    receptionist->DNI=DNI;
    receptionist->reservations= createStaticList(10, sizeof(Reservation));
    receptionist->rooms= createStaticList(15, sizeof(Room));
    receptionist->invoices= createStaticList(2, sizeof(Invoice));
    return receptionist;
}

void giveInformation(Receptionist* receptionist){
    for (int i = 0; i < receptionist->rooms->size; ++i) {
        printf("%s%s\n %s%d\n %s%f\n","Room type: ",((Room*)getActual(receptionist->rooms))->roomType,
               "Room's number: ",((Room*)getActual(receptionist->rooms))->roomNumber,
               "Room's price: ",((Room*)getActual(receptionist->rooms))->price);
    }
    for (int j = 0; j < receptionist->invoices->size; ++j) {
        printf("%s%s\n %s%s\n %s%d\n",
               "Date: ",((Invoice*)getActual(receptionist->invoices))->invoiceDate,
                "Invoice State: ", ((Invoice*)getActual(receptionist->invoices))->payState,
               "Client DNI: ", ((Invoice*)getActual(receptionist->invoices))->clientDNI
        );
    }
    for (int k = 0; k < receptionist->reservations->size; ++k) {
        printf("%s%s\n %s%d\n %s%d\n",
               "Client Surname: ",((Reservation*)getActual(receptionist->reservations))->clientSurname,
               "Client DNI: ", ((Reservation*)getActual(receptionist->reservations))->clientDNI,
               "Room number: ", ((Reservation*)getActual(receptionist->reservations))->roomNumber
        );
    }
}

int checkRoom(Receptionist* receptionist,int number){
    if(receptionist->rooms->size>0){
        for (int i = 0; i < receptionist->rooms->size; ++i) {
            goTo(receptionist->rooms,i);
            if( ((Room*)getActual(receptionist->rooms))->roomNumber == number &&
                    strcmp( ((Room*)getActual(receptionist->rooms))->occupate,"FREE") == 0){
                printf("%s\n","Room found and it´s available!");
                return 1;
            }
        }
    }
    return 0;
}

void checkIn(Receptionist* receptionist,char* hotelName, char* clientName ,char* clientSurname, int clientDNI, int roomNumber){
    for (int i = 0; i < receptionist->reservations->size; ++i) {
        goTo(receptionist->reservations,i);
        if( ((Reservation*)getActual(receptionist->reservations))->clientDNI == clientDNI){
            printf("%s\n","Reservation found!");
            for (int j = 0; j < receptionist->rooms->size; ++j) {
                if(roomNumber == ((Room*)getActual(receptionist->rooms))->roomNumber){
                    printf("%s\n","Room found!");
                    goBack(receptionist->invoices);
                    addNext(receptionist->invoices, createInvoice(getPosition(receptionist->invoices),hotelName,clientName,clientSurname,
                                                                  clientDNI,((Room*)getActual(receptionist->rooms))->roomNumber));
                    printf("%s\n","Invoice add!");
                }
            }
        }
    }
}

void freeReceptionist(Receptionist* receptionist){
    for (int i = 0; i < receptionist->rooms->size; ++i) {
        goTo(receptionist->rooms,i);
        freeRoom(((Room*)getActual(receptionist->rooms)));
    }
    for (int i = 0; i < receptionist->reservations->size; ++i) {
        goTo(receptionist->reservations,i);
        freeReservation(((Reservation*)getActual(receptionist->reservations)));
    }
    for (int i = 0; i < receptionist->invoices->size; ++i) {
        goTo(receptionist->invoices,i);
        freeRoom(((Room*)getActual(receptionist->invoices)));
    }
    free(receptionist->rooms);
    free(receptionist->reservations);
    free(receptionist->invoices);
    free(receptionist);
}