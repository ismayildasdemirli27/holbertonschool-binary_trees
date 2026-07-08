#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* First traverse the left subtree */
	binary_tree_postorder(tree->left, func);

	/* Then traverse the right subtree */
	binary_tree_postorder(tree->right, func);

	/* Finally process the root node */
	func(tree->n);
}
