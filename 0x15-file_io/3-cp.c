#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF 1024

/**
 * print_error - prints an error
 * @message: error message
 * Return: void
 */
void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
}
/**
 * exit_with_error - exits with an error message
 * @message: error message
 * @exit_code: the exit point of the code
 * Return: void
 */
void exit_with_error(const char *message, int exit_code)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
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
		exit_with_error("Usage: cp ink_from ink_to", 97);
	ink_from = argv[1];
	ink_to = argv[2];
	mode_from = open(ink_from, O_RDONLY);
	if (mode_from == -1)
		exit_with_error("Error: Can't read from file", 98);
	mode_to = open(ink_to, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (mode_to == -1)
		exit_with_error("Error: Can't write to file", 99);
	while ((ink_read = read(mode_from, buffer, BUFF)) > 0)
	{
		ink_write = write(mode_to, buffer, ink_read);
		if (ink_write == -1)
			exit_with_error("Error: Can't write to file", 99);
	}
	if (ink_read == -1)
		exit_with_error("Error: Can't write to file", 99);
	if (close(mode_from) == -1)
		exit_with_error("Error: Can't close fd", 100);
	if (close(mode_to) == -1)
		exit_with_error("Error: Can't close fd", 100);
	if (chmod(ink_to, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH) == -1)
		exit_with_error("Error: Can't set file permissions", 100);
	return (0);
}
