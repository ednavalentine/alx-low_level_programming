#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define BUFF 1024

/**
 * print_error_and_exit - prints an error and exits
 * @error_message: error message
 * @exit_code: code exit
 * Return: void
 */
void print_error_and_exit(const char *error_message, int exit_code)
{
	dprintf(STDERR_FILENO, "%s\n", error_message);
	exit(exit_code);
}
/**
 * copy_file - copys a file
 * @file_from: origin of the file
 * @file_to: destination of the file
 * Return: void
 */
void copy_file(const char *file_from, const char *file_to)
{
	int org_file, dest_file;
	ssize_t mode_read, mode_written;
	char ink[BUFF];

	org_file = open(file_from, O_RDONLY);
	if (org_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	dest_file = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_file == -1)
	{
		if (errno == EACCES)
		{
			dprintf(STDERR_FILENO, "Error: Permission denied to write %s\n", file_to);
		}
		else
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		}
		exit(99);
	}
	while ((mode_read = read(org_file, ink, BUFF)) > 0)
	{
		mode_written = write(dest_file, ink, mode_read);
		if (mode_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		if (mode_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
			exit(98);
		}
	}
	if (close(org_file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", org_file);
		exit(100);
	}
	if (close(dest_file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_file);
		exit(100);
	}
}
/**
 * main - main code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *ink;
	const char *inker;
	struct stat st;

	if (argc != 3)
	{
		print_error_and_exit("Usage: cp file_from file_to", 97);
	}
	ink = argv[1];
	inker = argv[2];
	if (stat(inker, &st) != -1)
	{
		if (truncate(inker, 0) == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", inker);
			exit(99);
		}
	}
	copy_file(ink, inker);
	if (chmod(inker, 0664) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't set permissions for %s\n", inker);
		exit(99);
	}
	return (0);
}
