#include "binary_trees.h"

/**
 * _depth - Returns the depth of the leftmost leaf
 * @tree: Pointer to the root node
 *
 * Return: Depth of the tree
 */
int _depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_recursive - Recursive helper function
 * @tree: Pointer to the root node
 * @d: Depth of the leftmost leaf
 * @level: Current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (0);

	/* Check if it is a leaf */
	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	/* If one child is NULL and the other is not, it's not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Recursively check left and right subtrees */
	return (is_perfect_recursive(tree->left, d, level + 1) &&
		is_perfect_recursive(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = _depth(tree);
	return (is_perfect_recursive(tree, d, 0));
}
