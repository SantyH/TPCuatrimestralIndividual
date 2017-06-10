#include <malloc.h>
#include <stdio.h>
#include "Camera.h"

//
// Created by Lucas on 9/6/2017.
//
Camera* createCamera(char* name, char* code, double retailPrice, int megapixels, int LCDScreen, int opticalZoom, char* tipo){
    Camera* camera = malloc(sizeof(Camera));

    camera->product = createProduct( name, code, retailPrice);
    camera->megapixels = megapixels;
    camera->LCDScreen = LCDScreen;
    camera->opticalZoom = opticalZoom;
    camera->tipo = tipo;

    return camera;
}
void showCamera(Camera* camera){
    showInformation(camera->product);
    printf("%s%s\n %s%d\n %s%d\n %s%d\n","Camera type:", camera->tipo, "Megapixels: ",camera->megapixels,
    "LCD Screen:", camera->LCDScreen,"Optical zoom: ", camera->opticalZoom);
}
void freeCamera(Camera*camera){
    freeProduct(camera->product);
    free(camera);
}
