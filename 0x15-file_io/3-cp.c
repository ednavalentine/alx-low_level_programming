#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFF 1024

/**
 * print_error - prints an error
 * @message: error message
 * Return: void
 */
void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(1);
}
/**
 * main - main code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *ink_from;
	const char *ink_to;
	int mode_from;
	int mode_to;
	char buffer[BUFF];
	ssize_t ink_read, ink_write;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp ink_from ink_to\n");
		exit(97);
	}
	ink_from = argv[1];
	ink_to = argv[2];
	mode_from = open(ink_from, O_RDONLY);
	if (mode_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		exit(98);
	}
	mode_to = open(ink_to, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (mode_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file\n");
		exit(99);
	}
	while ((ink_read = read(mode_from, buffer, BUFF)) > 0)
	{
		ink_write = write(mode_to, buffer, ink_read);
		if (ink_write == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			exit(99);
		}
	}
	if (ink_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read to file\n");
		exit(99);
	}
	if (close(mode_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(100);
	}
	if (close(mode_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(100);
	}
	if (chmod(ink_to, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't set file permissions\n");
		exit(100);
	}
	return (0);
}
