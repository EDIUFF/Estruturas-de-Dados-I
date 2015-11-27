#include "array_list.h"

ArrayList *newArrayList(int (*fcmp)(const void *, const void *)) {
    ArrayList *l = (ArrayList *) malloc(sizeof (ArrayList));
    l->array = (void **) malloc(sizeof (void *) * 11);
    l->size = 0;
    l->allocated = 11;
    l->fcmp = fcmp;
}

ArrayList *addAL(ArrayList *l, void *elem) {
    if (l->size == l->allocated - 1) {
        l->allocated *= 2;
        l->array = (void **) realloc(l->array, l->allocated);
    }
    l->array[l->size++] = elem;
    if ((l->size != 0) && (l->size < (l->allocated / 2))) {
        l->allocated /= 2;
        l->array = (void **) realloc(l->array, l->allocated);
    }
    return l;
}

void add_inAL(ArrayList* list, void* elem, int index) {
    if (list->size == (list->allocated - 1)) {
        list->allocated *= 2;
        list->array = (void **) realloc(list->array, list->allocated);
    }
    int i;
    for (i = list->size; i > index; i--)
        list->array[i] = list->array[i - 1];
    list->array[index] = elem;
    list->size++;
}

void *getAL(ArrayList *l, int index) {
    return l->array[index];
}

int remove_indexAL(ArrayList *list, int index) {
    void* elem = list->array[index];
    int i;
    for (i = index + 1; i < list->size; i++)
        list->array[i - 1] = list->array[i];
    list->size--;
    return elem;
}

int removeAL(ArrayList *list, void *elem) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (list->fcmp(elem, list->array[i]) == 0) {
            int j;
            for (j = i + 1; j < list->size; j++)
                list->array[j - 1] = list->array[j];
            list->size--;
            return i;
        }
    }
    return -1;
}

int containsAL(ArrayList* list, void* elem) {
    return index_ofAL(list, elem) != -1;
}

int index_ofAL(ArrayList *l, void *elem) {
    int i;
    for (i = 0; i < l->size; i++)
        if (l->fcmp(elem, l->array[i]) == 0)
            return i;
    return -1;
}

int sizeAL(ArrayList *l) {
    return l->size;
}

void sortAL(ArrayList* list){
    qsort(list->array, list->size, sizeof(void*), list->fcmp);
}
