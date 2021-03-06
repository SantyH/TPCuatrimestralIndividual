//
// Created by Santiago Hazana on 5/31/17.
//

#include <stdlib.h>
#include "Teacher.h"
#include "Student.h"
#include "Library.h"

Teacher* newTeacher(char* personType, char* name, char* surName, char* email, int phone, int enrollment){
    Teacher* teacher = malloc(sizeof(Student));
    teacher->person->personType = personType;
    teacher->person->name = name;
    teacher->person->surName = surName;
    teacher->person->email = email;
    teacher->person->phone = phone;
    teacher->person->enrollment = enrollment;

}

void teacherTakeMaterial(Teacher* teacher, Library* library ,int code){
    takeMaterial(teacher->person, library, code);
}

void teacherLeaveMaterial(Teacher* teacher, Library* library){
    leaveMaterial(teacher->person, library);
}

void freeTeacher(Teacher* teacher){
    free(teacher->person->name);
    free(teacher->person->personType);
    free(teacher->person->surName);
    free(teacher->person->email);
    freeLoan(teacher->person->loan);
    freeMaterial(teacher->person->material);
    freePerson(teacher->person);
    free(teacher);
}