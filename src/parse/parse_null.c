/*
** EPITECH PROJECT, 2017
** File Name : parse_null.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "btree.h"
#include "mysh.h"

int parse_null(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *left;
	cmd_t *right;

	if (this->exec != NULL && this->exec != semi_colons) {
		if (root->right == NULL || root->left == NULL) {
			my_putstr("Invalid null command.\n");
			return (ERROR);
		}
		left = root->left->item;
		printf("LEFT: %s\n", left->str);
		right = root->right->item;
		printf("RIGHT: %s\n", right->str);
	}
	return (0);
}
