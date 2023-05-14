#include "main.h"
#include <stdio.h>
/**
 * main - prints all arguments it receives
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */
int main(int argc, char *argv[])
{
	int ink;

	for (ink = 0; ink < argc; ink++)
	{
		printf("%s\n", argv[ink]);
	}
	return (0);
}
