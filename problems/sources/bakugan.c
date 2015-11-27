//
// Created by Mateus Rodrigues on 04/10/2015.
//

#include "../headers/bakugan.h"

int bakugan(int rounds, int *myMonsters, int *hisMonsters) {
    int myPoints = 0;
    int hisPoints = 0;
    int myActualMonster = 0;
    int hisActualMonster = 0;
    int myNumRep = 0;
    int hisNumRep = 0;
    int bonus = 1;
    int i = 0;
    for (i = 0; i < rounds; i++) {
        if (bonus == 1) {
            if (myActualMonster != m[i]) {
                myActualMonster = m[i];
                myNumRep = 1;
            } else {
                myNumRep++;
            }
            if (hisActualMonster != l[i]) {
                hisActualMonster = l[i];
                hisNumRep = 1;
            } else {
                hisNumRep++;
            }
            if (myNumRep == 3 && hisNumRep == 3) {
                bonus = 0;
            } else if (myNumRep == 3) {
                bonus = 0;
                myPoints += 30;
            } else if (hisNumRep == 3) {
                bonus = 0;
                hisPoints += 30;
            }
        }

        hisPoints += l[i];
        myPoints += m[i];
    }
    if (myPoints > hisPoints) {
        return 1;
    } else if (hisPoints > myPoints) {
        return -1;
    } else {
        return 0;
    }

}

}