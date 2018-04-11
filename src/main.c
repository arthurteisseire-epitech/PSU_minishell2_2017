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
	int status;

	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": The program must take one argument\n");
		return (84);
	}
	status = run();
	if (status == -1) {
		my_puterror("\nAn error occured\n");
		return (84);
	}
	return (status);
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
