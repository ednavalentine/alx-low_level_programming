#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 * Description: 'prints out a postive negative or zero as answer'
 * Return - Always 0 (Success)
 * betty coding style
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
		printf("%d is postive\n");
	else if (n == 0)
	{
		printf("%d is zero\n");
	}
	else
	{
		printf("%d is negative\n");
	}
	return (0);
}
