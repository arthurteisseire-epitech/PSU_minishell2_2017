/*
** EPITECH PROJECT, 2017
** File Name : my_memcpy.c
** File description:
** by Arthur Teisseire
*/

void *my_memcpy(void *dest, void *src, int size)
{
	const char *src_ptr = src;
	char *dest_ptr = dest;

	for (int i = 0; i < size; i++)
		dest_ptr[i] = src_ptr[i];
	return (src);
}
