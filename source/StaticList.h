
/*
    Header file that defines the array -  based implementation of a List
*/

#ifndef STRUCTURES_STATICLIST_H
#define STRUCTURES_STATICLIST_H

#include <cstddef>

typedef struct staticList StaticList;

/* ~~~ Structs ~~~ */

struct staticList{

    int capacity;
    int size;
    void** array;
    size_t typeSize;
    int current;
};

/* ~~~ Function Prototypes ~~~ */

StaticList* createStaticList(int initialCapacity);
void freeStaticList(StaticList* list);
int size(StaticList* list);
int isEmpty(StaticList* list);
void forward(StaticList* list);
void backwards(StaticList* list);
void* getActual(StaticList* list);
int getPosition(StaticList* list);
void goFirst(StaticList* list);
void goBack(StaticList* list);
void goTo(StaticList* list, int positionToGo);
void addNext(StaticList* list, void* toAdd);
void addBefore(StaticList* list, void* toAdd);
int removeS(StaticList* list);


#endif //STRUCTURES_STATICLIST_H
