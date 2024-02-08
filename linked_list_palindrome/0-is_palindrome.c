#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Check if it's a palindrome
 * @head: pointer to head of list
 * Return: 0 if palindrome, else 1
 */
int is_palindrome(listint_t **head)
{
	const listint_t *current;
	unsigned int n;
	int i, j = 0;
	int number_of_node = print_listint(*head) - 1;
	current = *head;
	n = 0;
	int *list_1 = malloc(number_of_node * sizeof(int));
	if (list_1 == NULL)
		return (1);
	int *list_2 = malloc(number_of_node * sizeof(int));
	if (list_2 == NULL)
		return (1);

	while (current != NULL)
	{
		list_1[n] = current->n;
		current = current->next;
		n++;
	}

	for (i = number_of_node; i >= 0; i--, j++)
	{
		list_2[j] = list_1[i];
	}

	for (i = 0; i < number_of_node; i++)
	{
		if (list_1[i] != list_2[i])
		{
			free(list_1);
			free(list_2);
			return (0);
		}
	}

	free(list_1);
	free(list_2);
	return (1);
}
