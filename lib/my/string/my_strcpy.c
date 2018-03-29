/*
** EPITECH PROJECT, 2017
** File Name : my_strcpy.c
** File description:
** Arthur Teisseire
*/

int my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
