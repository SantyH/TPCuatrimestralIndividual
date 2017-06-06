//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MATERIAL_H
#define TPCUATRIMESTRALINDIVIDUAL_MATERIAL_H


typedef struct material Material;

struct material{
    char* type;
    int code;
    char* author;
    char* title;
    int year;
    char* status;
    StaticList materialList;
    StaticList personList;
};

Material* newMaterial(char* type, int code, char* author, char* title, int year);
void deleteMaterial(int code);
void changeMaterialCode(int code);

#endif //TPCUATRIMESTRALINDIVIDUAL_MATERIAL_H



