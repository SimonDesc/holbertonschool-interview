#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - check if list is a cycle or not
 * @list: linked list to check
 * Return: 1 or 0 if failure
 */

int check_cycle(listint_t *list)
{
	listint_t *slow_p = list, *fast_p = list;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			return (1);
		}
	}
	return (0);
}
