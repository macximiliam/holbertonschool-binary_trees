#include "binary_trees.h"

/**
 * binary_trees_ancestor - Encuentra el ancestro común más bajo de dos nodos
 * @first: Puntero al primer nodo
 * @second: Puntero al segundo nodo
 * Return: Puntero al ancestro común, o NULL si no hay
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	const binary_tree_t *temp_first, *temp_second;

	if (!first || !second)
		return (NULL);

	for (temp_first = first; temp_first; temp_first = temp_first->parent)
	{
		for (temp_second = second; temp_second; temp_second = temp_second->parent)
		{
			if (temp_first == temp_second)
				return ((binary_tree_t *)temp_first);
		}
	}

	return (NULL);
}
