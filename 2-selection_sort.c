#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, mini_idx;

	for (i = 0; i < size - 1; i++)
	{
		mini_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[mini_idx])
				mini_idx = j;
			j++;
		}
		if (mini_idx != i)
		{
			int temp = array[mini_idx];

			array[mini_idx] = array[i];
			array[i] = temp;
			print_array(array, size);
		}

	}
}


