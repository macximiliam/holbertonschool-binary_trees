#include "binary_trees.h"

/**
 * min - Finds the minimum node in a BST
 * @n: Root of the subtree
 * Return: Pointer to node with smallest value
 */
bst_t *min(bst_t *n)
{
	while (n->left)
		n = n->left;
	return (n);
}

/**
 * bst_remove - Removes a node from a BST
 * @r: Pointer to the root node
 * @v: Value to remove
 * Return: New root node
 */
bst_t *bst_remove(bst_t *r, int v)
{
	bst_t *t;

	if (!r)
		return (NULL);
	if (v < r->n)
		r->left = bst_remove(r->left, v);
	else if (v > r->n)
		r->right = bst_remove(r->right, v);
	else
	{
		if (!r->left || !r->right)
		{
			t = r->left ? r->left : r->right;
			if (t)
				t->parent = r->parent;
			free(r);
			return (t);
		}
		t = min(r->right), r->n = t->n, r->right = bst_remove(r->right, t->n);
	}
	return (r);
}
