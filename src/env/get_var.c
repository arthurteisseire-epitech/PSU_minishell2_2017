/*
** EPITECH PROJECT, 2017
** File Name : get_var.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "env.h"

char *get_name(char *var)
{
	int i = 0;
	char *name;

	while (var[i] != '=' && var[i] != '\0')
		i++;
	name = my_strndup(var, i);
	if (name == NULL)
		return (NULL);
	return (name);
}

char *get_value(char *name)
{
	int i = 0;
	char *var;
	int index = index_name(name);

	if (index == -1)
		return (NULL);
	while (environ[index][i] != '=')
		i++;
	i++;
	var = my_strdup(&environ[index][i]);
	return (var);
}
