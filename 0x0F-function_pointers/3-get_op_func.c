#include "3-calc.h"
#include <stddef.h>
/**
 * get_op_func - selects the correct function
 * @s: operator passed as an argument to program
 * Return: pointer to function or NULL
 */
int (*get_op_func(char *s))(int, int)
{
	int ink = 0;

	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	while (ops[ink].op != NULL)
	{
		if (*(ops[ink].op) == *s && *(s + 1) == '\0')
			return (ops[ink].f);
		ink++;
	}
	return (NULL);
}
