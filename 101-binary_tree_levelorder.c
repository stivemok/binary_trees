#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through binary tree using levelorder traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t max, level;

	if (tree == NULL || func == NULL)
		return;
	max = binary_tree_height(tree) + 1;
	for (level = 1; level <= max; level++)
		binary_tree_porder(tree, func, level);
}

/**
 * binary_tree_porder - goes through binary tree using post-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * @level: level of a tree to call function
 */
void binary_tree_porder(const binary_tree_t *tree, void (*func)(int),
size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		binary_tree_porder(tree->left, func, level - 1);
		binary_tree_porder(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - finds the height of a binary tree
 * @tree: a tree to measere the height
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftheight, rightheight;

	leftheight = 0;
	rightheight = 0;
	if (tree == NULL)
		return (0);
	leftheight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rightheight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (leftheight > rightheight ? leftheight : rightheight);
}
