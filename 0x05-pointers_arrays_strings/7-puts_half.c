#include "main.h"
/**
 * puts_half - prints half of a string
 * @str: the parameter to be used
 * Return: half-string
 */
void puts_half(char *str)
{
	int yu, nu, zu;

	zu = 0;
	for (yu = 0; str[yu] != '\0'; yu++)
		zu++;
	nu = (zu / 2);
	if ((zu % 2) == 1)
		nu = ((yu + 1) / 2);
	for (yu = nu; str[yu] != '\0'; yu++)
		_putchar(str[yu]);
	_putchar('\n');
}
