#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	return (!tree ? NULL :
		   tree->n == value ? (bst_t *)tree :
		   value < tree->n ? bst_search(tree->left, value) :
		   bst_search(tree->right, value));
}
