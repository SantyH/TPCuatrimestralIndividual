//
// Created by Santiago Hazana on 5/31/17.
//

#include "Loan.h"

Loan* newLoan(int code, int id){
    Loan* loan = malloc(sizeof(Loan));
    loan->code = code;
    loan->id = id;
    loan->startDate = time(0);
}

double toPay(Loan* loan){
    time_t endDate = time(0);

    double minutesDiff = difftime(loan->startDate, endDate)/60; //difference in minutes, every minute counts as real days

    if(minutesDiff > 5)
        return (minutesDiff-5)*10; // free limit is 5 days (here in minutes) after that they get charged $10 per day.

    return 0;
}

void freeLoan(Loan* loan){
    free(loan->code);
    free(loan->startDate);
    free(loan->id);
    free(loan);
}