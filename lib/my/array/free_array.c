/*
** EPITECH PROJECT, 2017
** File Name : free_2d.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>

void free_array(char **array)
{
	int i = 0;

	while (array[i]) {
		free(array[i]);
		i++;
	}
	free(array);
}
