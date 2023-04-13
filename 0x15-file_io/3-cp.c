#include "main.h"

/**
 * error_handle - handles errors.
 * @f1: 1st file descriptor.
 * @f2: 2nd file descriptor.
 * @f1_name: 1st file name.
 * @f2_name: 2nd file name.
 *
 * Return: nothing.
 */
void error_handle(int f1, int f2, char *f1_name, char *f2_name)
{
	if (f1 == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", f1_name), exit(98);

	if (f2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f2_name), exit(99);
}

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd_r, fd_w, a, b;
	ssize_t n, w;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to"), exit(97);

	fd_r = open(argv[1], O_RDONLY), fd_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	error_handle(fd_r, fd_w, argv[1], argv[2]);

	while ((n = read(fd_r, buffer, 1024)) > 0)
	{
		w = write(fd_w, buffer, n);
		if (w < n)
			error_handle(-1, fd_w, "", argv[2]);
	}

	if (n == -1)
		error_handle(-1, 0, argv[1], ""), exit(98);

	a = close(fd_r), b = close(fd_w);
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
