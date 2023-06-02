#include "binary_trees.h"
/**
 * bst_remove - removes a node from BST
 * @root: a pointer to the root node of the tree to remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursion(root, root, value));
}

/**
 * bst_remove_recursion - recursively removes a node from BST
 * @root: a pointer to the root node of BST
 * @node: a pointer to the current node in BST
 * @value: the value to remove in BST
 * Return: a pointer to the root node after removing
 */
bst_t *bst_remove_recursion(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursion(root, node->left, value));
		else
			return (bst_remove_recursion(root, node->right, value));
	}
	return (0);
}

/**
 * bst_delete - deletes a node from BST
 * @root: a pointer to the root node of BTS
 * @node: a pointer to the node to delete
 * Return: a pointer to the root node after deletion
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent, *successor;

	successor = NULL;
	parent = node->parent;
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}
	else if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}
	successor = inorder_successor(node->right);
	node->n = successor->n;
	return (bst_delete(root, successor));
}

/**
 * inorder_successor - find min value of BST
 * @root: a pointer to the root node of BST
 * Return: min value
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
