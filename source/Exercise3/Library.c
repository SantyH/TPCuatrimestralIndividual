//
// Created by Santiago Hazana on 5/31/17.
//

#include <stdlib.h>
#include <printf.h>
#include "Library.h"


Library* newLibrary(){
    Library* library = malloc(sizeof(Library));
    library->materials = createStaticList(10, sizeof(Material*));
    library->persons = createStaticList(10, sizeof(Person*));
    library->materialCount = 0;
    library->personsIdCount = 0;
}

void loadMaterial(Library* library, Material* material){
    library->materialCount++;
    addNext(library->materials, material);
    printf("Material loaded\n");
}

void deleteMaterial(Library* library, int code){
    for (int i = 0; i < library->materials->size; ++i) {
        goTo(library->materials, i);
        if(((Material*)getActual(library->materials))->code == code){
            removeS(library->materials);
            printf("Material deleted\n");
            return;
        }
    }
    printf("No material with such code\n");
}

void loadPerson(Library* library, Person* person){
    library->personsIdCount++;
    addNext(library->persons, person);
    printf("Person loaded\n");
}

void deletePerson(Library* library, int id){
    for (int i = 0; i < library->persons->size; ++i) {
        goTo(library->persons, i);
        if(((Person*)getActual(library->persons))->enrollment == id){
            removeS(library->persons);
            printf("Person deleted");
            return;
        }
    }
    printf("No person with such id");
}

Material * getMaterial(Library *library, int code){
    for (int i = 0; i < library->materials->size; ++i) {
        goTo(library->materials, i);
        if(code == ((Material*)getActual(library->materials))->code)
            return getActual(library->materials);
    }
    printf("Material not found\n");
    return NULL;
}

void freeLibrary(Library* library){
    freeStaticList(library->persons);
    freeStaticList(library->materials);
    free(library);
}