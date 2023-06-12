#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: file
 */
int create_file(const char *filename, char *text_content)
{
	int ink;
	size_t mode;
	ssize_t cat;

	if (filename == NULL)
		return (-1);
	ink = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (ink == -1)
		return (-1);
	if (text_content != NULL)
	{
		mode = strlen(text_content);
		cat = write(ink, text_content, mode);
		if (cat == -1)
		{
			close(ink);
			return (-1);
		}
	}
	close(ink);
	return (1);
}

