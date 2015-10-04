/* 
 * File:   hash_set.h
 * Author: gems
 *
 * Created on September 9, 2015, 11:20 AM
 */

#ifndef HASH_SET_H
#define	HASH_SET_H

#include "array_list.h"
#include <math.h>

typedef struct HashSet {
    ArrayList** table;
    int (*fcmp)(const void*, const void*);
    int (*fhash)(const void*);
    int size, allocated, expanded, next_to_expand;
};

HashSet* newHashSet(int (*fhash)(const void*), int (*fcmp)(const void*, const void*));
void addHS(HashSet* set, void* elem);
void removeHS(HashSet* set, void* elem);
int containsHS(HashSet* set, void* elem);
int sizeHS(HashSet* set);
Iterator* iteratorHS(HashSet* set);

#endif	/* HASH_SET_H */

