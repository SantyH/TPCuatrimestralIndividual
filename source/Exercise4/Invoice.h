//
// Created by Lucas on 6/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_INVOICE_H
#define TPCUATRIMESTRALINDIVIDUAL_INVOICE_H

typedef struct Invoice{
    int invoiceNumber;

    char* hotelName;
    char* clientName;
    char* clientSurname;
    int clientDNI;
    double amountToPay;
    char* payState;
    char* invoiceDate;
}Invoice;

Invoice* createInvoice(int invoiceNumber, char* hotelName, char* clientName, char* clientSurname, int clientDNI, double amountToPay);
double payRoom(Invoice* invoice, double clientCash);
void freeInvoice(Invoice* invoice);
#endif //TPCUATRIMESTRALINDIVIDUAL_INVOICE_H
