#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * multiply - passed in base 10
 * @numb1: parameter to used
 * @numb2: parameter to used
 * Return: void
 */
int multiply(int num1, int num2)
{
	return (num1 * num2);
}
/**
 * isNumber - to check if its a number
 * @str: parameter to be used
 * Return: void
 */
int isNumber(const char* str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * printNumber - prints number
 * @number: no to be printed
 * Return: void
 */
void printNumber(int number)
{
	int digits = 0;
	int temp = number;
	char* output;
	char* ptr;
	int i;

	if (number == 0)
	{
		_putchar('0');
		return;
	}
	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}
	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}
	output = (char *)malloc(digits + 1);
	if (output == NULL)
	{
		exit(1);
	}
	for (i = digits - 1; i >= 0; i--)
	{
		output[i] = (number % 10) + '0';
		number /= 10;
	}
	output[digits] = '\0';
	ptr = output;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
	free(output);
}
/**
 * main - print 2 positive numbers
 * @argc: argument count
 * @argcv: argument vector
 * Return: void
 */
int main(int argc, char* argv[])
{
	int num1;
	int num2;
	int result;
	
	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}
	if (!isNumber(argv[1]) || !isNumber(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = multiply(num1, num2);

	printNumber(result);
	_putchar('\n');
	return (0);
}
