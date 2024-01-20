#include <stdio.h>

/**
 * @brief Swaps two elements in an array.
 *
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * @brief Recursively performs Bitonic sort on an array.
 *
 * @param array Pointer to the array to be sorted.
 * @param size Size of the array.
 */
void bitonic_sort(int *array, size_t size) {
    for (size_t step = 2; step <= size; step *= 2) {
        for (size_t i = 0; i < size; i += step) {
            int direction = (i / step) % 2 == 0 ? 1 : 0;
            bitonic_merge(array + i, step / 2, direction);
        }
    }
}
/**
 * @brief Merges two halves of an array in Bitonic manner.
 *
 * @param array Pointer to the array.
 * @param size Size of the array.
 * @param direction Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, int direction) {
    if (size > 1) {
        size_t half = size / 2;

        bitonic_compare(array, half, direction);
        bitonic_compare(array + half, half, direction);

        bitonic_merge(array, half, direction);
        bitonic_merge(array + half, half, direction);
    }
}

/**
 * @brief Compares and swaps elements in a Bitonic sequence.
 *
 * @param array Pointer to the array.
 * @param size Size of the array.
 * @param direction Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_compare(int *array, size_t size, int direction) {
    size_t half = size / 2;
    for (size_t i = 0; i < half; ++i) {
        if ((array[i] > array[i + half]) == direction) {
            swap(&array[i], &array[i + half]);
        }
    }
}

/**
 * @brief Prints the elements of an array.
 *
 * @param array Pointer to the array.
 * @param size Size of the array.
 */
void print_array(int *array, size_t size) {
    printf("%d", array[0]);
    for (size_t i = 1; i < size; ++i) {
        printf(", %d", array[i]);
    }
    printf("\n");
}
