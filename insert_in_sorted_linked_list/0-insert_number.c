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
			if (current->next->n > number){
				new->next = current->next->next;
				current->next = new;
				break;
			}
			current = current->next;
			}
	}

	return (new);
}
