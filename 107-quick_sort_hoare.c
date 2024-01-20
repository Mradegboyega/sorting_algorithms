#include <stdio.h>
#include <stddef.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size) {
    printf("%d", array[0]);
    for (size_t i = 1; i < size; ++i) {
        printf(", %d", array[i]);
    }
    printf("\n");
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Implements the Hoare partition scheme
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element
 */
size_t hoare_partition(int *array, size_t low, size_t high) {
    int pivot = array[high];
    size_t i = low - 1;
    size_t j = high + 1;

    while (1) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(&array[i], &array[j]);
        print_array(array, high + 1);
    }
}

/**
 * hoare_quick_sort - Recursively sorts the array using Quick Sort (Hoare)
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void hoare_quick_sort(int *array, size_t low, size_t high) {
    if (low < high) {
        size_t pi = hoare_partition(array, low, high);

        if (pi > 0) {
            hoare_quick_sort(array, low, pi);
        }

        hoare_quick_sort(array, pi + 1, high);
    }
}

/**
 * quick_sort_hoare - Wrapper function for Hoare Quick Sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size) {
    hoare_quick_sort(array, 0, size - 1);
}

