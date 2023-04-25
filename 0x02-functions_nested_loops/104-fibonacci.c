#include <stdio.h>
/**
 * main - print first 98 fibonaci sequences
 * starting with 1 and 2, followed by a new line
 * Return: 0
 */

int main(void)
{
	int count;
	unsigned long full1 = 0, full2 = 1, sum;
	unsigned long full1_half1, full1_half2, full2_half1, full2_half2;
	unsigned long half1, half2;

	for (count = 0; count < 92; count++)
	{
		sum = full1 + full2;
		printf("%lu, ", sum);

		full1 = full2;
		full2 = sum;
	}

	full1_half1 = full1 / 10000000000;
	full2_half1 = full2 / 10000000000;
	full1_half2 = full1 % 10000000000;
	full2_half2 = full2 % 10000000000;

	for (count = 93; count < 99; count++)
	{
		half1 = full1_half1 + full2_half1;
		half2 = full1_half2 + full2_half2;
		if (full1_half2 + full2_half2 > 9999999999)
		{
			half1 += 1;
			half2 %= 10000000000;
		}

		printf("%lu%lu", half1, half2);
		if (count != 98)
			printf(", ");

		full1_half1 = full2_half1;
		full1_half2 = full2_half2;
		full2_half1 = half1;
		full2_half2 = half2;
	}
	printf("\n");
	return (0);
}
