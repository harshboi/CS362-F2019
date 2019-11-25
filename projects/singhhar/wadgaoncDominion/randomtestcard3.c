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

    memset(&G, 23, sizeof(struct gameState));        // setthe game state
    initializeGame(2, types, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    int tributeRevealedCards[2] = {copper, duchy};
    int dup_tributeRevealedCards[2] = {duchy, duchy};
    int i = 0;
    G.handCount[1] = 5;
    G.handCount[0] = 5;
    G.hand[1][0] = 1;
    G.hand[1][1] = 1;
    G.hand[1][2] = 2;
    G.hand[1][3] = 2;

    for (i=0; i<100; i++) {
        
        // printf("%d\n", G.supplyCount[G.hand[1][2]]);
        // G.hand
        // int choice1 = 3;
        // int choice2 = 1;
        // int handpos = 1;
        int nextPlayer = 1;
        int currentPlayer = 0;
        int prev = G.playedCardCount;
        
        int j;
        for (j=0; j<2;j++) {
            gainCard(types[rand()%10], &G, 1, 0);
            gainCard(types[rand()%10], &G, 2, 0);
            gainCard(types[rand()%10], &G, 1, 1);
            gainCard(types[rand()%10], &G, 2, 1);
        }
        handleTribute(&G, 1, 0, tributeRevealedCards);
        int correct = tributeRevealedCards[0];
        // if (correct == tributeRevealedCards[0]) {
        //     printf("Error in tribute action here\n");
        // }

        // G.deckCount[nextPlayer] = 0;
        // G.discardCount[currentPlayer] = 1;
        // G.discardCount[nextPlayer] = 0;
        correct = tributeRevealedCards[0];

        handleTribute(&G, 1, 0, tributeRevealedCards);
        if (correct != tributeRevealedCards[0]) {
            printf("Error in tribute action\n");    // Gives an Error
        }

        // G.deckCount[nextPlayer] = 1;
        int _prev = G.deckCount[nextPlayer];
        
        // printf(G.deckCount[nextPlayer]);
        handleTribute(&G, 1, 0, tributeRevealedCards);
        // printf("%d\n", G.deckCount[nextPlayer]);

        if (_prev-1 != G.deckCount[nextPlayer]) {
            printf("Error in tribute action last\n");
        }
    }

}
