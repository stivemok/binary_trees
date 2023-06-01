#include "binary_trees.h"

/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	return (bt_complete(tree, 0, size));
}

/**
 * bt_complete - check if binary tree is complete
 * @tree: a pointer to the root node
 * @index: node index
 * @size: size of nodes
 * Return: size of tree
 */
int bt_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (bt_complete(tree->left, 2 * index + 1, size) &&
		bt_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - finds the size of a binary tree
 * @tree: tree to find the size
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
