#include "main.h"
#include <string.h>
/*
 * return: 0 if the value is null or is not binary
 * @converted_value: the value that was converted from binary
 * @alert: a variable to pick up if the array has a value that isn't 1 or 0
 * @i: counter variable for the for loop
 * @len: the length of the array of chars to be converted
 */

unsigned int binary_to_uint(const char *b)
{
	int alert = 0;
	unsigned int converted_value = 0;
	int len = strlen(b);
	int i;

	if (b == NULL)
		return (0);
	for (i = 0; i < len; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			alert++;
		else if (b[i] == '1')
			converted_value += 1 << (len - i - 1);
	}
	if (alert > 1)
		return (0);
	return (converted_value);
}
