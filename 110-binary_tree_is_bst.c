#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_search_tree(tree, INT_MIN, INT_MAX));
}

/**
 * binary_search_tree - checkes a valid BST
 * @tree: a pointer to the root node of the tree
 * @min: lower bound of node checked
 * @max: upper bound of node checked
 * Return: 1 if tree is a valid BST
 */
int binary_search_tree(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (binary_search_tree(tree->left, min, tree->n - 1) &&
		binary_search_tree(tree->right, tree->n + 1, max));
}
