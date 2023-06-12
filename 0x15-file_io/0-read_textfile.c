#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * read_textfile - reads a text file
 * @filename: pointer to file name
 * @letters: number of letters it should read and print
 * Return: textfile
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *mode;
	FILE *cat;
	ssize_t ink_read;
	ssize_t ink_written;

	if (filename == NULL)
	{
		return (0);
	}
	mode = malloc((letters + 1) * sizeof(char));
	if (mode == NULL)
	{
		return (0);
	}
	cat = fopen(filename, "r");
	if (cat == NULL)
	{
		return (0);
	}
	ink_read = fread(mode, sizeof(char), letters, cat);
	if (ink_read <= 0)
	{
		fclose(cat);
		free(mode);
		return (0);
	}
	mode[ink_read] = '\0';
	ink_written = fwrite(mode, sizeof(char), ink_read, stdout);
	fclose(cat);
	free(mode);
	if (ink_written != ink_read)
	{
		return (0);
	}
	return (ink_written);
}
