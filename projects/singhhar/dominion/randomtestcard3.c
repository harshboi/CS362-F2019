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
    int p = 1;
    int handCount = p;
    printf("Begin Testing Ambassador Function():\n");

    memset(&G, 23, sizeof(struct gameState));        // setthe game state
    initializeGame(2, types, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    int tributeRevealedCards[2] = {copper, duchy};
    int dup_tributeRevealedCards[2] = {duchy, duchy};

    G.handCount[1] = 5;
    G.handCount[0] = 5;
    G.hand[1][0] = 1;
    G.hand[1][1] = 1;
    G.hand[1][2] = 2;
    G.hand[1][3] = 2;

    // printf("%d\n", G.supplyCount[G.hand[1][2]]);
    // G.hand
    // int choice1 = 3;
    // int choice2 = 1;
    // int handpos = 1;
    int nextPlayer = 1;
    int currentPlayer = 0;
    int prev = G.playedCardCount;
    

    tribute_action(&G, 1, tributeRevealedCards, 0);
    int correct = tributeRevealedCards[0];
    // if (correct == tributeRevealedCards[0]) {
    //     printf("Error in tribute action here\n");
    // }

    G.deckCount[nextPlayer] = 0;
    G.discardCount[nextPlayer] = 0;
    
    tribute_action(&G, 1, dup_tributeRevealedCards, 0);
    if (G.playedCardCount != prev + 1) {
        printf("Error in tribute action\n");    // Should not give an error
    }

    G.deckCount[nextPlayer] = 0;
    G.discardCount[currentPlayer] = 1;
    G.discardCount[nextPlayer] = 0;
    correct = tributeRevealedCards[0];

    // printf("%d\n", tributeRevealedCards[0]);
    // printf("%d\n", G.discardCount[nextPlayer]);
    // printf("%d\n", G.deckCount[nextPlayer]);
    tribute_action(&G, 1, tributeRevealedCards, 0);
    if (correct != tributeRevealedCards[0]) {
        printf("Error in tribute action\n");    // Gives an Error
    }

    G.deckCount[nextPlayer] = 1;
    int _prev = G.deckCount[nextPlayer];
    
    // printf(G.deckCount[nextPlayer]);
    tribute_action(&G, 1, tributeRevealedCards, 0);
    // printf("%d\n", G.deckCount[nextPlayer]);

    if (_prev-1 != G.deckCount[nextPlayer]) {
        printf("Error in tribute action\n");
    }

}
