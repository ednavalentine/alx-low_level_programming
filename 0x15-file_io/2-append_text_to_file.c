#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of file
 * @text_content: NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *mode;
	size_t ink_len;
	size_t ink_write;

	if (filename == NULL)
		return (-1);
	mode = fopen(filename, "a");
	if (mode == NULL)
		return (-1);
	if (text_content != NULL)
	{
		ink_len = strlen(text_content);
		ink_write = fwrite(text_content, sizeof(char), ink_len, mode);
		if (ink_write < ink_len)
		{
			fclose(mode);
			return (-1);
		}
	}
	fclose(mode);
	return (1);
}
