/*
** EPITECH PROJECT, 2017
** File Name : my_arrcpy.h
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char **my_arrcpy(char const **array)
{
	int i = my_arrlen((void **)array);
	char **new_array = malloc(sizeof(char *) * (i + 1));
	
	for (int j = 0; j < i; j++)
		new_array[j] = my_strdup(array[j]);
	new_array[i] = NULL;
	return (new_array);
}
