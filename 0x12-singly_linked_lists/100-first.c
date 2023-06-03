#include <stdio.h>
/**
 * before_main - focus on this before the main file
 * Return: void
 */
void __attribute__((constructor)) print_before_main(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
