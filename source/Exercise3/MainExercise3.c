//
// Created by Santiago Hazana on 6/6/17.
//

#include "Library.h"
#include "ScanUtil.h"
#include "Person.h"
#include "Material.h"

int main(){

    Library library = newLibrary();

    printf("%s\n%s\n%s\n%s\n\n",
           "Library: enter code to operate",
           "1. Login Library admin",
           "2. Login user",
           "0. Exit"
    );

    switch (command){

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

    loadPerson(newPerson(scanChar(), scanChar(), scanChar(), scanChar(), scanInt(), library->personsIdCount));
}