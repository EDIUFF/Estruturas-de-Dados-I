//
// Created by Mateus Rodrigues on 04/10/2015.
//

#ifndef PROJETO_MONITORIA_2015_C_UTIL_H
#define PROJETO_MONITORIA_2015_C_UTIL_H

#include <string.h>

int fcmp_short(const void *a, const void *b) {
    short sa = *((short *) a);
    short sb = *((short *) b);
    if (sa > sb)
        return -1;
    if (sa < sb)
        return 1;
    return 0;
}

int fcmp_int(const void *a, const void *b) {
    int ia = *((int *) a);
    int ib = *((int *) b);
    if (ia > ib)
        return -1;
    if (ia < ib)
        return 1;
    return 0;
}

int fcmp_long(const void *a, const void *b) {
    long la = *((long *) a);
    long lb = *((long *) b);
    if (la > lb)
        return -1;
    if (la < lb)
        return 1;
    return 0;
}

int fcmp_float(const void *a, const void *b) {
    float fa = *((float *) a);
    float fb = *((float *) b);
    if (fa > fb)
        return -1;
    if (fa < fb)
        return 1;
    return 0;
}

int fcmp_double(const void *a, const void *b) {
    double da = *((double *) a);
    double db = *((double *) b);
    if (da > db)
        return -1;
    if (db < db)
        return 1;
    return 0;
}

int fcmp_char(const void *a, const void *b) {
    char ca = *((char *) a);
    char cb = *((char *) b);
    if (ca > cb)
        return -1;
    if (cb < cb)
        return 1;
    return 0;
}

int fcmp_string(const void *a, const void *b) {
    char *ca = ((char *) a);
    char *cb = ((char *) b);
    return strcmp(a, b);
}

int hash_short(const void *a) {
    return *((short *) a) * 31 / 17 * 19;
}

int hash_int(const void *a) {
    return *((int *) a) * 31 / 17 * 19;
}

int hash_long(const void *a) {
    return *((long *) a) * 31 / 17 * 19;
}

int hash_float(const void *a) {
    return (int) (*((float *) a) * 31 / 17 * 19);
}

int hash_double(const void *a) {
    return (int) (*((double *) a) * 31 / 17 * 19);
}

int hash_char(const void *a) {
    return (*((char *) a) * 31 / 17 * 19);
}

int hash_string(const void *a) {
    char* str = (char*)a;
    int hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

#endif //PROJETO_MONITORIA_2015_C_UTIL_H
