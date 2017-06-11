//
// Created by Santiago Hazana on 6/7/17.
//

#ifndef TPCUATRIMESTRALINDIVIDUAL_LABEL_H
#define TPCUATRIMESTRALINDIVIDUAL_LABEL_H

typedef struct Label Label;

struct Label{
    int id;
    char* name;
};

Label* newLabel(int id, char* name);
void freeLabel(Label* label);

#endif //TPCUATRIMESTRALINDIVIDUAL_LABEL_H
