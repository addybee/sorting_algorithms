#include "sort.h"
void swap(int *x, int *y);
int partition(int *array, int low, int high, size_t size);
void q_sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: the array to be sorted
 * @size: sze of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	q_sort(array, 0, size - 1, size);
}
/**
 * q_sort - help for quick sort function
 * @array: the array to be divided
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 */
void q_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		q_sort(array, low, pivot - 1, size);
		q_sort(array, pivot + 1, high, size);
	}
}

/**
 * partition - divides the array
 *
 * @array: the array to be divided
 * @low: lowest index
 * @high: highest index
 * @size: array size
 * Return: pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j;

	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < array[high])
		{
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * swap - swap two element of an array
 * @xx: first
 * @yy: second
 */
void swap(int *xx, int *yy)
{
	int temp = *xx;

	*xx = *yy;
	*yy = temp;
}
