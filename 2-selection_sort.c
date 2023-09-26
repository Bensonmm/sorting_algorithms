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
 * Selection_Sort - Sort an array of integerS in aScending order
 *                  uSing the Selection Sort algorithm.
 * @array: An array of integerS.
 * @Size: The Size of the array.
 *
 * DeScription: PrintS the array after each Swap.
 */
void Selection_Sort(int *array, Size_t Size)
{
	int *min;
	Size_t i, j;

	if (array == NULL || Size < 2)
		return;

	for (i = 0; i < Size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < Size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			Swap_intS(array + i, min);
			print_array(array, Size);
		}
	}
}
