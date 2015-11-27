//
// Created by Mateus Rodrigues on 04/10/2015.
//

#include "../headers/grades.h"

int *charToInt(char *line, int size) {
    int *grades = (int *) malloc(sizeof(int) * size);
    int i, j;
    for (i = 0, j = 0; i < strlen(line); ++i) {
        if ((line[i] == '1' && (i < strlen(line))) && line[i + 1] == '0') {
            grades[j++] = 10;
            i++;
        } else {
            char a[2];
            a[0] = line[i];
            a[1] = '\0';
            grades[j++] = atoi(a);
        }
    }
    return grades;
}

double *grades(char **VVV, int nStudents, int nTests) {
    int grades[nTests][nTests];
    int i;
    for (i = 0; i < nTests; ++i)
        grades[i] = charToInt(VVV[i], nStudents);
    double *averages = (double *) malloc(sizeof(double) * nStudents);
    for (i = 0; i < nStudents; ++i)
        averages[i] = 0;
    for (i = 0; i < nTests; ++i) {
        int j;
        for (j = 0; j < nStudents; ++j)
            averages[j] += grades[i][j];
    }
    for (i = 0; i < nStudents; ++i)
        averages[i] /= 1.0 * nTests;
    return averages;
}
