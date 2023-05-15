#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * strtow - splits a string into words
 * @str: String to be split
 * Return: void
 */
char **strtow(char *str)
{
	char **word;
	int ium, jum, kum, num;

	if (str == NULL || *str == '\0')
		return (NULL);
	num = count_words(str);
	if (num == 0)
		return (NULL);
	word = (char **) malloc((num + 1) * sizeof(char *));
	if (word == NULL)
		return (NULL);
	for (ium = 0, jum = 0; ium < num; ium++)
	{
		while (str[jum] == ' ')
			jum++;
		word[ium] = (char *) malloc((word_len(&str[jum]) + 1) * sizeof(char));
		if (word[ium] == NULL)
		{
			for (kum = 0; kum < ium; kum++)
			{
				free(word[kum]);
			}
			free(word);
			return (NULL);
		}
		for (kum = 0; str[jum] != '\0' && str[jum] != ' '; jum++, kum++)
			word[ium][kum] = str[jum];
		word[ium][kum] = '\0';
	}
	word[ium] = NULL;
	return (word);
}

/**
 * count_words - Counts the number of words in a string
 * @str: String to be counted
 * Return: void
 */
int count_words(char *str)
{
	int ink, count = 0;

	for (ink = 0; str[ink] != '\0'; ink++)
		if (str[ink] != ' ' && (ink == 0 || str[ink - 1] == ' '))
			count++;
	return (count);
}

/**
 * word_len - Calculates the length of a word
 * @str: String containing the word
 * Return: void
 */
int word_len(char *str)
{
	int len = 0;

	while (str[len] != '\0' && str[len] != ' ')
		len++;
	return (len);
}
