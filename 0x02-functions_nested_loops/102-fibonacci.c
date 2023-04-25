#include <stdio.h>

/**
  * main - Prints the first 52 fibonacci numbers
  * begining with 1 and 2, followed by a new line
  * Return: Always 0 (Success)
  */
int main(void)
{
	int ink = 0;
	long jug = 1, kat = 2;

	while (ink < 50)
	{
		if (ink == 0)
			printf("%ld", jug);
		else if (ink == 1)
			printf(", %ld", kat);
		else
		{
			kat += jug;
			jug = kat - jug;
			printf(", %ld", kat);
		}

		++ink;
	}

	printf("\n");
	return (0);
}
