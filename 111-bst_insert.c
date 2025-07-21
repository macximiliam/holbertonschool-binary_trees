#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node
 * @value: Value to insert
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
			return ((*tree)->left = binary_tree_node(*tree, value));
		return (bst_insert(&(*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
			return ((*tree)->right = binary_tree_node(*tree, value));
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL); /* Valor duplicado */
}
