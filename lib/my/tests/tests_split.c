/*
** EPITECH PROJECT, 2017
** File Name : test_split.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include "my.h"

Test(split, get_next_word)
{
	char *got = "     lala	 toto      ";
	char *res;

	get_next_word(&got, " ");
	res = get_next_word(&got, " ");
	cr_assert_str_eq(res, "toto");
	res = get_next_word(&got, " ");
	cr_assert_eq(res, NULL);
}

Test(split, count_words)
{
	cr_assert_eq(count_words("un deux trois", " "), 3);
	cr_assert_eq(count_words("  un deux trois ", " "), 3);
}

Test(split, split)
{
	char *got = "   /bin/ls   -l  ";
	char *expected[3] = {"/bin/ls", "-l", NULL};
	char **res = split(got, " ");
	int i = 0;

	while (expected[i] != NULL) {
		cr_assert_str_eq(res[i], expected[i]);
		i++;
	}
	cr_assert_eq(res[i], expected[i]);
	cr_assert_str_eq(got, "   /bin/ls   -l  ");
}
