/*
** EPITECH PROJECT, 2017
** File Name : parse_ambiguous.c
** File description:
** by Arthur Teisseire
*/

#include <stddef.h>
#include "mysh.h"
#include "my.h"
#include "parse.h"

static int ambigous_err(char *io)
{
	bufferize("Ambiguous ");
	bufferize(io);
	bufferize(" redirect.\n");
	bufferize(NULL);
	return (1);
}

int parse_ambigous(char *str)
{
	unsigned char byte = 0;
	int i = get_index(str);

	while (i != -1) {
		if ((byte & sep[i].byte) != 0)
			return (ambigous_err(sep[i].byte == 0b00000010 ?
				"input" : "output"));
		byte |= (my_strcmp(sep[i].str, "|") == 0 ?
			0b00000010 : sep[i].byte);
		str = my_strstr(str, sep[i].str);
		str += my_strlen(sep[i].str);
		i = get_index(str);
	}
	return (0);
}
