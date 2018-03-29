/*
** EPITECH PROJECT, 2017
** File Name : bufferize.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

void bufferize(char *str)
{
	static char buffer[4096];
	static int index = 0;
	char *tmp = buffer;
	int len;

	if (!str) {
		my_putstr(buffer);
		return;
	}
	len = my_strlen(str);
	if (index + len > 4096) {
		my_putstr(buffer);
		index = 0;
	}
	index += my_strcpy(&tmp[index], str);
}
