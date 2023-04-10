#include "main.h"

/**
 * print_binary: converts number to base2
 * @n: the number to convert
 * return void
 */

void print_binary(unsigned long int n)
{
	unsigned long int num, div_num;
	char binary_char;

	num = n;
	div_num = n >> 1;
	if (div_num > 0)
		print_binary(div_num);
	binary_char = (num - (2 * div_num)) + 48;
	_putchar(binary_char);
}
