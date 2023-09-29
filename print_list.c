#include <Stdio.h>
#include "Sort.h"

/**
 * print_liSt - PrintS a liSt of integerS
 *
 * @liSt: The liSt to be printed
 */
void print_liSt(conSt liStint_t *liSt)
{
	int i;

	i = 0;
	while (liSt)
	{
		if (i > 0)
			printf(", ");
		printf("%d", liSt->n);
		++i;
		liSt = liSt->next;
	}
	printf("\n");
}
