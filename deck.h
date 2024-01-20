#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Enumeration of card suits
 * @SPADE: Spade suit
 * @HEART: Heart suit
 * @CLUB: Club suit
 * @DIAMOND: Diamond suit
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a playing card
 * @value: Value of the card (e.g., "Ace", "2", ..., "King")
 * @kind: Suit of the card
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure representing a node in a deck of cards
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

/* Function prototypes */
void sort_deck(deck_node_t **deck);
int compare_cards(const void *card1, const void *card2);
#endif /* DECK_H */

