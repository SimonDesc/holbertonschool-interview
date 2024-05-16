#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */


void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (array == NULL)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0], array[0] = array[i], array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - heapifies the array
 *
 * @array: array to be sorted
 * @n: size of the array
 * @i: index
 * @size: size of the array
 *
 * Return: void
 */

void heapify(int *array, int n, int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i], array[i] = array[largest], array[largest] = temp;
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}

