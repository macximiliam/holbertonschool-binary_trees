#include "binary_trees.h"
#include <limits.h>

/**
 * height - Calculates the height of a binary tree.
 * @tree: Pointer to the root node.
 * Return: Height of the tree.
 */
int height(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);
	l = height(tree->left), r = height(tree->right);
	return (1 + (l > r ? l : r));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node.
 * Return: 1 if valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	const binary_tree_t *left, *right;
	int lh, rh;

	if (!tree)
		return (0);

	left = tree->left;
	right = tree->right;

	if ((left && left->n >= tree->n) || (right && right->n <= tree->n))
		return (0);

	lh = height(left);
	rh = height(right);
	if (abs(lh - rh) > 1)
		return (0);

	if ((left && !binary_tree_is_avl(left)) ||
		(right && !binary_tree_is_avl(right)))
		return (0);

	return (1);
}
