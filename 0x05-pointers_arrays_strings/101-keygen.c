#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - program that generates random valid passwords
 * Return: Always 0 (Success)
 */
int main(void)
{
	int passw[100];
	int iou, sumu, ni;

	sumu = 0;

	srand(time(NULL));
	for (iou = 0; iou < 100; iou++)
	{
		passw[iou] = rand() % 78;
		sumu += (passw[iou] + '0');
		putchar(passw[iou] + '0');
		if ((2772 - sumu) - '0' < 78)
		{
			ni = 2772 - sumu - '0';
			sumu += ni;
			putchar(ni + '0');
			break;
		}
	}
	return (0);
}
