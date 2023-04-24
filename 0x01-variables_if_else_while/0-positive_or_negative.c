#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 * Description: Know whether int n is postive, negative or equal to zero,
 * the main function returns an integer value
 * Return - Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
		printf("n is postive\n");
	else if (n == 0)
	{
		printf("n is zero\n");
	}
	else
	{
		printf("n is negative\n");
	}
	return (0);
}
