#include "main.h"

/**
 * check_arguments - checks the command line arguments
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: 1 on success, -1 on failure
 */
int check_arguments(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (-1);
	}
	return (1);
}

/**
 * open_file - opens a file
 * @filename: name of the file to open
 * @flags: flags to use when opening the file
 *
 * Return: file descriptor on success, -1 on failure
 */
int open_file(const char *filename, int flags)
{
	int fd = open(filename, flags);

	if (fd < 0)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);

	return (fd);
}

/**
 * copy_file - copies the content of one file to another
 * @fd_r: file descriptor for the source file
 * @fd_w: file descriptor for the destination file
 *
 * Return: 1 on success, -1 on failure
 */
int copy_file(int fd_r, int fd_w)
{
	ssize_t r;
	char buffer[BUFSIZ];

	while ((r = read(fd_r, buffer, BUFSIZ)) > 0)
	{
		if (write(fd_w, buffer, r) != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			return (-1);
		}
	}

	if (r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		return (-1);
	}

	return (1);
}

/**
 * close_file - closes a file
 * @fd: file descriptor of the file to close
 *
 * Return: 1 on success, -1 on failure
 */
int close_file(int fd)
{
	if (close(fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
		return (-1);
	}

	return (1);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd_r, fd_w;

	if (check_arguments(argc, argv) < 0)
		exit(97);

	fd_r = open_file(argv[1], O_RDONLY);
	if (fd_r < 0)
		exit(98);

	fd_w = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_w < 0)
	{
		close_file(fd_r);
		exit(99);
	}

	if (copy_file(fd_r, fd_w) < 0)
	{
		close_file(fd_r);
		close_file(fd_w);
		exit(99);
	}

	if (close_file(fd_r) < 0 || close_file(fd_w) < 0)
		exit(100);

	return (0);
}
