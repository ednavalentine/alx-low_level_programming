#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * read_textfile - reads a text file
 * @filename: pointer to file name
 * @letters: number of letters it should read and print
 * Return: textfile
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int mode;
	char *ink;
	ssize_t ink_read;
	ssize_t ink_written;

	if (filename == NULL)
	{
		return (0);
	}
	mode = open(filename, O_RDONLY);
	if (mode == -1)
		return (0);
	ink = malloc(sizeof(char) * letters);
	if (ink == NULL)
	{
		close(mode);
		return (0);
	}
	ink_read = read(mode, ink, letters);
	close(mode);
	if (ink_read == -1)
	{
		free(ink);
		return (0);
	}
	ink_written = write(STDOUT_FILENO, ink, ink_read);
	if (ink_written != ink_read)
	{
		return (0);
	}
	return (ink_written);
}
