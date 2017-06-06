//
// Created by Santiago Hazana on 5/31/17.
//

#include "Library.h"
#include "Material.h"
#include "Person.h"

Library* newLibrary(){
    Library* library = malloc(sizeof(Library));
    library->materials = createLinkedList(10, sizeof(Material));
    library->persons = createLinkedList(10, sizeof(Person));
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
        if((Material)goTo(library->materials, i)->code == code){
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
        if((Person)goTo(library->persons, i)->code == id){
            removeS(library->persons);
            printf("Person deleted");
            return;
        }
    }
    printf("No person with such id");
}

void freeLibrary(Library* library){
    free(library->personsIdCount);
    free(library->materialCount);
    freeStaticList(library->persons);
    freeStaticList(library->materials);
    free(library);
}