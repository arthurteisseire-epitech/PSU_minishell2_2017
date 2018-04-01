/*
** EPITECH PROJECT, 2017
** File Name : init_cmd.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

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
