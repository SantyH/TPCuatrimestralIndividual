//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_TEACHER_H
#define TPCUATRIMESTRALINDIVIDUAL_TEACHER_H

#include "Person.h"

typedef struct teacher Teacher;

struct teacher{
    Person* person;
};

void teacherTakeMaterial();
void teacherLeaveMaterial();

#endif //TPCUATRIMESTRALINDIVIDUAL_TEACHER_H
