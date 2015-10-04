#include "linked_list.h"
#include "array_list.h"

LinkedList* newLinkedList(int (* fcmp)(const void*, const void*)) {
    LinkedList* new = (LinkedList*) malloc(sizeof (LinkedList));
    new->first = NULL;
    new->last = NULL;
    new->fcmp = fcmp;
    new->size = 0;
    return new;
}

void addLL(LinkedList* list, void* elem) {
    Node* new = (Node*) malloc(sizeof (Node));
    new->info = elem;
    new->next = NULL;
    new->past = list->last;
    if (list->last != NULL)
        list->last->next = new;
    list->last = new;
    if (list->first == NULL)
        list->first = new;
}

void add_inLL(LinkedList* list, void* elem, int index) {
    if ((index == list->size) || (list->size == 0))
        addLL(list, elem);
    else {
        Node* actual;
        int i;
        for (i = 0, actual = list->first; i < index; i++, actual = actual->next) {
            if (i == index) {
                Node* new = (Node*) malloc(sizeof (Node));
                new->info = elem;
                new->next = actual;
                if (actual != NULL) {
                    if (actual->past != NULL)
                        actual->past->next = new;
                    else
                        list->first = new;
                    new->past = actual->past;
                    actual->past = new;
                }
                list->size++;
                return;
            }
        }
    }
}

void* getLL(LinkedList* list, int index) {
    Node* actual;
    int i;
    for (i = 0, actual = list->first; i < index; i++, actual = actual->next) {
        if (i == index)
            return actual->info;
    }
    return NULL;
}

void setLL(LinkedList* list, int index, void* elem) {
    Node* actual;
    int i;
    for (i = 0, actual = list->first; i < index; i++, actual = actual->next) {
        if (i == index) {
            actual->info = elem;
            break;
        }
    }
}

void* remove_indexLL(LinkedList* list, int index) {
    Node* actual;
    int i;
    for (i = 0, actual = list->first; i < index; i++, actual = actual->next) {
        if (i == index) {
            if (actual->next != NULL)
                actual->next->past = actual->past;
            else
                list->last = actual->past;
            if (actual->past != NULL)
                actual->past->next = actual->next;
            else
                list->first = actual->next;
            list->size--;
            void* elem = actual->info;
            free(actual);
            return elem;
        }
    }
    return NULL;
}

int removeLL(LinkedList* list, void* elem) {
    Node* actual;
    int i;
    for (i = 0, actual = list->first; i < list->size; i++, actual = actual->next) {
        if (list->fcmp(elem, actual->info) == 0) {
            if (actual->next != NULL)
                actual->next->past = actual->past;
            else
                list->last = actual->past;
            if (actual->past != NULL)
                actual->past->next = actual->next;
            else
                list->first = actual->next;
            list->size--;
            free(actual);
            return i;
        }
    }
    return -1;
}

int index_ofLL(LinkedList* list, void* elem) {
    Node* actual;
    int i;
    for (i = 0, actual = list->first; i < list->size; i++, actual = actual->next)
        if (list->fcmp(elem, actual->info) == 0)
            return i;
    return -1;
}

int containsLL(LinkedList* list, void* elem) {
    return index_ofLL(list, elem) != -1;
}
int sizeLL(LinkedList* list){
    return list->size;
}
void sortLL(LinkedList* list){
    
}
