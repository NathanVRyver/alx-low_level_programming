#include "main.h"
#include <stdlib.h>
/**
 * str_concat - Concatenates two strings.
 * @s1: The first string to be concatenated.
 * @s2: The second string to be concatenated.
 *
 * Return: If concatenation is successful - a pointer to a new string
 * containing the contents of @s1 and @s2.
 * NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i = 0, j = 0, len1 = 0, len2 = 0;

	if (s1 != NULL)
		while (s1[len1])
			len1++;
	if (s2 != NULL)
		while (s2[len2])
			len2++;

	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
		return (NULL);

	while (i < len1)
	{
		concat[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';

	return (concat);
}
