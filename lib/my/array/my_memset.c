/*
** EPITECH PROJECT, 2017
** File Name : my_memset.c
** File description:
** by Arthur Teisseire
*/

void *my_memset(void *s, char b, int n)
{
	int i = 0;
	char *ptr = s;

	while (i < n) {
		ptr[i] = b;
		i++;
	}
	return (s);
}
