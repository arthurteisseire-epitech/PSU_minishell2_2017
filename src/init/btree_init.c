/*
** EPITECH PROJECT, 2017
** File Name : btree_init.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "btree.h"
#include "my.h"
#include "mysh.h"
#include "init.h"
#include "parse.h"

int btree_init(btree_t **root, char *str)
{
	cmd_t *cmd = new_cmd(my_strdup(str));

	if (cmd == NULL)
		return (EXIT_FAILURE);
	*root = btree_create_node(cmd);
	if (root == NULL)
		return (EXIT_FAILURE);
	if (btree_apply_last(*root, btree_fill) == -1)
		return (EXIT_FAILURE);
	return (0);
}

int btree_fill(btree_t *root)
{
	cmd_t *this = root->item;
	int i = get_index(this->str);

	if (i != -1) {
		root->left = btree_new_node(this, i, get_before_to);
		root->right = btree_new_node(this, i, get_next_to);
		this->exec = sep[i].f;
		free_and_set((void **)&this->str, NULL, free);
		return (0);
	}
	return (2);
}

btree_t *btree_new_node(cmd_t *cmd, int index, char *(get)())
{
	cmd_t *new = new_cmd(get(cmd->str, sep[index].str));

	my_strip(&new->str, " \t");
	if (new == NULL)
		return (NULL);
	if (my_strcmp(new->str, "") == 0)
		return (free(new->str), NULL);
	return (btree_create_node(new));
}

cmd_t *new_cmd(char *str)
{
	cmd_t *cmd = malloc(sizeof(cmd_t));

	if (cmd == NULL)
		return (NULL);
	cmd->str = str;
	cmd->exec = NULL;
	return (cmd);
}
