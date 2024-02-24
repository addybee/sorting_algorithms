#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int max, k;
	size_t i;
	int *count, *output;

	if (size < 2 || !array)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		       max = array[i];
	}
	count = (int *)malloc(sizeof(int) * (max + 1));
	output= (int *)malloc(sizeof(int) * size);
	if (!count || !output)
		return;
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (size_t)max; i++)
		count[i] = count[i - 1] + count[i];
	print_array(count, (size_t)max + 1);
	for (k = size - 1; k >= 0; k--)
	{
		count[array[k]] = count[array[k]] - 1;
		output[count[array[k]]] = array[k];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
