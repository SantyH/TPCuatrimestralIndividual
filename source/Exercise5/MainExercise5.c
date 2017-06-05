//
// Created by Lucas on 2/6/2017.
//

#include <stdio.h>
#include <mem.h>
#include "MovieClub.h"
#include "../ScannerUtil/ScanUtil.h"
#include "Movie.h"
#include "Manager.h"

void MovieClubMain(MovieClub* movieClub);

void ManagerMain(MovieClub* movieClub, Manager* manager);

void ClientMain(MovieClub* movieClub, Client* client);

int main(){
    MovieClub* movieClub = createMovieClub();

    char* name;
    char* surname;
    int DNI;

    printf("%s\n","Insert name, surname amd DNI for manager in charge: ");
    name = scanChar();
    surname= scanChar();
    DNI=scanInt();
    Manager* manager = createManager(name,surname,DNI);

    int loop=1;
    while (loop){
        printf("%s\n%s\n%s\n%s\n",
               "1) MovieClub.",
               "2) Manager.",
               "3) Client.",
               "0) Close."
        );
        int command=0;
        scanf("%d",&command);
        switch (command){
            case 1:
                MovieClubMain(movieClub);
                break;
            case 2:
                ManagerMain(movieClub, manager);
                break;
            case 3:
                printf("%s\n","Insert your DNIAUX:");
                int DNIAUX = scanInt();
                for (int i = 0; i < movieClub->clients->size; ++i) {
                    goTo(movieClub->clients,i);
                    if(((Client*) getActual(movieClub->clients))->DNI == DNIAUX){
                        ClientMain(movieClub,((Client*) getActual(movieClub->clients)));
                        break;
                    }
                }
                break;
            case 0:
                for (int j = 0; j < movieClub->clients->size; ++j) {
                    goTo(movieClub->clients,j);
                    freeClient((Client*) getActual(movieClub->clients));
                }
                for (int k = 0; k < movieClub->movies->size; ++k) {
                    goTo(movieClub->movies,k);
                    freeMovie((Movie*) getActual(movieClub->movies));
                }
                for (int z = 0; z < movieClub->excesses->size; ++z) {
                    goTo(movieClub->excesses,z);
                    freeExcess((Excess*) getActual(movieClub->excesses));
                }
                freeManager(manager);
                freeMovieClub(movieClub);
                loop=0;
                break;
            default:break;
        }
    }
}
void MovieClubMain(MovieClub* movieClub){
   int loop=1;
   while (loop) {
       printf("%s\n%s\n%s\n",
              "1) Insert Movie to MovieClub.",
              "2) Change Movie price.",
              "0) Back."
       );
       int command = 0;
       scanf("%d", &command);
       switch (command) {
           case 1:
               printf("%s\n", "Insert title and amount for the Movie: ");
               goBack(movieClub->movies);
               addNext(movieClub->movies, createMovie(scanChar(), scanInt()));
               break;
           case 2:
               printf("%s\n", "Insert title for the Movie: ");
               char *title = scanChar();
               for (int i = 0; i < movieClub->movies->size; ++i) {
                   goTo(movieClub->movies, i);
                   if (strcmp(((Movie *) getActual(movieClub->movies))->title, title)) {
                       printf("%s\n", "Insert amount for the Movie: ");
                       changePrice((Movie *) getActual(movieClub->movies), scanInt());
                       break;
                   }
               }
               break;
           case 0:
               loop = 0;
               break;

           default:break;
       }
   }
}
 void ManagerMain(MovieClub* movieClub, Manager* manager){
    int loop=1;
    while (loop){
        printf("%s\n%s\n%s\n%s\n",
               "1) Register Client to MovieClub.",
               "2) Increase amount for client´s MovieCard.",
               "3) Generate Excess.",
               "0) Back."
        );
        int command=0;
        scanf("%d",&command);
        switch (command) {
            case 1:
                printf("%s\n","Insert client´s name, surname and DNI:");
                Client* client = createClient(scanChar(),scanChar(),scanInt());
                registerClient(movieClub,client);
                printf("%s\n","Insert amount for client´s MovieCard");
                generateMovieCard(client,scanInt());
                break;
            case 2:
                printf("%s\n","Insert DNI´s Client: ");
                int dni = scanInt();
                for (int i = 0; i < movieClub->clients->size; ++i) {
                    if(((Client*) getActual(movieClub->clients))->DNI==dni){
                        printf("%s\n","Insert amount: ");
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

void ClientMain(MovieClub* movieClub, Client* client){
    int loop=1;
    while (loop){
        printf("%s\n%s\n%s\n%s\n%s\n",
               "1) Pick up your Movies.",
               "2) Return Movie.",
               "3) Check available Movie.",
               "4) Check Movies Premiere.",
               "0) Back."
        );
        int command=0;
        scanf("%d",&command);
        switch (command) {
            case 1:
                pickUpMovies(client,movieClub->movies);
                break;
            case 2:
                printf("%s\n","Insert Movie title: ");
                returnMovie(client,movieClub,scanChar());
                break;
            case 3:
                printf("%s\n","Insert Movie title: ");
                char* title = scanChar();
                if (checkAvailableMovie(movieClub->movies,title)){
                    Movie* movie = NULL;
                    for (int i = 0; i < movieClub->movies->size; ++i) {
                        goTo(movieClub->movies,i);
                        if(strcmp(title,((Movie*) getActual(movieClub->movies))->title)){
                         movie= (Movie*) getActual(movieClub->movies);
                        }
                    }
                    printf("%s\n","Set any number if you want to rent this movie, else zero '0'.");
                    int rentBoolean = scanInt();
                    if(rentBoolean){
                        rentMovie(movie,client->movieCard->idMovieCard,client->movieCard->totalAmount);
                    }
                }
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

