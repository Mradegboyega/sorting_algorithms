#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void bitonic_merge(int *array, size_t size, int direction);
void bitonic_compare(int *array, size_t size, int direction);
void bitonic_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, size_t left, size_t middle, size_t right);
void merge_sort_recursive(int *array, size_t left, size_t right);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t index, size_t total_size);
void swap(int *a, int *b);
void radix_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void countSort(int *array, size_t size, int exp);
void swap(int *a, int *b);
size_t hoare_partition(int *array, size_t low, size_t high);
void hoare_quick_sort(int *array, size_t low, size_t high);
void quick_sort_hoare(int *array, size_t size);

/* Declare your other sorting function prototypes here */

#endif /* SORT_H */

