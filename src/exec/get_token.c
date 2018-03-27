/*
** EPITECH PROJECT, 2017
** File Name : get_token.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "dict.h"

static const dicf_t tokens[NB_TOKENS] = {
	/*{";", exec_cmd},*/
	/*{"|", exec_pipe},*/
	/*{"<", exec_redir_left},*/
	/*{"<<", exec_redir2_left},*/
	/*{">", exec_redir_right},*/
	/*{">>", exec_redir2_right}*/
};

cmd_f get_token_func(char *token)
{
	for (int i = 0; i < NB_TOKENS; i++)
		if (my_strcmp(token, tokens[i].str) == 0)
			return (tokens[i].f);
	return (NULL);
}
