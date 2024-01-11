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

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

	// On check si la liste est vide ou si le premier élément est le plus petit
    if (*head == NULL || (*head)->n >= number)
	{
		new->next = *head;
		*head = new;
		return new;
	}

	current = *head;
	// On recherche la position de la node qu'on récupère dans current
	while (current->next != NULL && current->next->n < number)
	{
		current = current->next;
	}

	// On prend la place de current
	new->next = current->next;
	current->next = new;

	return (new);
}
