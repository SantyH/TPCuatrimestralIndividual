//
// Created by Santiago Hazana on 5/31/17.
//

#include <stdlib.h>
#include "Person.h"
#include "Material.h"
#include "Library.h"
#include "Loan.h"

Person* newPerson(char* personType, char* name, char* surName, char* email, int phone, int enrollment){
    Person* person = malloc(sizeof(Person));
    person->personType = personType;
    person->name = name;
    person->surName = surName;
    person->email = email;
    person->phone = phone;
    person->enrollment = enrollment;
    return person;
}


void takeMaterial(Person* person, Library* library, int code){
    person->material = getMaterial(library, code);
    person->loan = newLoan(person->material->code, person->enrollment);
}


void leaveMaterial(Person* person, Library* library){
    addNext(library->materials, person->material);
    person->material = NULL;
    person->toPay = 0;
    freeLoan(person->loan);
}

void freePerson(Person* person){
    free(person->name);
    free(person->personType);
    free(person->surName);
    free(person->email);
    freeLoan(person->loan);
    freeMaterial(person->material);
    free(person);
}