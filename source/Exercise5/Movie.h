//
// Created by Lucas on 4/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_MOVIE_H
#define TPCUATRIMESTRALINDIVIDUAL_MOVIE_H


typedef struct Movie{
    char* title;
    double price;
    int idMovieCard;
    char* rentDate;
    char* devolutionDate;
    long timeStamp;
} Movie;

Movie* createMovie(char* title, double price);
void changePrice(Movie *movie, double price);
void isAvailable(Movie* movie);
//void rentMovie(Movie* movie,Client* client);
double rentMovie(Movie* movie, int idMovieCard, double amount);
void freeMovie(Movie* movie);

#endif //TPCUATRIMESTRALINDIVIDUAL_MOVIE_H
