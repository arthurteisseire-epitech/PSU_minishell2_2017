/*
** EPITECH PROJECT, 2017
** File Name : free_and_set.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>

void free_and_set(void **ptr, void *new_ptr)
{
	void *to_free = *ptr;

	*ptr = new_ptr;
	free(to_free);
}
