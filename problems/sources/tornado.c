//
// Created by Mateus Rodrigues on 04/10/2015.
//
#include "../headers/tornado.h"

int tornado(int *fence, int size) {
    int value = 0, i, cont = 0;
    for (i = 0; i < size; i++) {
        if ((fence[i] == '1') && (i >= 2)) {
            if ((fence[i - 1] == '0') && (fence[i - 2] == '0')) {
                fence[i - 2] = '1';
                value += tornado(fence) + 1;
            }
        }
        if ((fence[i] == '1') && (i < (size - 3))) {
            if (fence[i + 1] == '0' && fence[i + 2] == '0') {
                fence[i + 2] = '1';
                value += tornado(fence) + 1;
            }
        }
        if (fence[i] == '1')
            value++;
    }
    if ((value == 0) && (size > 2)) {
        fence[1] = '1';
        value += tornado(fence) + 1;
    }
    return fence;
}

