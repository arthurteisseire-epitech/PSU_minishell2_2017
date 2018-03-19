/*
** EPITECH PROJECT, 2017
** File Name : add_var.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "env.h"

int add_var(char **args)
{
	int i = 0;

	while (environ[i] != NULL)
		i++;
	environ[i] = concat_args(args);
	if (environ[i] == NULL)
		return (-1);
	environ[i + 1] = NULL;
	return (0);
}
