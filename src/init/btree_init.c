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
	{";", exec_cmd},
	{">>", redir2_right},
	{">", redir1_right},
	{"<", redir1_left},
	{"|", execout_to_pipe}
	/*{"<<", exec_redir2_left},*/
};

static int get_index(char *str)
{
	for (int i = 0; i < NB_SEP; i++)
		if (my_strstr(str, sep[i].str) != NULL)
			return (i);
	return (-1);
}

int init_tree(btree_t **root, char *str)
{
	cmd_t *cmd = new_cmd(my_strdup(str));

	if (cmd == NULL)
		return (-1);
	*root = btree_create_node(cmd);
	if (root == NULL)
		return (-1);
	if (btree_apply_last(*root, fill_tree) == -1)
		return (-1);
	return (0);
}

int fill_tree(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *new;
	int i = get_index(this->str);

	if (i != -1) {
		new = new_cmd(get_before_to(this->str, sep[i].str));
		my_strip(&new->str, " \t");
		root->left = btree_create_node(new);
		if (new == NULL || root->left == NULL)
			return (-1);
		new = new_cmd(get_next_to(this->str, sep[i].str));
		my_strip(&new->str, " \t");
		root->right = btree_create_node(new);
		if (new == NULL || root->right == NULL)
			return (-1);
		this->exec = sep[i].f;
		free_and_set((void **)&this->str, NULL, free);
		return (0);
	}
	return (1);
}
