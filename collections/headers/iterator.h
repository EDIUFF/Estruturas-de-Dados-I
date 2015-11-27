/* 
 * File:   iterator.h
 * Author: gems
 *
 * Created on September 20, 2015, 6:24 PM
 */

#ifndef ITERATOR_H
#define	ITERATOR_H

#include <stdlib.h>

typedef struct Iterator {
    void* collection;
    void*(* next)(const void*);
    int(* has_next)(const void*);
} Iterator;

Iterator* newIterator(void*(* next)(const void*), int(* has_next)(const void*));
void* nextI(Iterator* iterator);
int has_nextI(Iterator* iterator);
void destroyI(Iterator* iterator);
#endif	/* ITERATOR_H */

