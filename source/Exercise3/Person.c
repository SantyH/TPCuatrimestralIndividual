//
// Created by Santiago Hazana on 5/31/17.
//

#include "Person.h"
#include "Material.h"
#include "Library.h"

void newPerson(char* personType, char* name, char* surName, char* email, int phone, int enrollment){
    Person* person = malloc(sizeof(Person));
    person->personType = personType;
    person->name = name;
    person->surName = surName;
    person->email = email;
    person->phone = phone;
    person->enrollment = enrollment;
}


void takeMaterial(Person* person, Library* library, int code){
    person->material = library.getMaterial(code);
    person->loan = newLoan(person->material->code, person->enrollment);
}


void leaveMaterial(Person* person, Library* library){
    addNext(library->materialList, person->material);
    person->material = NULL;
    person->toPay = 0;
    freeLoan();
}