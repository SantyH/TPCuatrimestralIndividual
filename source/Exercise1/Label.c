//
// Created by Santiago Hazana on 6/7/17.
//

#include "Label.h"

Label* newLabel(int id, char* name){
    Label* label = malloc(sizeof(Label));
    label->id = id;
    label->name = name;
    return label;
}

void freeLabel(Label* label){
    free(label->name);
    free(label);
}