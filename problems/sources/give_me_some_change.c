//
// Created by Mateus Rodrigues on 04/10/2015.
//

#include "../headers/give_some_change.h"

int *giveMeSomeChange(int change, int *coins, int nCoins) {
    int *change_coins = (int *) malloc(sizeof(int));
    change_coins[0] = change;
    if (change != 0) {
        int value_left = 1;
        int i;
        for (i = 0; i < nCoins; i++) {
            if ((value - coins[i]) >= 0) {
                value -= coins[i];
                int *new_change_coins = giveMeSomeChange(change, coins, nCoins);
                if (new_change_coins[0] == -1) {
                    free(new_change_coins);
                } else if ((change_coins[0] >= (new_change_coins[0] + 1))) {
                    free(change_coins);
                    change_coins = (int *) realloc(new_change_coins, sizeof(int) * (new_change_coins[0] + 2));
                    change_coins[change_coins[0] + 1] = i;
                    change_coins[0]++;
                    value_left = 0;
                }
                change_coins += coins[i];
            }
        }
        if (value_left != 0) {
            change_coins = (int *) malloc(sizeof(int));
            change_coins[0] = -1;
        }
    }
    return change_coins;
}
