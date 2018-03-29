/*
** EPITECH PROJECT, 2017
** File Name : rm_arrelem.c
** File description:
** by Arthur Teisseire
*/

void rm_arrelem(void **array, int index, void (*free_fun)(void *ptr))
{
	void *to_free = array[index];

	while (array[index]) {
		array[index] = array[index + 1];
		index++;
	}
	if (free_fun)
		free_fun(to_free);
}
