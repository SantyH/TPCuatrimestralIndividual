//
// Created by Lucas on 9/6/2017.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_CAMERA_H
#define TPCUATRIMESTRALINDIVIDUAL_CAMERA_H

#include "Product.h"

typedef struct Camera{
    Product* product;
    int megapixels;
    int LCDScreen;
    int opticalZoom;
    char* type;
}Camera;
Camera* createCamera(char* name, char* code, double retailPrice,int megapixels, int LCDScreen, int opticalZoom, char* tipo);
void showCamera(Camera* camera);
void freeCamera(Camera*camera);

#endif //TPCUATRIMESTRALINDIVIDUAL_CAMERA_H