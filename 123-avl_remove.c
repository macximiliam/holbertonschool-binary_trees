#include "binary_trees.h"
#include <stdlib.h>

/**
 * rebalance_node - Rebalances a subtree rooted at node
 * @node: Pointer to the root of the subtree
 *
 * Return: New root after rebalancing
 */
static avl_t *rebalance_node(avl_t *node)
{
	int balance = binary_tree_balance(node);

	if (balance > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}

/**
 * avl_remove_rec - Recursively removes value and rebalances
 * @root: Pointer to current subtree root
 * @value: Value to remove
 *
 * Return: New root after removal and rebalance
 */
static avl_t *avl_remove_rec(avl_t *root, int value)
{
	avl_t *succ;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove_rec(root->left, value);
	else if (value > root->n)
		root->right = avl_remove_rec(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			succ = root->left ? root->left : root->right;
			free(root);
			return (succ);
		}
		succ = root->right;
		while (succ->left)
			succ = succ->left;
		root->n = succ->n;
		root->right = avl_remove_rec(root->right, succ->n);
	}
	if (root)
		root = rebalance_node(root);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree and rebalances
 * @root: Pointer to the root node of the AVL tree
 * @value: Value to remove
 *
 * Return: Pointer to the new root after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = avl_remove_rec(root, value);

	if (new_root)
		new_root->parent = NULL;
	return (new_root);
}
