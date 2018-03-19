/*
** EPITECH PROJECT, 2017
** File Name : my_strncpy.c
** File description:
** Arthur Teisseire
*/

char *my_strncpy(char *dest, char const *src, int const n)
{
	int i = 0;

	while (i < n && src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
