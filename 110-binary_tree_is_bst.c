#include "binary_trees.h"
#include <limits.h>

/**
 * check_if_BST - recursive helper to binary_tree_is_bst
 * @tree: tree to check for BST
 * @prev: pointer to int, passed "by reference" to update during recursion
 * @min: minimum value allowed for a BST node
 * @max: maximum value allowed for a BST node
 *
 * Return: 1 if tree is a valid BST
 *         0 if not or tree is NULL
 */
int check_if_BST(const binary_tree_t *tree, int *prev, int min, int max)
{
	if (tree)
	{
		if (!check_if_BST(tree->left, prev, min, tree->n - 1) ||
			!check_if_BST(tree->right, prev, tree->n + 1, max))
			return (0);
		if (tree->n <= min || tree->n >= max)
			return (0);
		*prev = tree->n;
		return (1);
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int prev = INT_MIN;
	return (check_if_BST(tree, &prev, INT_MIN, INT_MAX));
}
