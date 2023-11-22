#include "sort.h"

/**
 * swap - swaps the value of two integers
 * @a: int
 * @b: int
 */
void swap(int *a, int *b)
{
	int hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

/**
 * shell_sort - implements the shell short alogrithm using
 *	knuth sequence [1, 4, 13, 40, ...]
 *
 * @array: the array to be sorted
 * @size: the size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && (array[j] < array[j - gap]); j -= gap)
				swap(&array[j], &array[j - gap]);
		}
		gap /= 3;
		print_array(array, size);
	}
}
