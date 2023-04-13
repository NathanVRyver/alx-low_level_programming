#include "main.h"

/**
 * create_file - creates a file with the given name and writes
 * the given text content to it.
 * @filename: name of file to create
 * @text_content: text content to write to file, NULL to create an empty file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written;
	size_t text_len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		text_len = strlen(text_content);
		bytes_written = write(fd, text_content, text_len);
		if (bytes_written == -1 || (size_t)bytes_written != text_len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
