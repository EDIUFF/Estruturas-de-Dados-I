#include "iterator.h"
Iterator* newIterator(void* collection, void*(* next)(const void*), int(* has_next)(const void*)){
    Iterator* new = (Iterator*) malloc(sizeof(Iterator));
    new->collection = collection;
    new->next = next;
    new->has_next = has_next;
}
void* nextI(Iterator* iterator){
    return iterator->next(iterator->collection);
}
int has_nextI(Iterator* iterator){
    return iterator->has_next(iterator->collection);
}
void destroyI(Iterator* iterator){
    free(iterator);
}