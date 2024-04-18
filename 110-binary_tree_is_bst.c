#include "binary_trees.h"
#include <limits.h>

/**
 * check_if_BST - recursive helper to binary_tree_is_bst
 * @tree: tree to check for BST
 * @prev: pointer to int, passed "by reference" to update during recursion
 *
 * Return: 1 if tree is a valid BST
 *         0 if not or tree is NULL
 */
int check_if_BST(const binary_tree_t *tree, int *prev)
{
	if (tree)
	{
		if (!check_if_BST(tree->left, prev))
			return (0);

		if (tree->n <= *prev)
			return (0);

		*prev = tree->n;

		return (check_if_BST(tree->right, prev));
	}
	return (1);
}


/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *                       by using a recursive helper function.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if `tree` is a valid Binary Search Tree, 0 otherwise
 *         or if `tree` is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (!tree)
		return (0);

	return (check_if_BST(tree, &prev));
}
