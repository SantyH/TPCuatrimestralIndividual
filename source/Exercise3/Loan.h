//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_LOAN_H
#define TPCUATRIMESTRALINDIVIDUAL_LOAN_H

#include <time.h>

typedef struct Loan Loan;

struct Loan{
    int code;
    int id;
    time_t startDate;
};

Loan* newLoan(int code, int id);
double toPay(Loan* loan);
void freeLoan(Loan* loan);

#endif //TPCUATRIMESTRALINDIVIDUAL_LOAN_H
