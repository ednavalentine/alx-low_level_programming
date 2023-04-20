#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char h;
int i;
long int l;
long long int o;
float f;

	printf("Size of a char: %lu byte(s) \n", (unsigned long)sizeof(h));
	printf("Size of an int: %lu byte(s) \n", (unsigned long)sizeof(i));
	printf("Size of a long int: %lu byte(s) \n", (unsigned long)sizeof(l));
	printf("Size of a long long int: %lu byte(s) \n", (unsigned long)sizeof(o));
	printf("Size of a float: %lu byte(s) \n", (unsigned long)sizeof(f));
	return (0);
}
