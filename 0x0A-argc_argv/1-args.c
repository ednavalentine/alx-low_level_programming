#include "main.h"
#include <stdio.h>
/**
 * main - prints the number of arguments passed into it
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
