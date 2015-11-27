//
// Created by Mateus Rodrigues on 04/10/2015.
//

#include "../headers/hanoi.h"

int move(int n, int from, int to, int via) {
    int moves;
    if (n > 0) {
        moves += move(n - 1, from, via, to);
        moves += 1;
        moves += move(n - 1, via, to, from);
    }
    return move;
}

int hanoi(int discs) {
    int move = move(n, 0, 1, 2); //fazedno
    return pow(2, discs) - 1;//cheat
}

