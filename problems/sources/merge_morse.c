//
// Created by Mateus Rodrigues on 04/10/2015.
//

#include "../headers/merge_morse.h"

int mergeMorse(char **expression, int start, int end) {
    int value = 0;
    int i;
    for (i = start; i < end; i++)
        if (c[i] == '+')
            break;
    if (i < end)
        return mergeMorse(expression, start, i) + mergeMorse(expression, i + 1, end);
    for (i = start; i < end; i++)
        if (c[i] == '*')
            break;
    if (i < end)
        return mergeMorse(expression, start, i) * mergeMorse(expression, i + 1, end);
    for (i = start; i < end; i++) {
        switch (c[i]) {
            case '.':
                value += 1;
                break;
            case ':':
                value += 2;
                break;
            case '-':
                value += 5;
                break;
            case '=':
                value += 10;
                break;
            default:
                value += 0;
        }
    }
    return value;
}

