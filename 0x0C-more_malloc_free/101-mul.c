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
	int reversedNumber = 0;
	int tempNumber = number;

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

	while (tempNumber != 0)
	{
		reversedNumber = reversedNumber * 10 + (tempNumber % 10);
		tempNumber /= 10;
	}
	while (reversedNumber != 0)
	{
		_putchar((reversedNumber % 10) + '0');
		reversedNumber /= 10;
	}
}
/**
 * printError - print an error
 * Return: void
 */
void printError()
{
	const char* error = "Error\n";

	while (*error)
	{
		_putchar(*error);
		error++;
	}
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
	
	if ((argc != 3 || !isNumber(argv[1]) || !isNumber(argv[2])))
	{
		printError();
		return (98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	
	result = multiply(num1, num2);
	printNumber(result);
	_putchar('\n');
	return (0);
}
