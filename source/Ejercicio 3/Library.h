//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_LIBRARY_H
#define TPCUATRIMESTRALINDIVIDUAL_LIBRARY_H

#include "LinkedList.h"

typedef struct library Library;

struct lirary{
    LinkedList* materials;
    LinkedList* persons;
    int personsIdCount;
    int materialCount;
};

void loadMaterial();
void deleteMaterial(int code);
void loadPerson();
void deletePerson(int id);

#endif //TPCUATRIMESTRALINDIVIDUAL_LIBRARY_H
