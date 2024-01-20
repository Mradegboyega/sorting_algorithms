#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: First node to be swapped
 * @b: Second node to be swapped
 * @list: Pointer to the doubly linked list
 */
void swap_nodes(listint_t *a, listint_t *b, listint_t **list)
{
    if (a->prev)
        a->prev->next = b;
    if (b->next)
        b->next->prev = a;
    a->next = b->next;
    b->prev = a->prev;
    a->prev = b;
    b->next = a;

    if (a->next)
        a->next->prev = a;
    if (b->prev)
        b->prev->next = b;

    if (!b->prev)
        *list = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm.
 * @list: Pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, current->next, list);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(current->prev, current, list);
                print_list(*list);
                swapped = 1;
            }
        }
    }
}

