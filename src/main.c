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

void sighandler(int __attribute((unused))sig)
{
	my_putchar('\n');
	my_putstr("$> ");
}

int main(int ac, char **av)
{
	int status;

	signal(SIGINT, sighandler);
	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": The program must take one argument\n");
		return (84);
	}
	status = run();
	return (status % 256);
}
