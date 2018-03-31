/*
** EPITECH PROJECT, 2017
** File Name : remove_var.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "env.h"

int remove_var(char **args)
{
	int index = index_name(args[0], environ);

	rm_arrelem((void *)environ, index, NULL);
	return (0);
}
