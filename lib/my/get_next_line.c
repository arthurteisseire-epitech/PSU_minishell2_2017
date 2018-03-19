/*
** EPITECH PROJECT, 2017
** File Name : get_next_line.c
** File description:
** by Arthur Teisseire
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static int find_backspace(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char *cut_line(char **begin, char *line, int index_bn)
{
	char *res;

	line = concat(line, *begin, index_bn);
	res = concat(NULL, line, my_strlen(line));
	*begin += index_bn + 1;
	free(line);
	return (res);
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE];
	static char *begin = buffer;
	char *line = NULL;
	int index;
	int size;

	if ((index = find_backspace(begin)) != -1)
		return (cut_line(&begin, line, index));
	line = concat(line, begin, my_strlen(begin));
	while ((size = read(fd, buffer, READ_SIZE)) > 0) {
		buffer[size] = '\0';
		begin = buffer;
		if ((index = find_backspace(begin)) != -1)
			return (cut_line(&begin, line, index));
		else if (my_strlen(begin) != 0)
			return (cut_line(&begin, line, my_strlen(begin)));
		line = concat(line, begin, my_strlen(begin));
	}
	free(line);
	return (NULL);
}
