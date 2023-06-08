#include "binary_trees.h"
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: apointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL tree
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bt_avl(tree, INT_MIN, INT_MAX));
}

/**
 * bt_avl - checks if a binary tree is a valid AVL
 * @tree: pointer to the root node
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if tree is a valid AVL tree
 */
int bt_avl(const binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	left = tree->left ? 1 + bt_height(tree->left) : 0;
	right = tree->right ? 1 + bt_height(tree->right) : 0;
	if (abs(left - right) > 1)
		return (0);
	return (bt_avl(tree->left, min, tree->n - 1) &&
		bt_avl(tree->right, tree->n + 1, max));
}

/**
 * bt_height - measure the height of a binary tree
 * @tree: tree to measure the height
 * Return: height of tree
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = 0;
	right_height = 0;
	if (tree == NULL)
		return (0);
	left_height = tree->left ? 1 + bt_height(tree->left) : 0;
	right_height = tree->right ? 1 + bt_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}
