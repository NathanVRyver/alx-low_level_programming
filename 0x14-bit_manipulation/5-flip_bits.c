#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get
 * from one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: Number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = 0, count = 0;

	flip = n ^ m;
	while (flip)
	{
		if (flip & 1)
			count++;

		flip >>= 1;
	}

	return (count);
}
