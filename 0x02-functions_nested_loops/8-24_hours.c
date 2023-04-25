#include "main.h"
/**
 * jack_bauer - prints every minute of the day of Jack Bauer
 * starting from 00:00 and ends at 23:59
 */
void jack_bauer(void)
{
	int i, p;

	i = 0;

	while (i < 24)
	{
		p = 0;

		while (p < 60)
		{
			_putchar((i / 10) + '0');
			_putchar((i % 10) + '0');
			_putchar(':');
			_putchar((p / 10) + '0');
			_putchar((p % 10) + '0');
			_putchar('\n');
			p++;
		}
		i++;
	}
}

