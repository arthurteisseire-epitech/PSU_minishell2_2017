/*
** EPITECH PROJECT, 2017
** File Name : array_to_str.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char *array_to_str(char **array, char *between)
{
	int i = 1;
	int len_between = my_strlen(between);
	char *res;

	if (array[0] == NULL)
		return (NULL);
	res = my_strdup(array[0]);
	if (res == NULL)
		return (NULL);
	while (array[i] != NULL) {
		res = concat(res, between, len_between);
		res = concat(res, array[i], my_strlen(array[i]));
		if (res == NULL)
			return (NULL);
		i++;
	}
	return (res);
}
