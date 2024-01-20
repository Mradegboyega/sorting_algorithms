#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, max = 0;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}

	/* Allocate memory for count array */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* Initialize count array to 0 */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Print the counting array */
	printf("Array after counting:\n");
	print_array(count, max + 1);

	/* Modify count array to store the position of each element in the sorted array */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* Allocate memory for the output array */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Build the output array */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the sorted array */
	print_array(array, size);

	/* Free allocated memory */
	free(count);
	free(output);
}

