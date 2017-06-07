//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_LIBRARY_H
#define TPCUATRIMESTRALINDIVIDUAL_LIBRARY_H

#include "LinkedList.h"

typedef struct library Library;

struct library{
    StaticList* materials;
    StaticList* persons;

    int personsIdCount;
    int materialCount;
};

Library* newLibrary();
void loadMaterial(Library* library, Material* material);
void deleteMaterial(Library* library, int code);
void loadPerson(Library* library, Person* person);
void deletePerson(Library* library, int id);
void freeLibrary(Library* library);

#endif //TPCUATRIMESTRALINDIVIDUAL_LIBRARY_H
