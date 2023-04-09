#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 * Return: the converted number, or 0 if the string container is null
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i;
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		result = 2 * result + (b[i] - '0');
	}
        
        return (result);	
}
