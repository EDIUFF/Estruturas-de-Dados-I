/* 
 * File:   hash_map.h
 * Author: gems
 *
 * Created on September 9, 2015, 10:58 AM
 */

#ifndef HASH_MAP_H
#define	HASH_MAP_H

#include "hash_set.h"

typedef struct Pair {
    void* key;
    void* value;
    HashMap* map;
};

typedef struct HashMap {
    ArrayList** table;
    int size, allocated, expanded, next_to_expand;
    int(*fhash_key)(const void*);
    int(*fcmp_key)(const void*, const void*);
    int(*fcmp_value)(const void*, const void*);
} HashMap;

HashMap* newHashMap(int(*hash_key)(const void*), int(*fcmp_key)(const void*, const void*), int(*fcmp_value)(const void*, const void*));
void putHM(HashMap* map, void* key, void* value); // da replace se tiver
void* removeHM(HashMap* map, void* key);
void* getHM(HashMap* map, void* key);
int hasKey(HashMap* map, void* key);
int hasValue(HashMap* map, void* value);
Iterator* keys(HashMap* map);
Iterator* values(HashMap* map);

#endif	/* HASH_MAP_H */

