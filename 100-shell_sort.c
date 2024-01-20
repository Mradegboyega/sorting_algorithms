#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Perform insertion sort for each gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			/* Shift elements that are greater than temp to the right */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			/* Insert temp at its correct position */
			array[j] = temp;
		}

		/* Print the array after each decrease in the interval */
		print_array(array, size);

		/* Update the gap using Knuth sequence */
		gap = (gap - 1) / 3;
	}
}

