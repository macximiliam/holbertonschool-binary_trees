#include "binary_trees.h"
#include <limits.h>

/**
 * is_avl_helper - Recursively checks if a tree is a valid AVL tree.
 * @tree: Pointer to current node.
 * @min: Minimum allowed value for the current subtree.
 * @max: Maximum allowed value for the current subtree.
 * @height: Pointer to store the height of current subtree.
 *
 * Return: 1 if subtree is AVL, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max, int *height)
{
	int left_height = 0, right_height = 0;
	int left_avl = 0, right_avl = 0;
	int balance = 0;

	if (!tree)
	{
		*height = 0;
		return (1);
	}

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_avl = is_avl_helper(tree->left, min, tree->n, &left_height);
	right_avl = is_avl_helper(tree->right, tree->n, max, &right_height);
	balance = left_height - right_height;

	if (!left_avl || !right_avl || balance < -1 || balance > 1)
		return (0);

	*height = (left_height > right_height ? left_height : right_height) + 1;
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX, &height));
}
