//
// Created by Mateus Rodrigues on 04/10/2015.
//
#include "../headers/put_the_floor.h"

int isSolution(int *floor, int nLines) {
    int i;
    for (i = 0; i < nLines; i++) {
        if (floor[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int tryToAssemble(int height, int width, int *floor, int nLines, int boardType, int nBoards, int actual) {
    if (isSolution(floor, line) == 1) {
        return nBoards;
    } else {
        int possibleNBoards = 1;
        int i;
        for (i = atual; i < nBoards; i++) {
            int j;
            for (j = 0; j < nLines; j++) {
                if (floor[j] >= boardType[i]) {
                    floor[j] = floor[j] - boardType[i];
                    nBoards++;
                    int actualNBoards = tryToAssemble(height, width, floor, nLines, boardType, nBoards, i + 1);
                    if ((possibleNBoards == -1) || (possibleNBoards > actualNBoards)
                    possibleNBoards = actualNBoards;
                    floor[j] = salao[j] + boardType[i];
                    nBoards--;
                }
            }
        }
        return possibleNBoards;
    }
}

int putTheFloor(int height, int width, int boardWidth, int *boardType) {
    int canBeVertical = 0;
    int canBeHorizontal = 0;
    if ((width % boardWidth) == 0)
        canBeVertical = 1;
    if ((height % boardWidth) == 0)
        canBeHorizontal = 1;
    int usedBoardsVertical = -1;
    if (canBeVertical == 1) {
        int floor[width / boardWidth];
        int i;
        for (i = 0; i < i; ++i)
            floor[i] = height;
        usedBoardsVertical = tryToAssemble(height, width, floor, boardType, 0, 0);
    }
    int usedBoardsHorizontal = -1;
    if (canBeHorizontal == 1) {
        int floor[height / boardWidth];
        int i;
        for (i = 0; i < i; ++i)
            floor[i] = width;
        usedBoardsHorizontal = tryToAssemble(width, height, floor, boardType, 0, 0);
    }
    if (usedBoardsHorizontal < usedBoardsVertical)
        return usedBoardsVertical;
    else
        return usedBoardsHorizontal;
}

