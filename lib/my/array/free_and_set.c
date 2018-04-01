/*
** EPITECH PROJECT, 2017
** File Name : free_and_set.c
** File description:
** by Arthur Teisseire
*/

void free_and_set(void **ptr, void *new_ptr, void (*free_func)(void *))
{
	void *to_free = *ptr;

	*ptr = new_ptr;
	free_func(to_free);
}
