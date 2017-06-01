//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_LOAN_H
#define TPCUATRIMESTRALINDIVIDUAL_LOAN_H

typedef struct loan Loan;

struct loan{
    int code;
    int id;
    char* startDate;
    char* endDate;
};

double toPay();

#endif //TPCUATRIMESTRALINDIVIDUAL_LOAN_H
