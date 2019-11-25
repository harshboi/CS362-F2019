#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int types[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };  // declarethe game state
    struct gameState G;// declarethe arrays 
    int seed = 1241;
    int coppers[MAX_HAND];
    int p = 0;
    int handCount = p;
    printf("Begin Testing Minion Function():\n");

    memset(&G, 23, sizeof(struct gameState));        // setthe game state
    initializeGame(2, types, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    int prev = 4;
    int initial = G.handCount[p] = 0;
    // -----------CODE FOR Random TEST------------
    int i;
    for (i=0; i<100;i++) {
        if (p == 1){
            G.handCount[0] = initial;
        }
        else {
            G.handCount[1] = 10;
        }
        G.handCount[p] = initial;
        int j;

        // NOTE: UNCOMMENTING THE LINES BELOW WILL CAUSE AN INFINITE LOOP (BUG I INTRODUCED IN THE LAST ASSIGNMENT)
        // G.handCount[p] = 10;    
        // handleMinion(&G, 0, 1, 0, p);
        // NOTE: Commenting lines for the gaincard for player 1 will cause the test to go into an infinite loop
        for (j=0; j<50;j++) {
        //     gainCard(types[rand()%10], &G, 1, 0);        # NOTE: RANDOM IN HERE
        //     gainCard(types[rand()%10], &G, 2, 0);
            gainCard(types[rand()%10], &G, 1, 1);
            gainCard(types[rand()%10], &G, 2, 1);
        }
        if (G.handCount[p] != 4){
            printf("Error in minion action\n");
        }

        int p_coins = G.coins;
        handleMinion(&G, 1, 0, 0, p);
        if (G.coins != p_coins + 2) {
            printf("error in choice1 for minion action\n");
        }

        G.whoseTurn = p;
        handleMinion(&G, 0, 1, 0, p);
        if (G.handCount[p+1] != 4 || G.handCount[p+1] != 0) {
            printf("Error in removing and adding cards for second player\n");
        }
        else {
            prev = G.handCount[p+1];
        }

    }   
}