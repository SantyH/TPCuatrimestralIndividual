//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_STUDENT_H
#define TPCUATRIMESTRALINDIVIDUAL_STUDENT_H

#include "Person.h"

typedef struct student Student;

struct student{
    Person* person;
};

Student* newStudent();
void studentTakeMaterial();
void studentLeaveMaterial();

#endif //TPCUATRIMESTRALINDIVIDUAL_STUDENT_H
