#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read and write text from a file.
 * @filename: The name of the file to be read.
 * @letters: The number of letters to read and write.
 *
 * Return: The number of bytes written to stdout, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd, w, t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);

	return (w);
}
