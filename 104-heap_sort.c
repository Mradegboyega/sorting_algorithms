#include "sort.h"

/**
 * swap - swaps two elements of an array
 * @a: first element
 * @b: second element
 **/
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * heapify - recursively perform heapify on the array
 * @array: array to heapify
 * @size: size of the array
 * @i: index
 * @heap_size: size of heap
 **/
void heapify(int *array, size_t size, size_t i, size_t heap_size)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < heap_size && array[left] > array[largest])
        largest = left;

    if (right < heap_size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, size);
        heapify(array, size, largest, heap_size);
    }
}

/**
 * heap_sort - sorts an array of integers in ascending order using Heap sort
 * @array: array to be sorted
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    for (size_t i = size / 2; i > 0; i--)
        heapify(array, size, i - 1, size);

    for (size_t i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, size, 0, i);
    }
}

