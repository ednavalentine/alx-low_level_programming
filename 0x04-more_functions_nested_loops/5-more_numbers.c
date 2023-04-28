#include "main.h"
/**
 * more_numbers - prints ten numbers from 0-14 only using the _putchar 3 times
 * Description: you can only use _putchar three times in your code
 */
void more_numbers(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j > 9)
			{
				_putchar((j / 10) + '0');
			}
				_putchar((j % 10) + '0');
		}
	_putchar('\n');
	}
}
