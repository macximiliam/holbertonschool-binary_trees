#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *queue[1024];
	size_t front = 0, rear = 0;
	int found_null_child = 0;

	if (tree == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *node = queue[front++];

		if (node->left)
		{
			if (found_null_child)
				return (0);
			queue[rear++] = node->left;
		}
		else
			found_null_child = 1;

		if (node->right)
		{
			if (found_null_child)
				return (0);
			queue[rear++] = node->right;
		}
		else
			found_null_child = 1;
	}

	return (1);
}
