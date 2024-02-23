#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using  the shell
 * sort algorithm with knuth srquence
 * @array: the array to be sorted
 * @size: Number of elements in the arrray
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Calculate initial gap using knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* perform shell sort with decending gap */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3; /* Reduce the gap */
	}
}
