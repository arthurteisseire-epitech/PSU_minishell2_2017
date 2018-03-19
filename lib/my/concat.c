/*
** EPITECH PROJECT, 2017
** File Name : concat.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char *concat(char *dest, char *src, int len_src)
{
	int len_dest = my_strlen(dest);
	char *res = malloc(sizeof(char) * (len_dest + len_src + 1));
	int i = 0;

	if (res == NULL)
		return (NULL);
	if (dest != NULL) {
		while (dest[i] != '\0') {
			res[i] = dest[i];
			i++;
		}
		free(dest);
	}
	i = 0;
	while (i < len_src) {
		res[len_dest + i] = src[i];
		i++;
	}
	res[len_dest + i] = '\0';
	return (res);
}
