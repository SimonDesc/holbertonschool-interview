#include <stdio.h>
#include <math.h>

#include "menger.h"
/**
 * drawMenger - draw each level of the Menger Sponge
 *
 * @level: current level of the Menger Sponge
 * @size: size
 * @row: row index
 * @col: column index
 */

void drawMenger(int level, int size, int row, int col)
{
	int newSize, isCenterEmpty;

	if (level == 0)
	{
		printf("#");
	}
	else
	{
		newSize = size / 3;
		isCenterEmpty = (row >= newSize && row < 2 * newSize) &&
						(col >= newSize && col < 2 * newSize);

		if (isCenterEmpty)
		{
			printf(" ");
		}
		else
		{
			drawMenger(level - 1, newSize, row % newSize, col % newSize);
		}
	}
}
/**
 * menger - Menger Sponge
 *
 * @level: level of the Menger Sponge
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
	{
		return;
	}

	size = (int)pow(3, level);

	for (i = 0; i < size; i++)
	{

		for (j = 0; j < size; j++)
		{
			drawMenger(level, size, i, j);
		}
		printf("\n");
	}
}
