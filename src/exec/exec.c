/*
** EPITECH PROJECT, 2017
** File Name : exec.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "btree.h"
#include "init.h"

int exec(char *cmd)
{
	btree_t *root;
	cmd_t *this;
	int status = 0;

	status = btree_init(&root, cmd);
	if (status != 0)
		return (status);
	this = root->item;
	if (this->str != NULL) {
		if (my_strcmp(this->str, ""))
			fork_and_exec(this->str);
	} else {
		status = btree_exec(root);
	}
	if (this->pipefd[0] != 0)
		my_fdcpy(1, this->pipefd[0]);
	return (status);
}
