/*
** EPITECH PROJECT, 2017
** File Name : concat.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char *concat(char *left, char *right, int len_right)
{
	int len_left = my_strlen(left);
	char *res = malloc(sizeof(char) * (len_left + len_right + 1));

	if (res == NULL)
		return (NULL);
	if (left != NULL)
		my_strcpy(res, left);
	free(left);
	if (right != NULL)
		my_memcpy(&res[len_left], right, len_right);
	res[len_left + len_right] = '\0';
	return (res);
}
