/*
** EPITECH PROJECT, 2017
** File Name : tools.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>

int skip_first_flags(char **str, char *flags);
char **split(char *str, char *flags);
char *get_next_word(char **str, char *flags);
int len_first_word(char *str, char *flags);
int count_words(char *str, char *flags);
int in_str(char c, char *str);
char *my_strncpy(char *dest, char const *src, int n);

#endif
