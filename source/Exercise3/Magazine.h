//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MAGAZINE_H
#define TPCUATRIMESTRALINDIVIDUAL_MAGAZINE_H

#include "Material.h"

typedef struct Magazine Magazine;

struct Magazine{
    Material* material;
};

Magazine* newMagazine(char* type, int code, char* author, char* title, int year);
void freeMagazine(Magazine* magazine);
void changeMagazine(Magazine* magazine, int code);



#endif //TPCUATRIMESTRALINDIVIDUAL_MAGAZINE_H
