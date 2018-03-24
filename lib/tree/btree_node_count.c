/*
** EPITECH PROJECT, 2017
** File Name : btree_node_count.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"

int btree_node_count(btree_t const *root)
{
	int nb_node = 1;

	if (root->left != NULL)
		nb_node += btree_node_count(root->left);
	if (root->right != NULL)
		nb_node += btree_node_count(root->right);
	return (nb_node);
}
