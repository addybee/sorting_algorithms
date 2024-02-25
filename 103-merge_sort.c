#include "sort.h"
#include <stdio.h>
void copy_array(int *array, int *temp, size_t size);
void splitMerge(int *array, size_t start, size_t end, int *temp);
void merge(int *array, size_t start, size_t mid, size_t end, int *temp);
/**
 * merge_sort - sorts an array of integers in ascending order using the Merge
 * sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	copy_array(array, temp, size);
	splitMerge(array, 0, size, temp);
	free(temp);
}

/**
 * copy_array - sort the array using topDown method
 * @array: array to sort
 * @temp: work array
 */

void copy_array(int *array, int *temp, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		temp[i] = array[i];
}

/**
 * splitMerge - splits and merge the array
 * @array: array to sort
 * @start: begining of array index
 * @end: end of array(exclusive array[end] invalid)
 * @temp: work array
 */

void splitMerge(int *array, size_t start, size_t end, int *temp)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = (start + end) / 2;
		splitMerge(array, start, mid, temp);
		splitMerge(array, mid, end, temp);
		merge(array, start, mid, end, temp);
	}
}

/**
 * merge - merge the array
 * @array: array to sort
 * @start: begining of array index
 * @mid: middle of the array index
 * @end: end of array(exclusive array[end] invalid)
 * @temp: work array
 */
void merge(int *array, size_t start, size_t mid, size_t end, int *temp)
{
	size_t k = start, i = start, j = mid;

	printf("Merging...\n[left]: ");
	print_array(temp + start, mid - start);

	printf("[right]: ");
	print_array(temp + mid, end - mid);
	for (; k < end; k++)
	{
		if (i < mid && (j >= end || temp[i] <= temp[j]))
		{
			array[k] = temp[i];
			i++;
		}
		else
		{
			array[k] = temp[j];
			j++;
		}
	}
	copy_array(array, temp, end);

	printf("[Done]: ");
	print_array(array + start, end - start);
}
