/*
** EPITECH PROJECT, 2017
** File Name : split.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char **split(char *str, char const *flags)
{
	int nb_words = count_words(str, flags);
	char **res = malloc(sizeof(char *) * (nb_words + 1));
	int i = 0;

	res[nb_words] = NULL;
	while (i < nb_words) {
		res[i] = get_next_word(&str, flags);
		i++;
	}
	return (res);
}

char *get_next_word(char **str, char const *flags)
{
	int len_word;
	char *word;

	while (is_char_in_str(**str, flags))
		(*str)++;
	len_word = len_first_word(*str, flags);
	word = malloc(sizeof(char) * (len_word + 1));
	if (word == NULL || len_word == 0)
		return (NULL);
	word[len_word] = '\0';
	my_strncpy(word, *str, len_word);
	(*str) += len_word;
	return (word);
}

int count_words(char *str, char const *flags)
{
	int nb_words = 0;

	while (*str != '\0') {
		while (is_char_in_str(*str, flags))
			str++;
		if (*str != '\0')
			nb_words++;
		while (*str != '\0' && !is_char_in_str(*str, flags))
			str++;
	}
	return (nb_words);
}

int len_first_word(char *str, char const *flags)
{
	int i = 0;

	while (str[i] != '\0' && !is_char_in_str(str[i], flags))
		i++;
	return (i);
}

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
