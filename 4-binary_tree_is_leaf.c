#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: A pointer to the node to check.
 *
 * Return: 1 if node is a leaf
 *         0 if not a leaf
 *         0 if node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int n = 0;

	if (node != NULL)
	{
		n = ((node->left == NULL) && (node->right == NULL) ? 1 : 0);
	}
	return (n);
}
