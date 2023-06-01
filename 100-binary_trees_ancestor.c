#include "binary_trees.h"

/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	size_t firstdepth, seconddepth;

	if (!first || !second)
		return (NULL);
	firstdepth = binary_tree_depth(first);
	seconddepth = binary_tree_depth(second);
	while (firstdepth > seconddepth)
	{
		first = first->parent;
		firstdepth--;
	}
	while (seconddepth > firstdepth)
	{
		second = second->parent;
		seconddepth--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - finds the depth of a node
 * @tree: a pointer to the node depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
