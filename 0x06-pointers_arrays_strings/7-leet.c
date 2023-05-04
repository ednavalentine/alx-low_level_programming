#include "main.h"
/**
 * leet - encodes a string into 1337
 * @s: the string to encode
 * Return: the encoded string
 */
char *leet(char *s)
{
	int ri, ju;
	char let_chars[] = "4433007711";
	char letters[] = "aAeEoOtTlL";

	for (ri = 0; s[ri] != '\0'; ri++)
	{
		for (ju = 0; letters[ju] != '\0'; ju++)
		{
			if (s[ri] == letters[ju])
			{
				s[ri] = let_chars[ju];
				break;
			}
		}
	}
	return (s);
}
