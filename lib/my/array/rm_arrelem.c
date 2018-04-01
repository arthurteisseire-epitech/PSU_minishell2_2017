/*
** EPITECH PROJECT, 2017
** File Name : rm_arrelem.c
** File description:
** by Arthur Teisseire
*/

void rm_arrelem(void **array, int index, void (*free_func)(void *ptr))
{
	void *to_free = array[index];

	while (array[index]) {
		array[index] = array[index + 1];
		index++;
	}
	if (free_func)
		free_func(to_free);
}
