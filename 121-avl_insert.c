#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL tree.
 * @tree: Double pointer to the root node.
 * @value: Value to insert.
 * Return: Pointer to the inserted node or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;
	avl_t *node;

	if (!tree)
		return (NULL);

	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	node = (value < (*tree)->n) ?
		avl_insert(&(*tree)->left, value) :
		(value > (*tree)->n) ?
		avl_insert(&(*tree)->right, value) :
		NULL;

	if (!node)
		return (NULL);

	if (value < (*tree)->n && !(*tree)->left->parent)
		(*tree)->left->parent = *tree;
	if (value > (*tree)->n && !(*tree)->right->parent)
		(*tree)->right->parent = *tree;

	balance = binary_tree_balance(*tree);

	*tree = (balance > 1 && value < (*tree)->left->n) ?
		binary_tree_rotate_right(*tree) :
		(balance < -1 && value > (*tree)->right->n) ?
		binary_tree_rotate_left(*tree) :
		(balance > 1 && value > (*tree)->left->n) ?
		((*tree)->left = binary_tree_rotate_left((*tree)->left),
		binary_tree_rotate_right(*tree)) :
		(balance < -1 && value < (*tree)->right->n) ?
		((*tree)->right = binary_tree_rotate_right((*tree)->right),
		binary_tree_rotate_left(*tree)) :
		*tree;

	return (node);
}
