//
// Created by Lucas on 9/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_PERSONSHOP_H
#define TPCUATRIMESTRALINDIVIDUAL_PERSONSHOP_H
typedef struct PersonShop{
    char* name;
    int dni;
    char* address;
    int phone;
    char* location;
    char* province;
    char* country;
    char* postCode;
}PersonShop;

PersonShop* createPersonShop(char* name, int dni, char* address, int phone, char* location, char* province, char* country,char* postCode);
void freePersonShop(PersonShop* personShop);
#endif //TPCUATRIMESTRALINDIVIDUAL_PERSONSHOP_H
