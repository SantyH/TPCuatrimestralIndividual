//
// Created by Santiago Hazana on 5/31/17.
//

#include "Book.h"

Book* newBook(char* editorial, char* type, int code, char* author, char* title, int year){
    Book* book = malloc(sizeof(Book));
    book->editorial = editoral;
    book->material->type = type;
    book->material->code = code;
    book->material->author = author;
    book->material->title = title;
    book->material->year = year;
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

void changeBook(Book* book, int code){
    book->material->code = code;
}