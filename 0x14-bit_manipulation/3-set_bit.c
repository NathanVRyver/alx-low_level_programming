#include "main.h"

/**
 * set_bit - sets the value of a bit to 1.
 * at a given index.
 * @num_ptr: pointer of an unsigned long int.
 * @bit_index: index of the bit.
 *
 * Return: 1 if it worked, -1 if it didn't.
 */
int set_bit(unsigned long int *num_ptr, unsigned int bit_index)
{
	unsigned int mask;

	if (bit_index > 63)
		return (-1);

	mask = 1 << bit_index;
	*num_ptr = (*num_ptr | mask);

	return (1);
}
