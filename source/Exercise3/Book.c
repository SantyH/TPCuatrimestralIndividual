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

void freeBook(){

}