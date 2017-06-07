//
// Created by Santiago Hazana on 5/31/17.
//

#include "Magazine.h"


Magazine* newMagazine(char* type, int code, char* author, char* title, int year){
    Magazine* magazine = malloc(sizeof(Magazine));
    magazine->material = newMaterial(type, code, author, title, year);
    return magazine;
}

void freeMagazine(Magazine* magazine){
    free(magazine->material->type);
    free(magazine->material->code);
    free(magazine->material->author);
    free(magazine->material->title);
    free(magazine->material->year);
    free(magazine->material->status);
    free(magazine->material);
    free(magazine->editorial);
    free(magazine);
}

void changeMagazine(Magazine* magazine, int code){
    magazine->material->code = code;
}