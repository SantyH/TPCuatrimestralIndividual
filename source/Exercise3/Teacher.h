//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_TEACHER_H
#define TPCUATRIMESTRALINDIVIDUAL_TEACHER_H

#include "Person.h"
#include "Library.h"

typedef struct Teacher Teacher;

struct Teacher{
    Person* person;
};

Teacher* newTeacher(char* personType, char* name, char* surName, char* email, int phone, int enrollment);
void teacherTakeMaterial(Teacher* teacher, Library* library ,int code);
void teacherLeaveMaterial(Teacher* teacher, Library* library);

#endif //TPCUATRIMESTRALINDIVIDUAL_TEACHER_H
