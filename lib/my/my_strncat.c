/*
** EPITECH PROJECT, 2017
** File Name : my_strncat.c
** File description:
** by Arthur Teisseire
*/

char *my_strncat(char *dest, char const *src, int const n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (j < n && src[j] != '\0') {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
