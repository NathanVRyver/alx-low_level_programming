#include "main.h"
/**
 * get_bit: returns the value of a bit at an index
 * @num: unsigned long int given as input in the function
 * @bit_index: index of the bit
 * Return: the value of the bit
 */
int get_bit(unsigned long int num, unsigned int bit_index)
{
	unsigned int i;
	if (num == 0 && bit_index < 64)
		return (0);
	for (i = 0; i <= 63; num >>= 1, i++)
	{
		if (bit_index == i)
			return (num & 1);
	}
	return (-1);
}
