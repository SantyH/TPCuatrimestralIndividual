//
// Created by Santiago Hazana on 5/31/17.
//

#include <stdlib.h>
#include "Magazine.h"


Magazine* newMagazine(char* type, int code, char* author, char* title, int year){
    Magazine* magazine = malloc(sizeof(Magazine));
    magazine->material = newMaterial(type, code, author, title, year);
    return magazine;
}

void freeMagazine(Magazine* magazine){
    free(magazine->material->type);
    free(magazine->material->author);
    free(magazine->material->title);
    free(magazine->material->status);
    free(magazine->material);
    free(magazine);
}

void changeMagazineCode(Magazine *magazine, int code){
    magazine->material->code = code;
}