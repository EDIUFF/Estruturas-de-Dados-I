#include "../headers/array_deque.h"

ArrayDeque* newArrayDeque(int (*fcmp)(const void*, const void*)) {
    ArrayDeque* new = (ArrayDeque*) malloc(sizeof (ArrayDeque));
    new->array = (void**) malloc(sizeof (void*)*11);
    new->allocated = 11;
    new->size = 0;
    new->next = 0;
    return new;
}

void pushAD(ArrayDeque* deque, void* elem) {
    if (deque->size == (deque->allocated - 1)) {
        deque->allocated *= 2;
        deque->array = (void**) realloc(sizeof (void*)*deque->allocated);
    }
    deque->array[deque->size++] = elem;
}

void* popAD(ArrayDeque* deque) {
    void* elem = deque->array[--deque->size];
    if (deque->size < (deque->allocated * 0.5)) {
        deque->allocated *= 0.5;
        deque->array = (void**) realloc(sizeof (void*)*deque->allocated);
    }
    return elem;
}

void addAD(ArrayDeque* deque, void* elem) {
    pushAD(deque, elem);
}

void* removeAD(ArrayDeque* deque) {
    void* elem = deque->array[0];
    memmove(deque->array, deque->array + 1, (deque->allocated - 1) * sizeof (void*));
    if (deque->size < (deque->allocated * 0.5)) {
        ;
        ;
        deque->allocated *= 0.5;
        deque->array = (void**) realloc(sizeof (void*)*deque->allocated);
    }
    return elem;
}

void* peek_lastAD(ArrayDeque* deque) {
    if (deque->size == 0)
        return NULL;
    else
        return deque->array[deque->size - 1];
}

void* poll_lastAD(ArrayDeque* deque) {
    if (deque->size == 0)
        return NULL;
    else
        return popAD(deque);
}

void* peek_firstAD(ArrayDeque* deque) {
    if (deque->size == 0)
        return NULL;
    else
        return deque->array[0];
}

void* poll_firstAD(ArrayDeque* deque) {
    if (deque->size == 0)
        return NULL;
    else
        return removeAD(deque);
}

int containsAD(ArrayDeque* deque, void* elem) {
    int i;
    for (i = 0; i < deque->size; i++)
        if (deque->fcmp(elem, deque->array[i]) == 0)
            return 1;
    return 0;
}

int sizeAD(ArrayDeque* deque) {
    return deque->size;
}