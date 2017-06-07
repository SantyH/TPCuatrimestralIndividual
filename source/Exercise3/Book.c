//
// Created by Santiago Hazana on 5/31/17.
//

#include "Book.h"

Book* newBook(char* type, int code, char* author, char* title, int year, char* editorial){
    Book* book = malloc(sizeof(Book));
    book->editorial = editoral;
    book->material = newMaterial(type, code, author, title, year);
    return book;
}

void freeBook(Book* book){
    free(book->material->type);
    free(book->material->code);
    free(book->material->author);
    free(book->material->title);
    free(book->material->year);
    free(book->material->status);
    free(book->material);
    free(book->editorial);
    free(book);
}

void changeBookCode(Book* book, int code){
    book->material->code = code;
}