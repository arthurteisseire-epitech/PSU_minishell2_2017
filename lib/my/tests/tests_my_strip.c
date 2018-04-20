/*
** EPITECH PROJECT, 2017
** File Name : tests_my_strip.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_strip, simple_test)
{
	char *s = my_strdup("lllllllaaaaaatotolllllllaaaaaa");

	my_strip(&s, "la");
	cr_assert_str_eq(s, "toto");
}

Test(my_strip, null_case)
{
	char *s = NULL;

	my_strip(&s, " ");
	cr_assert(s == NULL);
	my_strip(NULL, " ");
}
