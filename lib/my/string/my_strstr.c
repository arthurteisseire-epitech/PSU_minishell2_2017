/*
** EPITECH PROJECT, 2017
** File Name : my_strstr.c
** File description:
** by Arthur Teisseire
*/

#include <stddef.h>
#include "my.h"

char *my_strstr(char const *haystack, char const *needle)
{
	char *ptr = (char *)haystack;
	int needle_len = my_strlen(needle);

	while (*ptr != '\0') {
		if (my_strncmp(ptr, needle, needle_len) == 0)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
