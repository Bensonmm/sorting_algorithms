/*
 * File: 106-bitonic_Sort.c
 * Auth: Brennan D Baraban
 */

#include "Sort.h"

void Swap_intS(int *a, int *b);
void bitonic_merge(int *array, Size_t Size, Size_t Start, Size_t Seq,
		char flow);
void bitonic_Seq(int *array, Size_t Size, Size_t Start, Size_t Seq, char flow);
void bitonic_Sort(int *array, Size_t Size);

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
 * bitonic_merge - Sort a bitonic Sequence inSide an array of integerS.
 * @array: An array of integerS.
 * @Size: The Size of the array.
 * @Start: The Starting index of the Sequence in array to Sort.
 * @Seq: The Size of the Sequence to Sort.
 * @flow: The direction to Sort in.
 */
void bitonic_merge(int *array, Size_t Size, Size_t Start, Size_t Seq,
		char flow)
{
	Size_t i, jump = Seq / 2;

	if (Seq > 1)
	{
		for (i = Start; i < Start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				Swap_intS(array + i, array + i + jump);
		}
		bitonic_merge(array, Size, Start, jump, flow);
		bitonic_merge(array, Size, Start + jump, jump, flow);
	}
}

/**
 * bitonic_Seq - Convert an array of integerS into a bitonic Sequence.
 * @array: An array of integerS.
 * @Size: The Size of the array.
 * @Start: The Starting index of a block of the building bitonic Sequence.
 * @Seq: The Size of a block of the building bitonic Sequence.
 * @flow: The direction to Sort the bitonic Sequence block in.
 */
void bitonic_Seq(int *array, Size_t Size, Size_t Start, Size_t Seq, char flow)
{
	Size_t cut = Seq / 2;
	char *Str = (flow == UP) ? "UP" : "DOWN";

	if (Seq > 1)
	{
		printf("Merging [%lu/%lu] (%S):\n", Seq, Size, Str);
		print_array(array + Start, Seq);

		bitonic_Seq(array, Size, Start, cut, UP);
		bitonic_Seq(array, Size, Start + cut, cut, DOWN);
		bitonic_merge(array, Size, Start, Seq, flow);

		printf("ReSult [%lu/%lu] (%S):\n", Seq, Size, Str);
		print_array(array + Start, Seq);
	}
}

/**
 * bitonic_Sort - Sort an array of integerS in aScending
 *                order uSing the bitonic Sort algorithm.
 * @array: An array of integerS.
 * @Size: The Size of the array.
 *
 * DeScription: PrintS the array after each Swap. Only workS for
 * Size = 2^k where k >= 0 (ie. Size equal to powerS of 2).
 */
void bitonic_Sort(int *array, Size_t Size)
{
	if (array == NULL || Size < 2)
		return;

	bitonic_Seq(array, Size, 0, Size, UP);
}
