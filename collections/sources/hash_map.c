#include "hash_map.h"

HashMap* newHashMap(int(*fhash_key)(const void*), int(*fcmp_key)(const void*, const void*), int(*fcmp_value)(const void*, const void*)) {
    HashMap* new = (HashMap*) malloc(sizeof (HashMap));
    new->table = (ArrayList**) malloc(sizeof (ArrayList*)*11);
    int i;
    for (i = 0; i < 11; i++)
        new->table[i] = NULL;
    new->allocated = 11;
    new->size = 0;
    new->expanded = 0;
    new->next_to_expand = 0;
    new>fcmp_key = fcmp_key;
    new->fcmp_value = fcmp_value;
    new->fhash_key = fhash_key;
    return new;
}

int hash(HashMap* map, int hash) {
    if (hash < 0)
        hash *= -1;
    if (map->expanded == 0)
        return hash % 11;
    int new_hash = hash % 11 * pow(2, map->expanded - 1);
    if (new_hash < map->next_to_expand)
        new_hash = hash % 11 * pow(2, map->expanded);
    return new_hash;
}

int cmp(const void* a, const void* b) {
    Pair* pair_a = (Pair*) a;
    Pair* pair_b = (Pair*) b;
    HashMap* map = pair_a->map;
    return !(((map->fcmp_key(pair_a->key, pair_b->key) == 0) && (map->fcmp_value(pair_a->value, pair_b->value))) == 1);
}

void putHM(HashMap* map, void* key, void* value) {
    int hash = hash(map, map->fhash_key(key));
    Pair* new = (Pair*) malloc(sizeof (Pair));
    if (map->table[hash] == NULL) {
        map->table[hash] = newArrayList(cmp);
    }
    ArrayList* line = map->table[hash];
    Pair* new = (Pair*) malloc(sizeof (Pair));
    new->key = key;
    new->value = value;
    new->map = map;
    if (containsAL(line, new) == 0) {
        addAL(line, new);
        map->size++;
        if ((map->size * 1.0 / map->allocated) > 0.75) {
            map->table = (ArrayList**) realloc(map->table, map->allocated + 1);
            map->table[0] = NULL;
            map->table[map->allocated] = NULL;
            map->size -= sizeAL(line);
            map->allocated++;
            map->next_to_expand = 1;
            map->expanded = floor(map->allocated / 11);
            Iterator* i = iteratorAL(line);
            while (has_nextI(i))
                addAL(map, nextI(i));
            destroyAL(line);
        }
    }
}

void* removeHM(HashMap* map, void* key) {
    int hash = hash(map, map->fhash_key(key));
    ArrayList* line = map->table[hash];
    Iterator* i = iteratorAL(line);
    while (has_nextI(i)) {
        Pair* actual = (Pair*) nextI(i);
        if (map->fcmp_key(actual->key, key)) {
            removeAL(line, actual);
            void* value = actual->value;
            free(actual);
            destroyI(i);
            return value;
        }
    }
    destroyI(i);
    return NULL;
}

void* getHM(HashMap* map, void* key) {
    int hash = hash(map, map->fhash_key(key));
    ArrayList* line = map->table[hash];
    Iterator* i = iteratorAL(line);
    while (has_nextI(i)) {
        Pair* actual = (Pair*) nextI(i);
        if (map->fcmp_key(actual->key, key)) {
            destroyI(i);
            return actual->value;
        }
    }
    destroyI(i);
    return NULL;
}

int hasKey(HashMap* map, void* key) {
    int hash = hash(map, map->fhash_key(key));
    ArrayList* line = map->table[hash];
    Iterator* i = iteratorAL(line);
    while (has_nextI(i)) {
        Pair* actual = (Pair*) nextI(i);
        if (map->fcmp_key(actual->key, key)) {
            destroyI(i);
            return 1;
        }
    }
    destroyI(i);
    return 0;
}

int hasValue(HashMap* map, void* value) {
    int i;
    for (i = 0; i < map->size; i++) {
        if (map->table[i] != NULL) {
            Iterator* j = iteratorAL(map->table[i]);
            while (has_nextI(j)) {
                Pair* actual = (Pair*) nextI(j);
                if (map->fcmp_value(actual->value, value)) {
                    destroyI(j);
                    return 1;
                }
            }
            destroyI(i);
        }
    }
    return 0;
}
