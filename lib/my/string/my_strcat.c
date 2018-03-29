/*
** EPITECH PROJECT, 2017
** File Name : my_strcat.c
** File description:
** By Arthur Teisseire
*/

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0') {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
