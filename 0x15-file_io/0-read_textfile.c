#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX
 * standard output.
 * @filename: file to be read.
 * @letters: number of letters to read and print
 *
 * Return: number of bytes read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	int fd, bytes_read, bytes_written;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);
	close(fd);

	return (bytes_written);
}
