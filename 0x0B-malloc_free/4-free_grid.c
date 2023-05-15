#include "main.h"
#include <stdlib.h>
/**
 * free_grid -  frees a 2 dimensional grid
 * @grid: parameter to be used
 * @height: parameter to be used
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int ink;

	for (ink  = 0; ink < height; ink++)
	{
		free(grid[ink]);
	}
	free(grid);
}
