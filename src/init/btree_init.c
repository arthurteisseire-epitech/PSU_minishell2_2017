/*
** EPITECH PROJECT, 2017
** File Name : btree_init.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"
#include "my.h"
#include "mysh.h"
#include "init.h"
#include "dict.h"

static const dicf_t sep[NB_SEP] = {
	{";", semi_colons},
	{">>", redir2_right},
	{">", redir1_right},
	{"<", redir1_left},
	{"|", exec_pipe}
	/*{"<<", exec_redir2_left},*/
};

static int get_index(char *str)
{
	for (int i = 0; i < NB_SEP; i++)
		if (my_strstr(str, sep[i].str) != NULL)
			return (i);
	return (-1);
}

int btree_init(btree_t **root, char *str)
{
	cmd_t *this;
	cmd_t *cmd = new_cmd(my_strdup(str));

	if (cmd == NULL)
		return (-1);
	*root = btree_create_node(cmd);
	if (root == NULL)
		return (-1);
	this = (*root)->item;
	this->pipefd[0] = 0;
	if (btree_apply_last(*root, btree_fill) == -1)
		return (-1);
	return (0);
}

int btree_fill(btree_t *root)
{
	cmd_t *this = root->item;
	int i = get_index(this->str);

	if (i != -1) {
		root->left = btree_new_node(this, i, get_before_to);
		if (root->left == NULL)
			return (-1);
		root->right = btree_new_node(this, i, get_next_to);
		if (root->right == NULL)
			return (-1);
		this->exec = sep[i].f;
		free_and_set((void **)&this->str, NULL, free);
		return (0);
	}
	return (1);
}

btree_t *btree_new_node(cmd_t *cmd, int index, char *(get)())
{
	cmd_t *new = new_cmd(get(cmd->str, sep[index].str));

	my_strip(&new->str, " \t");
	if (new == NULL)
		return (NULL);
	if (new->str != NULL && my_strcmp(new->str, "") == 0) {
		//free_and_set((void **)&new->str, NULL, free);
		//new->str = NULL;
	}
	return (btree_create_node(new));
}

cmd_t *new_cmd(char *str)
{
	cmd_t *cmd = malloc(sizeof(cmd_t));
	if (cmd == NULL)
		return (NULL);
	cmd->str = str;
	cmd->array = NULL;
	cmd->exec = NULL;
	return (cmd);
}
