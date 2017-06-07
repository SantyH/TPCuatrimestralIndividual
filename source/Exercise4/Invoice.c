//
// Created by Lucas on 6/6/2017.
//

//#include <malloc.h>
#include <time.h>
//#include <mem.h>
#include <stdlib.h>
#include <memory.h>
#include "Invoice.h"

Invoice* createInvoice(int invoiceNumber,char* hotelName, char* clientName,char* clientSurname ,int clientDNI, double amountToPay){
    Invoice* invoice = malloc(sizeof(Invoice));
    invoice->hotelName= hotelName;
    invoice->clientName= clientName;
    invoice->clientSurname= clientSurname;
    invoice->clientDNI= clientDNI;
    invoice->invoiceNumber= invoiceNumber;
    invoice->amountToPay = amountToPay;
    invoice->payState = "NO PAYMENT";

    time_t calendarTime;
    time(&calendarTime);

    invoice->invoiceDate = malloc(sizeof(char *));
    strcpy(invoice->invoiceDate, ctime(&calendarTime));

    return invoice;
}

double payRoom(Invoice* invoice, double clientCash){
    if(strcmp(invoice->payState,"NO PAYMENT")==0 && clientCash>=invoice->amountToPay) {
        invoice->payState = "PAYMENT";
        return invoice->amountToPay;
    }
    return 0;
}

void freeInvoice(Invoice* invoice){
    free(invoice);
}