#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

static void insert_at_first_open_position(heap_t *current, heap_t *new_node,
										  int level, int *done)
{
	if (current == NULL || *done)
	{
		return;
	}

	/* Si nous sommes au niveau où un nœud peut être inséré. */
	if (level == 1)
	{
		/* Vérifier si l'enfant gauche est disponible. */
		if (!current->left)
		{
			current->left = new_node;
			new_node->parent = current;
			*done = 1;
		}
		/* Sinon, vérifier si l'enfant droit est disponible. */
		else if (!current->right)
		{
			current->right = new_node;
			new_node->parent = current;
			*done = 1;
		}
		else
		{
			/* Les deux enfants existent déjà */
			/* La fonction retourne pour chercher une position dans un autre nœud.*/
			return;
		}
	}

	else if (level > 1)
	{
		/* On descend dans les branches de l'arbre */
		insert_at_first_open_position(current->left, new_node, level - 1, done);
		insert_at_first_open_position(current->right, new_node, level - 1, done);
	}
}

static int tree_height(heap_t *root)
{
	if (root == NULL)
	{
		return (0);
	}

	int left_height = tree_height(root->left);
	int right_height = tree_height(root->right);

	if (left_height > right_height)
	{
		return (left_height + 1);
	}
	else
	{
		return (right_height + 1);
	}
}

heap_t *sift_up(heap_t *new_node)
{
	heap_t *current = new_node;
	heap_t *node_with_inserted_value = new_node;

	while (current->parent)
	{
		heap_t *parent = current->parent;

		if (parent->n < current->n)
		{
			int temp = parent->n;

			parent->n = current->n;
			current->n = temp;

			node_with_inserted_value = parent;

			current = parent;
		}
		else
		{
			break;
		}
	}

	return (node_with_inserted_value);
}

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!root)
		return (NULL);
	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;

	/* Si l'arbre est vide, le nouveau nœud devient la racine.*/
	if (!*root)
	{
		*root = new;
	}
	/* Sinon, trouver la position pour le nouvel élément. */
	else
	{
		int done = 0;
		/* On calcul la hauteur de l'arbre */
		int height = tree_height(*root);

		for (int level = 1; level <= height; ++level)
		{
			insert_at_first_open_position(*root, new, level, &done);
			if (done)
			{
				break;
			}
		}
		if (!done)
		{
			insert_at_first_open_position(*root, new, height + 1, &done);
		}
	}

	return (sift_up(new));
}
