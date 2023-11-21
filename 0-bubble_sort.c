/**
 * swap - A function to swap out address
 *
 * @a: The first integer to be swapped after comparism
 *
 * @b: The second integer to be swapped after comparism
 */

#include "sort.h"

void swap(int *a, int *b)
{
	int hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

/**
 * bubble_sort - A function to sort elements using the bubble sort method
 *
 * @array: Array of elements
 *
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int i, j;

	/* Loop to control the number of passes */
	for (i = 1; i <= size; i++)
	{
		/* Loop to control the number of comparisons per pass */
		for (j = 0; j < size - 1; j++)
		{
			/* Swap if current element > next */
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
