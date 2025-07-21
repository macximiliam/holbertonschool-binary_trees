#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - Recursive checker for BST validity
 * @tree: Current node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * Return: 1 if valid, 0 if not
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to root node
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
