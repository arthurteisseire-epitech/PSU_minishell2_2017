/*
** EPITECH PROJECT, 2017
** File Name : index_name.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "env.h"

int index_name(char *var_name)
{
	int i = 0;
	char *env_name;

	while (environ[i] != NULL) {
		env_name = get_name(environ[i]);
		if (env_name == NULL)
			return (-1);
		if (my_strcmp(env_name, var_name) == 0) {
			free(env_name);
			return (i);
		}
		free(env_name);
		i++;
	}
	return (-1);
}
