/*
** EPITECH PROJECT, 2017
** File Name : prompt.c
** File description:
** by Arthur Teisseire
*/

#include <unistd.h>
#include <sys/stat.h>
#include "my.h"

void print_prompt(void)
{
	char pwd[READ_SIZE];
	char *curr_dir = pwd;
	char *tmp = NULL;

	getcwd(pwd, READ_SIZE);
	tmp = my_strstr(pwd, "/");
	while (tmp != NULL) {
		tmp++;
		curr_dir = tmp;
		tmp = my_strstr(tmp, "/");
	}
	bufferize("[");
	bufferize(curr_dir);
	bufferize("]$ ");
	bufferize(NULL);
}
