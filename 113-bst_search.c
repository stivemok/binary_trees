#include "binary_trees.h"

/**
 * bst_search - searchs for a value in BST
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to searchin the tree
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	if (tree == NULL)
		return (0);
	temp = (bst_t *)tree;
	while (temp)
	{
		if (temp->n == value)
			return (temp);
		if (temp->n > value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return (0);
}
