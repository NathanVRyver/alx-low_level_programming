#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd_r, fd_w, r, a, b;
	char buffer[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_r = open(argv[1], O_RDONLY);
	if (fd_r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_w == -1)
	{
		close(fd_r);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((r = read(fd_r, buffer, BUFSIZ)) > 0)
	{
		if (write(fd_w, buffer, r) != r)
		{
			close(fd_r);
			close(fd_w);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (r == -1)
	{
		close(fd_r);
		close(fd_w);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	a = close(fd_r);
	b = close(fd_w);
	if (a == -1 || b == -1)
	{
		if (a == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_r);
		if (b == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_w);
		exit(100);
	}

	return (0);
}
