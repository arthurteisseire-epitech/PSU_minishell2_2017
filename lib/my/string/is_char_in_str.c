/*
** EPITECH PROJECT, 2017
** File Name : is_char_in_str.c
** File description:
** by Arthur Teisseire
*/

int is_char_in_str(char const c, char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
