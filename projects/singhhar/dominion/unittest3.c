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
    int p = 1;
    int handCount = p;
    printf("Begin Testing Ambassador Function():\n");

    memset(&G, 23, sizeof(struct gameState));        // setthe game state
    initializeGame(2, k, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    
    struct gameState temp;
    memcpy(&temp, &G, sizeof(struct gameState));

    temp.handCount[1] = 5;
    temp.handCount[0] = 5;
    temp.hand[1][0] = 1;
    temp.hand[1][1] = 1;
    temp.hand[1][2] = 2;
    temp.hand[1][3] = 2;

    // printf("%d\n", temp.supplyCount[temp.hand[1][2]]);
    int prev = temp.supplyCount[temp.hand[1][2]];
    // temp.hand
    int choice1 = 3;
    int choice2 = 1;
    int handpos = 1;
    ambassador_action(&temp, choice1, choice2, handpos, p);
    // printf("%d\n", temp.supplyCount[temp.hand[1][2]]);
    if (prev + choice2 != temp.supplyCount[temp.hand[p][choice2]]){
        printf("Error in ambassador function\n");
    }

    choice2 = 4;
    if (-1 != ambassador_action(&temp, choice1, choice2, handpos, p)){
        printf("Ambassador choice problems");
    }
}

