#include "main.h"
/**
 * print_times_table - prints the n times table, starting with 0
 * @n: number of the multipication table
 */
void print_times_table(int n)
{
	int xy, yy, yx;

	if (n >= 0 && n <= 14)
	{
		for (xy = 0; xy <= n; xy++)
		{
			for (yy = 0; yy <= n; yy++)
			{
				yx = xy * yy;
				if (yx > 99)
				{
					_putchar(',');
					_putchar(32);
					_putchar((yx / 100) + '0');
					_putchar(((yx / 10) % 10) + '0');
					_putchar((yx % 10) + '0');
				}
				else if (yx > 9)
				{
					_putchar(',');
					_putchar(32);
					_putchar(32);
					_putchar(((yx / 10) % 10) + '0');
					_putchar((yx % 10) + '0');
				}
				else
				{
					if (yy != 0)
					{
						_putchar(',');
						_putchar(32);
						_putchar(32);
						_putchar(32);
					}
					_putchar(yx + '0');
				}
			}
			_putchar('\n');
		}
	}
}
