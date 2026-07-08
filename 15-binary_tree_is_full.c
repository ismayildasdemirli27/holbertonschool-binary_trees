#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if full, 0 if not or if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If it's a leaf, it's full by definition */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If it has both children, check if both subtrees are full */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If it has only one child, it's not full */
	return (0);
}
