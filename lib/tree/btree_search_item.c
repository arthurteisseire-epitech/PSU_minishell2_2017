/*
** EPITECH PROJECT, 2017
** File Name : btree_search_item.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"

void *btree_search_item(btree_t const *root, void const *item, int (*cmpf)())
{
	void *rvalue = NULL;

	if (root->left != NULL)
		rvalue = btree_search_item(root->left, item, cmpf);
	if (cmpf(root->item, item) == 0)
		return (root->item);
	if (root->right != NULL)
		rvalue = btree_search_item(root->right, item, cmpf);
	return (rvalue);
}
