/*
** EPITECH PROJECT, 2017
** File Name : right_redir.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include "my.h"
#include "mysh.h"

int redir1_right(cmd_t *cmd)
{
	char **array = split(cmd->array[0], "");

	if (array == NULL)
		return (-1);
	execout_to_pipe(cmd, array);
	write_in_file(cmd->array[1], cmd->pipefd[0], O_TRUNC);
	return (0);
}

int redir2_right(cmd_t *cmd)
{
	char **array = split(cmd->array[0], "");

	if (array == NULL)
		return (-1);
	execout_to_pipe(cmd, array);
	write_in_file(cmd->array[1], cmd->pipefd[0], O_APPEND);
	return (0);
}

int redir1_left(cmd_t *cmd)
{
	int fd = open(cmd->array[1], O_RDONLY);

	if (fd < 0)
		return (fd);
	my_fdcpy(cmd->pipefd[1], fd);
	return (0);
}
