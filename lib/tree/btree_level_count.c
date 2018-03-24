/*
** EPITECH PROJECT, 2017
** File Name : btree_level_count.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"

int btree_level_count(btree_t const *root)
{
	int nb_level = 0;

	if (root->left != NULL) {
		if (nb_level > 0)
			nb_level--;
		nb_level = btree_level_count(root->left);
	}
	if (root->right != NULL) {
		if (nb_level > 0)
			nb_level--;
		nb_level = btree_level_count(root->right);
	}
	return (nb_level + 1);
}
