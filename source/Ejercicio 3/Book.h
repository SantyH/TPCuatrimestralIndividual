//
// Created by Santiago Hazana on 5/31/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_BOOK_H
#define TPCUATRIMESTRALINDIVIDUAL_BOOK_H

#include "Material.h"

typedef struct book Book;

struct book{
    Material* material;
    char* editorial;
};

Book* newBook();
void unregisterBook();
void changeBook();

#endif //TPCUATRIMESTRALINDIVIDUAL_BOOK_H
