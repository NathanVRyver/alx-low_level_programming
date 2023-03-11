#include "main.h"

void _puts(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        _putchar(s[i]);
}

int main(void)
{
    _puts("\"At the end of the day, my goal was to be the best hacker\"\n\t- Kevin Mitnick");
    return (0);
}
