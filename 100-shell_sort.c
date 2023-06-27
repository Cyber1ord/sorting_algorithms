#include "sort.h"

/**
 * shell_sort - Shell sort - Knuth Sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int gap, i, j, tmp;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];

			array[j] = tmp;
		}
		print_array(array, size);
	}
}
