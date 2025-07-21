#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to root node.
 * @value: Value to remove.
 * Return: New root after deletion and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;
	int balance;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = root->right;
		while (temp->left)
			temp = temp->left;
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	balance = binary_tree_balance(root);
	if (balance > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
