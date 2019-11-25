#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };  // declarethe game state
    struct gameState G;// declarethe arrays 
    int seed = 1241;
    int coppers[MAX_HAND];
    int p = 0;
    int handCount = p;
    printf("Begin Testing Minion Function():\n");

    memset(&G, 23, sizeof(struct gameState));        // setthe game state
    initializeGame(2, k, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    
    struct gameState temp;
    memcpy(&temp, &G, sizeof(struct gameState));


    // -----------CODE FOR UNIT TEST------------
    temp.handCount[p+1] = 10;

    // NOTE: UNCOMMENTING THE LINES BELOW WILL CAUSE AN INFINITE LOOP (BUG I INTRODUCED IN THE LAST ASSIGNMENT)
    // temp.handCount[p] = 10;    
    // minion_action(&temp, 0, 1, 0, p);

    if (temp.handCount[p] != 4){
        printf("Error in minion action\n");
    }

    int p_coins = temp.coins;
    handleMinion(&temp, 1, 0, 0, p);
    if (temp.coins != p_coins + 2) {
        printf("error in choice1 for minion action");
    }
    handleMinion(&temp, 0, 1, 0, p+1);
    if (temp.handCount[p+1] != 4) {
        printf("Error in removing and adding cards for second player");
    }
    
}
