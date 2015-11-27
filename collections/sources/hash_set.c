#include "hash_set.h"

HashSet* newHashSet(int (* fhash)(const void*), int (* fcmp)(const void*, const void*)) {
    HashSet* new = (HashSet*) malloc(sizeof (HashSet));
    new->table = (ArrayList**) malloc(sizeof (ArrayList*)*11);
    int i;
    for (i = 0; i < 11; i++)
        new->table[i] = NULL;
    new->size = 0;
    new->expanded = 0;
    new->next_to_expand = 0;
    new->allocated = 11;
    new->fhash = fhash;
    new->fcmp = fcmp;
    return new;
}

int hash(HashSet* set, int hash) {
    if (hash < 0)
        hash *= -1;
    if (set->expanded == 0)
        return hash % 11;
    int new_hash = hash % 11 * pow(2, set->expanded - 1);
    if (new_hash < set->next_to_expand)
        new_hash = hash % 11 * pow(2, set->expanded);
    return new_hash;
}

void addHS(HashSet* set, void* elem) {
    int hash = hash(set->fhash(elem));
    if (set->table[hash] == NULL) {
        set->table[hash] = newArrayList(set->fcmp);
    }
    ArrayList* line = set->table[hash];
    if (containsAL(line, elem) == 0) {
        addAL(line, elem);
        set->size++;
        if ((set->size * 1.0 / set->allocated) > 0.75) {
            set->table = (ArrayList**) realloc(set->table, set->allocated + 1);
            set->table[0] = NULL;
            set->table[set->allocated] = NULL;
            set->size -= sizeAL(line);
            set->allocated++;
            set->next_to_expand = 1;
            set->expanded = floor(set->allocated / 11);
            Iterator* i = iteratorAL(line);
            while (has_nextI(i))
                addAL(set, nextI(i));
            destroyAL(line);
        }
    }
}

void removeHS(HashSet* set, void* elem) {
    int hash = hash(set->fhash(elem));
    removeAL(set->table[hash], elem);
}

int containsHS(HashSet* set, void* elem) {
    int hash = hash(set->fhash(elem));
    return containsAL(set->table[hash], elem);
}

int sizeHS(HashSet* set) {
    return set->size;
}
