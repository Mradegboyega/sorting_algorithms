#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Comparison function for sorting cards
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 * 
 * Return: Integer less than, equal to, or greater than zero if card1
 * is found, respectively, to be less than, to match, or be greater than card2.
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = (*(const deck_node_t **)card1)->card;
    const card_t *c2 = (*(const deck_node_t **)card2)->card;

    /* First, compare the kind (suit) of the cards */
    if (c1->kind != c2->kind)
        return c1->kind - c2->kind;

    /* If the kind is the same, compare the value */
    return strcmp(c1->value, c2->value);
}

/**
 * sort_deck - Sorts a deck of cards using qsort
 * @deck: Pointer to a pointer to the head of the deck
 * 
 * Description:
 *   This function sorts a deck of cards in ascending order, first by suit
 *   (Spade < Heart < Club < Diamond) and then by card value (Ace < 2 < ... < King).
 *   It uses the qsort function from the C standard library.
 */
void sort_deck(deck_node_t **deck)
{
    /* Count the number of nodes in the deck */
    size_t count = 0;
    deck_node_t *current = *deck;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    /* Convert the deck to an array for qsort */
    deck_node_t **deck_array = malloc(count * sizeof(deck_node_t *));
    if (deck_array == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    current = *deck;
    for (size_t i = 0; i < count; i++)
    {
        deck_array[i] = current;
        current = current->next;
    }

    /* Sort the array of deck nodes using qsort */
    qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);

    /* Rebuild the sorted deck as a linked list */
    *deck = deck_array[0];
    for (size_t i = 0; i < count - 1; i++)
    {
        deck_array[i]->next = deck_array[i + 1];
        deck_array[i + 1]->prev = deck_array[i];
    }

    deck_array[count - 1]->next = NULL;

    free(deck_array);
}

