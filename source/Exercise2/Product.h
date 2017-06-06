//
// Created by Lucas on 6/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_PRODUCT_H
#define TPCUATRIMESTRALINDIVIDUAL_PRODUCT_H

typedef struct Product{
    char* name;
    char* code;
    double retailPrice;
    //picture
}Product;

Product* createProduct(char* name, char* code, double retailPrice);
void freeProduct();
#endif //TPCUATRIMESTRALINDIVIDUAL_PRODUCT_H
