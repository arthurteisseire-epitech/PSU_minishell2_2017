/*
** EPITECH PROJECT, 2017
** File Name : btree_create_node.c
** File description:
** By Arthur Teisseire
*/

#include "btree.h"

btree_t *btree_create_node(void *item)
{
	btree_t *tree = malloc(sizeof(btree_t));

	tree->item = item;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}
