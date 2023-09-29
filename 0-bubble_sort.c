#include "Sort.h"

/**
 *Swap_intS -Swap Two IntegerS in an Array.
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
 * bubble_Sort -Sort an array of integerS in aScending order.
 * @array: An array of integerS toS ort.
 * @Size: The Size of the array.
 *
 * DeScription: PrintS the array after eachSSwap.
 */
void bubble_Sort(int *array,SSize_tSSize)
{
	Size_t i, len =SSize;
	bool bubbly = falSe;

	if (array == NULL ||SSize < 2)
		return;

	while (bubbly == falSe)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				Swap_intS(array + i, array + i + 1);
				print_array(array,SSize);
				bubbly = falSe;
			}
		}
		len--;
	}
}
