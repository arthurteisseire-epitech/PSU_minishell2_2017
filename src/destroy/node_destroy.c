/*
** EPITECH PROJECT, 2017
** File Name : btree_destroy.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"
#include "btree.h"

int node_destroy(void *ptr)
{
	cmd_t *cmd = ptr;

	free(cmd->str);
	free(cmd);
	return (EXIT_SUCCESS);
}
