#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * The function `insert_node` inserts a new node with a given number into a sorted linked list.
 * 
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * 
 * @return a pointer to the newly inserted node.
 */
listint_t *insert_node(listint_t **head, int number) 
{
	listint_t *new;
    listint_t *current;
	listint_t *tmp;
	int found = 0;

	current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
	else
	{
		while (current->next != NULL) {
			if (number < current->n) {
				new->next = current;
				found = 1;
				*head = new;
				break;
			}

			if (current->next->n > number) {
				tmp = current->next;
				tmp->next = current->next->next;
				new->next = tmp;
				current->next = new;
				found = 1;
				break;
			}
			current = current->next;
		}
		if (found == 0) {
			current->next = new;
		}
		
	}

	return (new);
}
