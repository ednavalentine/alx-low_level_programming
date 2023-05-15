#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: parameter to be used
 * @height: parameter to be used
 * Return: void
 */
int **alloc_grid(int width, int height)
{
	int ink, jum;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = (int **) malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);
	for (ink = 0; ink < height; ink++)
	{
		grid[ink] = (int *) malloc(sizeof(int) * width);
		if (grid[ink] == NULL)
		{
			for (jum = 0; jum < ink; jum++)
				free(grid[jum]);
			free(grid);
			return (NULL);
		}
		for (jum = 0; jum < width; jum++)
			grid[ink][jum] = 0;
	}
	return (grid);
}
