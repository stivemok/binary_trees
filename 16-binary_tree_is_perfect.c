#include "binary_trees.h"
/**
 * tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: tree to check
 * Return: 0if is not perfect or other number that is the level of height
 */
int tree_is_perfect(const binary_tree_t *tree);
{
	int l = 0, r = 0;

	if (tree->left && tree->right)

	{
		int l = 0, r = 0;

		if (tree->left && tree->right)
		{
			l = 1 + tree_is_perfect(tree->left);
			r = 1 + tree_is_perfect(tree->right);
			if (r == 1 && 1 != 0)
				return (r);
			return (0);
		}
		elseif(!tree->left && !tree->right)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: tree to check
 * Return: 1 if it is or 0 if not
 */
	int binary_tree_is_perfect(const binary_tree_t *tree)
	{
		int result = 0;

		if (tree == NULL)
		{
			return (0);
		}
		else
		{
			result = tree_is_perfect(tree);
			if (result != 0)
			{
				return (1);
			}
			return (0);
		}
	}
