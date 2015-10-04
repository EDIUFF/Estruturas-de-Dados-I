/* 
 * File:   ArrayDeque.h
 * Author: gems
 *
 * Created on September 9, 2015, 11:09 AM
 */

#ifndef ARRAYDEQUE_H
#define	ARRAYDEQUE_H

#include "iterator.h"

typedef struct ArrayDeque{
    void* array;
    int size, allocated;
    int (*fcmp)(const void*, const void*);
    int next;
}ArrayDeque;

ArrayDeque* newArrayDeque(int (*fcmp)(const void*, const void*));
void pushAD(ArrayDeque* deque, void* elem);
void* popAD(ArrayDeque* deque);
void addAD(ArrayDeque* deque, void* elem);
void* removeAD(ArrayDeque* deque);
void* peek_lastAD(ArrayDeque* deque);
void* poll_lastAD(ArrayDeque* deque);
void* peek_firstAD(ArrayDeque* deque);
void* poll_firstAD(ArrayDeque* deque);
int containsAD(ArrayDeque* deque, void* elem);
int sizeAD(ArrayDeque* deque);
Iterator* iteratorAD(ArrayDeque* deque);
#endif	/* ARRAYDEQUE_H */

