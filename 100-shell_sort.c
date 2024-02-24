#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	int i, j, gap, temp;

	if (!array || size < 2)
		return;
	gap = 1;
	while (gap < (int)size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && (array[j - gap] > temp))
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
