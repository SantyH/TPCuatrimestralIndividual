//
// Created by Lucas on 2/6/2017.
//

#include <stdio.h>
#include "MovieClub.h"
#include "../ScannerUtil/ScanUtil.h"
#include "Movie.h"
#include "Manager.h"

int main(){
    MovieClub* movieClub = createMovieClub();

    char* name;
    char* surname;
    int DNI;

    printf("%s","Insert name, surname amd DNI for manager in charge: ");
    scanf("%s",&name);
    scanf("%s",&surname);
    scanf("%d",&DNI);

//    Manager* manager = createManager(name,surname,DNI);
    Manager* manager = createManager(scanChar(),scanChar(),scanInt());


//    Movie* movie = createMovie("pelicula",15);

    int loop=1;
    while (loop){
        printf("%s","1) Insert Movie to MovieClub.");
        int command=0;
        scanf("%d",&command);
        switch (command){
            case 1:
                char* title;
                scanf("%s", title);
                double price;
                scanf("%lf",&price);
                createMovie(title,price);
                break;
            case 2:


        }
    }
}

static void ClientMain(MovieClub* movieClub, Client* client){
    int loop=1;
    while (loop){
        printf("%s\n","1)");
        int command=0;
        scanf("%d",&command);
        switch (command) {
            case 1:
                pickUpMovies(client,movieClub->movies);
                break;
            case 2:
                printf("%s","Insert Movie title: ");
                returnMovie(client,movieClub,scanChar());
                break;
            case 3:
                printf("%s","Insert Movie title: ");
                checkAvailableMovie(movieClub->movies,scanChar());
                break;
            case 4:
                checkMoviePremiere(movieClub->movies);
                break;
            case 5:
                showMovies(movieClub->movies);
                break;
            case 0:
                loop=0;
                break;
            default:break;
        }
    }
}

static void ManagerMain(MovieClub* movieClub){
    int loop=1;
    while (loop){
        printf("%s","1) Register Client to MovieClub.");
        int command=0;
        scanf("%d",&command);
        switch (command) {
            case 1:
                printf("%s","Insert client´s name, surname and DNI:");
                Client* client = createClient(scanChar(),scanChar(),scanInt());
                registerClient(movieClub,client);
                printf("%s","Insert amount for client´s MovieCard");
                generateMovieCard(client,scanInt());
                break;
            case 2:
                printf("%s","Increase amount for client´s MovieCard. Insert DNI´s Client: ");
                int dni = scanInt();
                for (int i = 0; i < movieClub->clients->size; ++i) {
                    if(((Client*) getActual(movieClub->clients))->DNI==dni){
                        printf("%s","Insert amount: ");
                        increaseAmountMovieCard(((Client*) getActual(movieClub->clients))->movieCard,scanInt());
                        break;
                    }
                }
                break;
            case 3:
                generateExcess(movieClub);
                break;
            case 0:
                loop=0;
                break;
            default:break;
        }
    }
}

static void MovieClubMain(MovieClub* movieClub){
    int loop=1;
    while (loop){
        printf("%s","1) Add Movie to MovieClub.", 2);
        int command=0;
        scanf("%d",&command);
        switch (command) {

        }
    }
}