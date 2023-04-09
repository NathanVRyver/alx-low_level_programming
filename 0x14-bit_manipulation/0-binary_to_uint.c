#include "main.h"
/*
 * binary_to_uint -- converts a binary number to an unsigned int
 * return: 0 if the value is null or is not binary
 * @converted_value: the value that was converted from binary
 * @b: pointer to the binary string
 * @i: counter variable for the for loop
 * @len: the length of the array of chars to be converted
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int converted_value = 0;
	unsigned int bit_value = 1;
	unsigned int len = strlen(b);
	unsigned int i;

	if (b == NULL)
		return (0);

	for (i = 0; i < len; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		if (b[i] == '1')
			converted_value += bit_value;

		bit_value <<= 1;
	}
	return (converted_value);
}
