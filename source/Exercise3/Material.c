//
// Created by Santiago Hazana on 5/31/17.
//

#include "Material.h"

Material* newMaterial(char* type, int code, char* author, char* title, int year){
    Material* material = malloc(sizeof(Material));
    material->type = type;
    material->code = code;
    material->author = author;
    material->title = title;
    material->year = year;
    material->status = "free";
}
void changeMaterial(Material* material){

}

void deleteMaterial(Material* material){
    free(material->type);
    free(material->code);
    free(material->author);
    free(material->title);
    free(material->year);
    free(material->status);
    free(material);
}
