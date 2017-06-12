//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_BOOK_H
#define TPCUATRIMESTRALINDIVIDUAL_BOOK_H

#include "Material.h"

typedef struct Book Book;

struct Book{
    Material* material;
    char* editorial;
};

Book* newBook(char* type, int code, char* author, char* title, int year, char* editorial);
void changeBookCode(Book* book, int code);
void freeBook(Book* book);

#endif //TPCUATRIMESTRALINDIVIDUAL_BOOK_H
