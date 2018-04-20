/*
** EPITECH PROJECT, 2017
** File Name : tests_get_next_to.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(get_next_to, simple_test)
{
	char *str = "lalatotoPapa";
	char *flags = "toto";
	char *res = get_next_to(str, flags);

	cr_assert_str_eq(res, "Papa");
}

Test(get_next_to, without_match)
{
	char *str = "lalaPapa";
	char *flags = "toto";
	char *res = get_next_to(str, flags);

	cr_assert_eq(res, NULL);
}
