//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MATERIAL_H
#define TPCUATRIMESTRALINDIVIDUAL_MATERIAL_H


#include "../Structs/StaticList.h"

typedef struct Material Material;

struct Material{
    char* type;
    int code;
    char* author;
    char* title;
    int year;
    char* status;
};

Material* newMaterial(char* type, int code, char* author, char* title, int year);
void freeMaterial(Material* material);
void changeMaterialCode(Material* material, int code);

#endif //TPCUATRIMESTRALINDIVIDUAL_MATERIAL_H



