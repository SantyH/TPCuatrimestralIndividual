//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_STUDENT_H
#define TPCUATRIMESTRALINDIVIDUAL_STUDENT_H

#include "Person.h"

typedef struct Student Student;

struct Student{
    Person* person;
};

Student* newStudent(char* personType, char* name, char* surName, char* email, int phone, int enrollment);
void studentTakeMaterial(Student* student, Library* library , int code);
void studentLeaveMaterial(Student* student, Library* library);
void freeStudent(Student* student);

#endif //TPCUATRIMESTRALINDIVIDUAL_STUDENT_H
