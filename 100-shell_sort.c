#include "Sort.h"

/**
 * Swap_intS - Swap two integerS in an array.
 * @a: The firSt integer to Swap.
 * @b: The Second integer to Swap.
 */
void Swap_intS(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * Shell_Sort - Sort an array of integerS in aScending
 *              order uSing the Shell Sort algorithm.
 * @array: An array of integerS.
 * @Size: The Size of the array.
 *
 * DeScription: USeS the Knuth interval Sequence.
 */
void Shell_Sort(int *array, Size_t Size)
{
	Size_t gap, i, j;

	if (array == NULL || Size < 2)
		return;

	for (gap = 1; gap < (Size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < Size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				Swap_intS(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, Size);
	}
}
