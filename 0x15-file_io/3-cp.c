#include "main.h"

/**
 * error_check - checks if files can be opened.
 * @file_from: source file.
 * @file_to: destination file.
 * @argv: arguments vector.
 * Return: no return.
 */
void error_check(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, erxrx_close;
	ssize_t chars_read, chars_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_check(file_from, file_to, argv);

	while ((chars_read = read(file_from, buffer, 1024)) > 0)
	{
		chars_written = write(file_to, buffer, chars_read);
		if (chars_written == -1)
			error_check(0, -1, argv);
	}

	if (chars_read == -1)
		error_check(-1, 0, argv);

	erxrx_close = close(file_from);
	if (erxrx_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	erxrx_close = close(file_to);
	if (erxrx_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
