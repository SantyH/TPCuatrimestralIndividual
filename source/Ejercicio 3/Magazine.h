//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MAGAZINE_H
#define TPCUATRIMESTRALINDIVIDUAL_MAGAZINE_H

#include "Material.h"

typedef struct magazine Magazine;

struct magazine{
    Material* material;
};

Magazine* newMagazine();
void unregisterMagazine();
void changeMagazine();



#endif //TPCUATRIMESTRALINDIVIDUAL_MAGAZINE_H
