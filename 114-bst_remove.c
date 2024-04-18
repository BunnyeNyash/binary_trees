#include "binary_trees.h"

/**
 * remove_type - Determine the type of removal needed for a BST node
 * @node: The node for which removal type is determined
 *
 * Return: Type of removal needed
 *         0 if no removal
 *         1 if left child
 *         2 if right child)
 */
int remove_type(bst_t *node)
{
	if (node->left != NULL && node->right == NULL)
		return (1);
	else if (node->left == NULL && node->right != NULL)
		return (2);
	else
		return (0);
}


/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of tree which will have a node removed
 * @value: value to remove from tree
 *
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
