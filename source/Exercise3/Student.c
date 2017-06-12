//
// Created by Santiago Hazana on 5/31/17.
//

#include <stdlib.h>
#include "Student.h"
#include "Library.h"

Student* newStudent(char* personType, char* name, char* surName, char* email, int phone, int enrollment){
    Student* student = malloc(sizeof(Student));
    student->person->personType = personType;
    student->person->name = name;
    student->person->surName = surName;
    student->person->email = email;
    student->person->phone = phone;
    student->person->enrollment = enrollment;

}

void studentTakeMaterial(Student* student, Library* library ,int code){
    takeMaterial(student->person, library, code);
}

void studentLeaveMaterial(Student* student, Library* library){
    leaveMaterial(student->person, library);
}

void freeStudent(Student* student){
    free(student->person->name);
    free(student->person->personType);
    free(student->person->surName);
    free(student->person->email);
    freeLoan(student->person->loan);
    freeMaterial(student->person->material);
    freePerson(student->person);
    free(student);
}