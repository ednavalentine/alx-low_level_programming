#include "main.h"
/**
 * times_table - prints the 9 times table, starting with 0
 * Return: nothing
 */
void times_table(void)
{
	int z, m, n;

	for (z = 0; z <= 9; z++)
	{
		for (m = 0; m <= 9; m++)
		{
			n = z * m;

			if ((n / 10) == 0)
			{
				if (m != 0)
					_putchar(' ');
				_putchar(n + '0');

				if (m == 9)
					continue;
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				_putchar((n / 10) + '0');
				_putchar((n % 10) + '0');
				if (m == 9)
					continue;
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}


