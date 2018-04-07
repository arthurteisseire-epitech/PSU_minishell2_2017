/*
** EPITECH PROJECT, 2017
** File Name : semi_colons.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "btree.h"

int semi_colons(btree_t *root)
{
	cmd_t *left = root->left->item;

	left->array = split(left->str, " \t");
	execout_to_pipe(left);
	my_fdcpy(1, left->pipefd[0]);
	return (0);
}
