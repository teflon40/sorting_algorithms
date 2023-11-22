#include "sort.h"

void merge(int *array, int low, int mid, int high)
{
    int *tmp, i, a = low, b = mid + 1;

    tmp = malloc(sizeof(int) * (high + 1));
    if (tmp == NULL)
        return;

    printf("Merging...\n[left]: ");
	print_array(array, mid - low);

	printf("[right]: ");
	print_array(array, high - mid);

    for (i = low; i <= high; i++)
        tmp[i] = array[i];
    for (i = low; i <= high; i++)
    {
        if (a > mid)
            array[i] = tmp[b++];
	else if (b > high)
            array[i] = tmp[a++];
        else if (array[a] < array[b])
		array[i] = tmp[a++];
	else
		array[i] = tmp[b++];
    }
    free(tmp);
}
void sort(int *array, int low, int high)
{
    int mid, i;
    if (low < high)
    {
        //printf("Low = %d, High = %d\n", low, high);
        mid = low + (high - low) / 2;
        sort(array, low, mid);
        sort(array, mid, high);
        merge(array, low, mid, high);
    }
}

void merge_sort(int *array, size_t size)
{
    sort(array, 0, size - 1);

}
