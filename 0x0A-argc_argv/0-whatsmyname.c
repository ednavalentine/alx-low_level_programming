#include "main.h"
#include <stdio.h>
/**
 * main - program that prints its name
 * @argc: argument count
 * @argv[]: argument vector
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
