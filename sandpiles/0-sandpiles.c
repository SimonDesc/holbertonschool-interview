#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sandpiles.h"

/**
 * print_grid2 - prints a 3x3 grid of integers.
 * @grid: The parameter "grid" is a 2-dimensional array of
 * integers with dimensions 3x3.
 */
void print_grid2(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - takes two 3x3 grids as input
 * adds them together, and then performs
 * toppling operations on the resulting grid until all values
 * are less than or equal to 3.
 * @grid1: A 3x3 integer array representing the first sandpile grid.
 * @grid2: The `grid2` parameter is a 2D array of integers with dimensions 3x3.
 * It represents the second sandpile grid that will be added to the first grid
 * (`grid1`) in the `sandpiles_sum` function.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	add_matrix(grid1, grid2);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				printf("=\n");
				print_grid2(grid1);
				toppling(grid1);

				i = 0;
				j = 0;
			}
		}
	}
}

/**
 * toppling - takes a 3x3 grid as input and performs a toppling
 * operation on each element
 * of the grid, reducing the value by 4 and distributing the excess to
 * neighboring elements.
 * @grid1: The parameter `grid1` is a 2-dimensional array of integers
 * with dimensions 3x3.
 */
void toppling(int grid1[3][3])
{
	int i, j;

	int gridTemp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;

				if (i - 1 >= 0)
				{
					gridTemp[i - 1][j]++;
				}
				if (j - 1 >= 0)
				{
					gridTemp[i][j - 1]++;
				}
				if (j + 1 < 3)
				{
					gridTemp[i][j + 1]++;
				}
				if (i + 1 < 3)
				{
					gridTemp[i + 1][j]++;
				}
			}
		}
	}
	add_matrix(grid1, gridTemp);
}

/**
 * add_matrix - takes two 3x3 matrices as input and adds
 * them element-wise, modifying the first matrix.
 *
 * @grid1: A 2D array of integers representing the first matrix.
 * @grid2: The parameter `grid2` is a 2-dimensional array of integers with
 * dimensions 3x3.
 * It represents the second matrix that will be added to the first matrix
 * (`grid1`).
 */
void add_matrix(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}
