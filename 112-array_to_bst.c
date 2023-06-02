#include "binary_trees.h"
/**
 * array_to_bst - builds a binary search tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: a pointer to the root node of the created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
