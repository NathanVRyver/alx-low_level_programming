#include "main.h"

/**
 * clear_bit - Sets the value of a bit at a given index to 0.
 * @n: Pointer to the number to modify.
 * @index: Index of the bit to set to 0.
 *
 * Return: 1 on success, -1 on failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int mask;

	if (index > 63)
		return (-1);

	mask = 1 << index;
	if (*n & mask)
		*n ^= mask;

	return (1);
}
