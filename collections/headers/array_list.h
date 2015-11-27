/* 
 * File:   array_list.h
 * Author: gems
 *
 * Created on September 9, 2015, 10:57 AM
 */

#ifndef ARRAY_LIST_H
#define	ARRAY_LIST_H
#include <stdlib.h>

#include "iterator.h"

typedef struct ArrayList {
    void* array;
    int allocated, size;
    int (*fcmp)(void *, void *);
} ArrayList;

ArrayList* newArrayList(int (* fcmp)(const void*, const void*));
void addAL(ArrayList* list, void* elem);
void add_inAL(ArrayList* list, void* elem, int index);
void* getAL(ArrayList* list, int index);
void setAL(ArrayList* list, int index, void* elem);
void* remove_indexAL(ArrayList* list, int index);
void* removeAL(ArrayList* list, void* elem);
int index_ofAL(ArrayList* list, void* elem);
int containsAL(ArrayList* list, void* elem);
int sizeAL(ArrayList* list);
void sortAL(ArrayList* list);
Iterator* iteratorAL(ArrayList* list);
void destroyAL(ArrayList* list);

#endif	/* ARRAY_LIST_H */

