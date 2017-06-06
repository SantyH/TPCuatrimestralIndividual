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
void loadMaterial();
void deleteMaterial(int code);
void loadPerson();
void deletePerson(int id);
void freeLibrary();

#endif //TPCUATRIMESTRALINDIVIDUAL_LIBRARY_H
