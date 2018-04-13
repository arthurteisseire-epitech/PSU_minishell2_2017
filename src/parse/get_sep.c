/*
** EPITECH PROJECT, 2017
** File Name : get_sep.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "parse.h"

const dicf_t sep[NB_SEP] = {
	{";", semi_colons, 0},
	{">>", redir2_right, 0b00000001},
	{">", redir1_right, 0b00000001},
	{"|", exec_pipe, 0b00000001},
	{"<<", redir2_left, 0b00000010},
	{"<", redir1_left, 0b00000010}
};

int get_index(char *str)
{
	for (int i = 0; i < NB_SEP; i++)
		if (my_strstr(str, sep[i].str) != NULL)
			return (i);
	return (-1);
}

