#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int types[10] = { adventurer, estate, feast, gardens, mine, remodel, smithy, village, baron, great_hall };  // declarethe game state
    int seed = 1241;
    int coppers[MAX_HAND];
    int p = 0;
    int handCount = p;
    int i = 0;
    struct gameState G;                            // declare the arrays 
    memset(&G, 23, sizeof(struct gameState));      // set the game state
    initializeGame(2, types, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    for(i=0; i<10000; i++) {
        int j;
        for (j=0; j<2;j++) {
            gainCard(types[rand()%10], &G, 1, 0);
            gainCard(types[rand()%10], &G, 2, 0);
            gainCard(types[rand()%10], &G, 1, 1);
            gainCard(types[rand()%10], &G, 2, 1);
        }
        int prev_coins = G.coins;
        baron_action(&G, 1, p);
        // G.supplyCount[estate] = 2;
        baron_action(&G, 1, p);
        // G.hand[p][0] = estate;
        baron_action(&G, 1, p);
        baron_action(&G, 0, p);
        // G.supplyCount[estate] = -2;
        baron_action(&G, 0, p);
        
        int prev_num = G.supplyCount[estate];
        baron_action(&G, 1, p);
        // prev_num = G.supplyCount[estate];
        baron_action(&G, 0, p);
        if (prev_num - 1 != supplyCount(estate, &G)) {
            printf("error in gaining a card count\n");
        }
        
        if(G.coins != prev_coins + 4) {
            printf("Baron Action not performing according to expectations\n");
        }
        // printf("%d\n", G.coins);
    }


}