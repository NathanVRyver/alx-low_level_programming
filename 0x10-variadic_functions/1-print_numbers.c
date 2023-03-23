#include "variadic_functions.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/**
 * print_numbers: function that prints numbers
 * @seperator: number seperator
 * @n: number count
 * return: void
 */


void print_numbers(const char *seperator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;

	va_start(ap, n);
	for (i=0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if ((seperator) && (i < n-1))
			printf("%s", seperator);
	}
	printf("\n");
	va_end(ap);
}
