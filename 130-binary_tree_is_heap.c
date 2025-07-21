#include "binary_trees.h"

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to root
 * Return: Number of nodes
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * check_heap - Recursively checks for completeness and max-heap property
 * @tree: Pointer to root
 * @index: Current node index (like array)
 * @size: Total number of nodes
 * Return: 1 if valid Max Heap, 0 otherwise
 */
int check_heap(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	if ((tree->left && tree->n < tree->left->n) ||
		(tree->right && tree->n < tree->right->n))
		return (0);

	return (check_heap(tree->left, 2 * index + 1, size) &&
		check_heap(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node
 * Return: 1 if valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = count_nodes(tree);
	return (check_heap(tree, 0, size));
}
