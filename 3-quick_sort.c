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
 * split - A function to split the array
 *
 * @array: The array
 *
 * @l: low of the array
 *
 * @h: High of the array
 *
 * @size: Size of the array
 *
 * Return: Integer
 */
int split(int *array, int l, int h, size_t size)
{
	int i, pivot = array[h];
	int firsthigh;

	firsthigh = l;
	for (i = l; i < h; i++)
	{
		if (array[i] <= pivot)
		{
			if (firsthigh != i)
			{
				swap(&array[i], &array[firsthigh]);
				print_array(array, size);
			}
			firsthigh++;
		}
	}
	if (firsthigh != h)
	{
		swap(&array[h], &array[firsthigh]);
		print_array(array, size);
	}
	return (firsthigh);
}

/**
 * tmp_sort - A function to sort elements
 *
 * @array: Array of element
 *
 * @l: Low of the array
 *
 * @h: High of the array
 *
 * @size: Size of the array
 */

void tmp_sort(int *array, int l, int h, size_t size)
{
	int middle;

	if (l < h)
	{
		middle = split(array, l, h, size);
		tmp_sort(array, l, middle - 1, size);
		tmp_sort(array, middle + 1, h, size);
	}
}
/**
 * quick_sort - A function to sort elements using the quicksort method
 *
 * @array: The array of elements
 *
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	tmp_sort(array, 0, size - 1, size);
}
