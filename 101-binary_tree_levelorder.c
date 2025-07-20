#include "binary_trees.h"

/**
 * binary_tree_levelorder - Recorre un árbol
 * binario usando recorrido por niveles
 * @tree: Puntero al nodo raíz del árbol a recorrer
 * @func: Puntero a una función que se llamará para cada valor del nodo
 *
 * Description: Utiliza una cola (implementada como arreglo estático)
 * para recorrer el árbol nivel por nivel, aplicando la función
 * pasada como parámetro a cada nodo visitado.
 * Si tree o func es NULL, no hace nada.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[1024];
	size_t front = 0, rear = 0;

	if (!tree || !func)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *node = queue[front++];

		func(node->n);

		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}
}
