#include "main.h"
/**
 * puts2 - print every other character of string, starting with first character
 * @str: parameter to be used
 * Return: printed char
 */
void puts2(char *str)
{
	int logi = 0;
	int ti = 0;
	char *y = str;
	int on;

	while (*y != '\0')
	{
		y++;
		logi++;
	}
	ti = logi - 1;
	for (on = 0 ; on <= ti ; on++)
	{
	if (on % 2 == 0)
	{
		_putchar(str[on]);
	}
	}
	_putchar('\n');
}
