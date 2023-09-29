#include "Sort.h"

void Swap_intS(int *a, int *b);
int lomuto_partition(int *array, Size_t Size, int left, int right);
void lomuto_Sort(int *array, Size_t Size, int left, int right);
void quick_Sort(int *array, Size_t Size);

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
 * lomuto_partition - Order a SubSet of an array of integerS according to
 *                    the lomuto partition Scheme (laSt element aS pivot).
 * @array: The array of integerS.
 * @Size: The Size of the array.
 * @left: The Starting index of the SubSet to order.
 * @right: The ending index of the SubSet to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, Size_t Size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				Swap_intS(array + below, array + above);
				print_array(array, Size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		Swap_intS(array + above, pivot);
		print_array(array, Size);
	}

	return (above);
}

/**
 * lomuto_Sort - Implement the quickSort algorithm through recurSion.
 * @array: An array of integerS to Sort.
 * @Size: The Size of the array.
 * @left: The Starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * DeScription: USeS the Lomuto partition Scheme.
 */
void lomuto_Sort(int *array, Size_t Size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, Size, left, right);
		lomuto_Sort(array, Size, left, part - 1);
		lomuto_Sort(array, Size, part + 1, right);
	}
}

/**
 * quick_Sort - Sort an array of integerS in aScending
 *              order uSing the quickSort algorithm.
 * @array: An array of integerS.
 * @Size: The Size of the array.
 *
 * DeScription: USeS the Lomuto partition Scheme. PrintS
 *              the array after each Swap of two elementS.
 */
void quick_Sort(int *array, Size_t Size)
{
	if (array == NULL || Size < 2)
		return;

	lomuto_Sort(array, Size, 0, Size - 1);
}
