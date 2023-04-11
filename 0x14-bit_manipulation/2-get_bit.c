#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index.
 * @n: unsigned long int input.
 * @index: index to start
 * Return: Index on success, -1 on fail.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = 0;

	while (n)
	{
		if (i == index)
		{
			if (n % 2)
				return (1);
			else
				return (0);
		}

		n = n >> 1;
		i++;
	}

	if (index > i && index < 63)
		return (0);

	return (-1);
}
