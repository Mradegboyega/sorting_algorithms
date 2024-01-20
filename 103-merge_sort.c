#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sub-arrays of the array
 * @array: The array to be merged
 * @left: Starting index of the left sub-array
 * @middle: Ending index of the left sub-array
 * @right: Ending index of the right sub-array
 */
void merge(int *array, size_t left, size_t middle, size_t right)
{
	size_t i, j, k;
	size_t n1 = middle - left + 1;
	size_t n2 = right - middle;

	int *L = malloc(n1 * sizeof(int));
	int *R = malloc(n2 * sizeof(int));

	if (L == NULL || R == NULL)
		exit(1); /* Memory allocation failure */

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (j = 0; j < n2; j++)
		R[j] = array[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

/**
 * merge_sort_recursive - Sorts an array using the Merge sort algorithm (recursive)
 * @array: The array to be sorted
 * @left: Starting index of the array
 * @right: Ending index of the array
 */
void merge_sort_recursive(int *array, size_t left, size_t right)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;

		merge_sort_recursive(array, left, middle);
		merge_sort_recursive(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}

/**
 * merge_sort - Initiates the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	printf("Array before sorting:\n");
	print_array(array, size);

	merge_sort_recursive(array, 0, size - 1);

	printf("Array after sorting:\n");
	print_array(array, size);
}


