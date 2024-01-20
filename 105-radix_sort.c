#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Helper function to get the maximum value in an array
 * @array: array to find the maximum value in
 * @size: size of the array
 * Return: the maximum value
 **/
int getMax(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * countSort - Helper function to perform counting sort based on significant digit
 * @array: array to sort
 * @size: size of the array
 * @exp: current exponent (significant digit)
 **/
void countSort(int *array, size_t size, int exp)
{
    const size_t output_size = size;
    int *output = malloc(output_size * sizeof(int));
    if (output == NULL)
        return;

    int count[10] = {0};

    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: array to be sorted
 * @size: size of the array
 **/
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = getMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(array, size, exp);
    }
}

