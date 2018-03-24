/*
** EPITECH PROJECT, 2017
** File Name : btree_insert_data.c
** File description:
** By Arthur Teisseire
*/

#include "btree.h"

void btree_insert_data(btree_t *root, void *item, int (*cmpf)())
{
	if ((*cmpf)(item, root->item) < 0) {
		if (root->left != NULL)
			btree_insert_data(root->left, item, cmpf);
		else
			root->left = btree_create_node(item);
	} else {
		if (root->right != NULL)
			btree_insert_data(root->right, item, cmpf);
		else
			root->right = btree_create_node(item);
	}
}
