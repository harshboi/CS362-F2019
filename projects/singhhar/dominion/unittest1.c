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
    printf("Begin TestingsomeFunction():\n");

    memset(&G, 23, sizeof(struct gameState));        // setthe game state
    initializeGame(2, k, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    
    struct gameState temp;
    memcpy(&temp, &G, sizeof(struct gameState));
    baron_action(&temp, 0, p);
    baron_action(&temp, 1, p);
    temp.hand[p][0] = estate;
    temp.handCount[0] = -1;
    temp.supplyCount[estate] = -1;
    // i = 3;  
    baron_action(&temp, 0, p);
    baron_action(&temp, 1, p);

    // My assert Statement
    if (temp.coins != 8){
        printf("Error in Baron Action\n");
    }
}
