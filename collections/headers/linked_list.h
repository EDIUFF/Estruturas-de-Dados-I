/* 
 * File:   linked_list.h
 * Author: gems
 *
 * Created on September 9, 2015, 10:58 AM
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#include <stdlib.h>

typedef struct Node {
    void* info;
    struct Node* past;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* first;
    Node* last;
    int size;
    int (* fcmp)(const void*, const void*);
} LinkedList;

LinkedList* newLinkedList(int (* fcmp)(const void*, const void*));
void addLL(LinkedList* list, void* elem);
void add_inLL(LinkedList* list, void* elem);
void* getLL(LinkedList* list, int index);
void setLL(LinkedList* list, int index, void* elem);
void* remove_indexLL(LinkedList* list, int index);
int removeLL(LinkedList* list, void* elem);
int index_ofLL(LinkedList* list, void* elem);
int containsLL(LinkedList* list, void* elem);
int sizeLL(LinkedList* list);
void sortLL(LinkedList* list);

#endif	/* LINKED_LIST_H */

