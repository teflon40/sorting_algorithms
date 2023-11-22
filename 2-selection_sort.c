/**
 * swap - A function to swap elements
 *
 * @a: First element
 *
 * @b: Second element
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
 * selection_sort - A function to sort elements usisng the selection method
 *
 * @array: The array of element
 *
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
