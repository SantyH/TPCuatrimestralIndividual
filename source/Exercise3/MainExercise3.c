//
// Created by Santiago Hazana on 6/6/17.
//

#include "Library.h"
#include "../ScannerUtil/ScanUtil.h"
#include "Person.h"
#include "Material.h"
#include "Book.h"
#include "Magazine.h"
#include "../Structs/StaticList.h"

int main(){

    Library library = newLibrary();
    int operate = 1;
    while(operate) {
        printf("%s\n%s\n%s\n%s\n\n",
               "Library: enter code to operate",
               "1. Login Library admin",
               "2. Login user",
               "0. Exit"
        );
        int command = scanInt();

        switch (command){
            case 1:
                admin();
                break;
            case 2:
                user();
                break;
            case 0:
                freeLibrary(library);
                operate = 0;
                break;
            default:
                break;
        }

    }
}

void createPerson(Library* library){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n\n",
           "Please enter:",
           "Person type",
           "Name",
           "Surname",
           "Email",
           "Phone"
    );

    loadPerson(library, newPerson(scanChar(), scanChar(), scanChar(), scanChar(), scanInt(), library->personsIdCount));
}

void createMaterial(Library* library){
    printf("%s\n%s\n%s\n%s\n%s\n",
           "Please enter:",
           "Material type",
           "Author",
           "Title",
           "Year"
    );
    char* materialType = scanChar();

    if(strcmp(materialType, "book")){
        printf("Editorial");
        loadMaterial(library, newBook(scanChar(), library->materialCount, scanChar(), scanChar(), scanInt(), scanChar()));
    }else{
        loadMaterial(library, newMagazine(scanChar(), library->materialCount, scanChar(), scanChar(), scanInt()));
    }

    loadMaterial(library, newMaterial(materialType, library->materialCount, scanChar(), scanChar(), scanChar()));
}

void admin(Library* library){

    int operate = 1;
    while (operate){
        printf("%s\n%s\n%s\n%s\n\n",
               "Library: enter code to operate",
               "1. Load Material",
               "2. Delete Material",
               "3. Get Materials",
               "4. Delete user",
               "0. Exit"
        );

        int command = scanInt();

        switch (command){
            case 1:
                createMaterial(library);
                break;
            case 2:
                printf("Enter material code to delete\n");
                deleteMaterial(scanInt());
                break;
            case 3:
                for (int i = 0; i < library->materials->size; ++i) {
                    goTo(library->materials, i);
                    printf("%i\n%s\n%s\n%s\n%s\n\n",
                           (Material)getActual(library->materials)->code,
                           (Material)getActual(library->materials)->type,
                           (Material)getActual(library->materials)->title,
                           (Material)getActual(library->materials)->author,
                           (Material)getActual(library->materials)->status
                    );
                }
                break;
            case 4:
                printf("Enter person id to delete\n");
                deletePerson(scanInt());
                break;
            case 0:
                operate = 0;
                break;
            default:
                printf("Enter a valid command\n");
                break;
        }
    }

}

void user(){

}