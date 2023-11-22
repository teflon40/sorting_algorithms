#include "sort.h"

/**
 * counting_sort - implements counting sort algorithm to sort
 *	array in ascending order
 * @array: [int] array to be sorted
 * @size:  [int] size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, max = array[0], j;
	int *tmp, *result;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > (int) max)
			max = array[i];
	}
	tmp = malloc(sizeof(int) * (max + 1));
	if (tmp == NULL)
		return;
	result = malloc(sizeof(int) * size);
	if (result == NULL)
	{
		free(tmp);
		return;
	}
	for (i = 0; i <= (size_t) max; i++)
		tmp[i] = 0;
	for (j = 0; j < size; j++)
		tmp[array[j]] = tmp[array[j]] + 1;
	for (i = 1; i <= max; i++)
		tmp[i] = tmp[i] + tmp[i - 1];
	print_array(tmp, max + 1);
	for (i = size - 1; (int) i >= 0; i--)
	{
		tmp[array[i]] = tmp[array[i]] - 1;
		result[tmp[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = result[i];
	free(tmp);
	free(result);
}
