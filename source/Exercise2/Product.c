//
// Created by Lucas on 6/6/2017.
//

#include <malloc.h>
#include <stdio.h>
#include "Product.h"

Product* createProduct(char* name, char* code, double retailPrice){
    Product* product = malloc(sizeof(Product));

    product->name= name;
    product->retailPrice=retailPrice;
    product->code= code;
}

void showInformation(Product* product){
    printf("%s%s\n %s%s\n %s%lf\n","Product: ", product->name, "Code: ", product->code, "Retail price:", product->retailPrice);
}

void freeProduct(Product* product){
    free(product);
}