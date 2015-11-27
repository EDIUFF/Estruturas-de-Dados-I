//
// Created by Mateus Rodrigues on 04/10/2015.
//

#include "../headers/how_many_piles.h"

int number_of_digits(int number) {
    int digits = 0;
    while (number) {
        digits++;
        number /= 10;
    }
    return digits;
}

int bunch_of_ones(int number) {
    while (number) {
        int n = number % 10;
        if (n != 1) return 0;
        number /= 10;
    }
    return 1;
}


int how_many_piles(int coins) {
    int possibilities = 1;
    if (!bunch_of_ones(coins)) {
        int offset = 1;
        int i, n;
        for (i = 0, n = number_of_digits(coins); i < n; i++) {
            offset *= 10;
        }
        offset += coins - 1;
        possibilities += how_many_piles(offset) + (coins % 10) / 2 - 1;
    }
    return possibilities;
}
