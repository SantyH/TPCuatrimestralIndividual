//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_PERSON_H
#define TPCUATRIMESTRALINDIVIDUAL_PERSON_H

typedef struct person Person;

struct person{
    char* personType;
    char* name;
    char* surName;
    char* email;
    int phone;
    int numberOfBooks;
    double toPay;
    int enrollment;
};

void takeMaterial(int code);
void leaveMaterial();

#endif //TPCUATRIMESTRALINDIVIDUAL_PERSON_H
