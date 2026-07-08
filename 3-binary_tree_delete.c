#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Description: If tree is NULL, do nothing. Uses post-order traversal
 * to free nodes to ensure children are freed before their parents.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* First delete both subtrees */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Then delete the node */
	free(tree);
}
