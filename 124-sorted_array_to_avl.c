#include "binary_trees.h"

/**
 * build_avl - Recursively builds AVL from sorted array
 * @arr: Array
 * @start: Start index
 * @end: End index
 * @parent: Parent node
 * Return: Pointer to created node
 */
avl_t *build_avl(int *arr, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, arr[mid]);
	if (!node)
		return (NULL);

	node->left = build_avl(arr, start, mid - 1, node);
	node->right = build_avl(arr, mid + 1, end, node);
	return (node);
}

/**
 * sorted_array_to_avl - Builds AVL tree from sorted array
 * @array: Array to convert
 * @size: Array size
 * Return: Root node of AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (build_avl(array, 0, size - 1, NULL));
}
