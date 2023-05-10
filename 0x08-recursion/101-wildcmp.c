#include "main.h"
/**
 * wildcmp - compares two strings
 * @s1: parameeter to be used
 * @s2: parameter to be used
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
	{
		return ((*s1 == '\0') ? 1 : 0);
	}
	else if (*s2 == '*')
	{
		if (*(s2+1) == '\0')
		{
			return (1);
		}
		else
		{
			return ((*s1 == '\0') ? wildcmp(s1, s2+1) : (wildcmp(s1, s2+1) || wildcmp(s1+1, s2)));
		}
	}
	else
	{
	return ((*s1 == *s2) ? wildcmp(s1+1, s2+1) : 0);
	}
}
