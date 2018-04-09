/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"
#include "my.h"
#include "mysh.h"
#include "init.h"

int main(int ac, char **av)
{
	sh_t sh;
	int status;

	sh.rvalue = 0;
	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": The program must take one argument\n");
		return (84);
	}
	status = mysh(&sh);
	if (status == -1) {
		my_puterror("\nAn error occured\n");
		return (84);
	}
	return (sh.rvalue);
}

int print_node(btree_t *root)
{
	cmd_t *this = root->item;

	bufferize(this->str);
	bufferize("\n");
	return (0);
}

int main_old(int ac, char **av)
{
	if (ac != 2)
		return (84);
	exec(av[1]);
	return (0);
}

int exec(char *cmd)
{
	btree_t *root;
	cmd_t *this;

	btree_init(&root, cmd);
	if (root == NULL)
		return (-1);
	this = root->item;
	if (this->str != NULL)
		fork_and_exec(this->str);
	else
		btree_exec(root);
	if (this->pipefd[0] != 0)
		my_fdcpy(1, this->pipefd[0]);
	close(this->pipefd[0]);
	return (0);
}
