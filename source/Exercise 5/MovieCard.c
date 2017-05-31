//
// Created by Lucas on 30/5/2017.
//

#include <stdlib.h>
#include "MovieCard.h"


MovieCard* createMovieCard(int id, int amount){
    MovieCard* movieCard = malloc(sizeof(MovieCard));
    movieCard->id=id;
    movieCard->totalAmount=amount;
    movieCard->movies = createLinkedList();

}
//void checkAvailableMovie(MovieCard* movieCard, char movieTitle[]){
//    for(int i=0; i<movieCard->movies->size;i++){
//        if(mo)
//    }
//}
//void checkMoviePremiere(MovieCard* movieCard);
void freeMovieCard(MovieCard* movieCard);