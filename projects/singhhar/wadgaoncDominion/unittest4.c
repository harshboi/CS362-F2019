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
    printf("Begin Testing tribute Function():\n");

    memset(&G, 23, sizeof(struct gameState));        // setthe game state
    initializeGame(2, k, seed, &G);            // initialize a new game
    G.handCount[p] = handCount;                    // setany other variables
    memcpy(G.hand[p], coppers, sizeof(int) * handCount);        // call the refactoredfunction
    int tributeRevealedCards[2] = {copper, duchy};
    int dup_tributeRevealedCards[2] = {duchy, duchy};
    struct gameState temp;
    memcpy(&temp, &G, sizeof(struct gameState));

    temp.handCount[1] = 5;
    temp.handCount[0] = 5;
    temp.hand[1][0] = 1;
    temp.hand[1][1] = 1;
    temp.hand[1][2] = 2;
    temp.hand[1][3] = 2;

    // printf("%d\n", temp.supplyCount[temp.hand[1][2]]);
    // temp.hand
    // int choice1 = 3;
    // int choice2 = 1;
    // int handpos = 1;
    int nextPlayer = 1;
    int currentPlayer = 0;
    int prev = temp.playedCardCount;
    

    handleTribute(&G, 1, 0, tributeRevealedCards);
    int correct = tributeRevealedCards[0];
    // if (correct == tributeRevealedCards[0]) {
    //     printf("Error in tribute action here\n");
    // }

    temp.deckCount[nextPlayer] = 0;
    temp.discardCount[nextPlayer] = 0;
    
    handleTribute(&temp, 1, 0, dup_tributeRevealedCards);
    if (temp.playedCardCount != prev + 1) {
        printf("Error in tribute action\n");    // Should not give an error
    }

    temp.deckCount[nextPlayer] = 0;
    temp.discardCount[currentPlayer] = 1;
    temp.discardCount[nextPlayer] = 0;
    correct = tributeRevealedCards[0];

    // printf("%d\n", tributeRevealedCards[0]);
    // printf("%d\n", temp.discardCount[nextPlayer]);
    // printf("%d\n", temp.deckCount[nextPlayer]);
    handleTribute(&temp, 1, 0, tributeRevealedCards);
    if (correct != tributeRevealedCards[0]) {
        printf("Error in tribute action\n");    // Gives an Error
    }

    temp.deckCount[nextPlayer] = 1;
    int _prev = temp.deckCount[nextPlayer];
    
    // printf(temp.deckCount[nextPlayer]);
    handleTribute(&temp, 1, 0, tributeRevealedCards);
    // printf("%d\n", temp.deckCount[nextPlayer]);

    if (_prev-1 != temp.deckCount[nextPlayer]) {
        printf("Error in tribute action\n");
    }
    dup_tributeRevealedCards[0] = copper;
    dup_tributeRevealedCards[1] = gold;

    _prev = temp.coins;
    handleTribute(&temp, 1, 0, dup_tributeRevealedCards);

    if (_prev != temp.coins - 2) {
        printf("Error in tribute action\n");
    }
}

