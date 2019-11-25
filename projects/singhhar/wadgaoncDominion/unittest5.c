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
    printf("Begin Testing Mine Function():\n");

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

    int choice1 = 1;
    int choice2 = 5;
    // handleMine(&temp, choice1, choice2, 0, 2);
    // printf("choice %d\n", getCost(choice2));
    // printf("state->hand %d\n", (getCost(temp.hand[0][choice1]) + 4));
    int x = handleMine(&temp, choice1, choice2, 0, 2);
    printf("%d", x);
    if (x == -1){
        printf("error in mine function");
    }
    






}