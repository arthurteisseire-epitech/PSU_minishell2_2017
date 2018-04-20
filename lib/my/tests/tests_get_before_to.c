/*
** EPITECH PROJECT, 2017
** File Name : tests_get_before_to.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(before_to, simple_test)
{
	char *str = "lalatotoPapa";
	char *flags = "toto";
	char *res = get_before_to(str, flags);

	cr_assert_str_eq(res, "lala");
}

Test(get_before_to, advanced_test)
{
	char *str = "1 < 2 < 3 << 4";
	char *flags = "<<";
	char *res = get_before_to(str, flags);

	cr_assert_str_eq(res, "1 < 2 < 3 ");
}

Test(get_before_to, without_match)
{
	char *str = "lalaPapa";
	char *flags = "toto";
	char *res = get_before_to(str, flags);

	cr_assert_str_eq(res, str);
}

Test(get_to, special_cases)
{
	char *str = "totolalaPapatoto";
	char *flags = "toto";
	char *res = get_before_to(str, flags);

	cr_assert_str_eq(res, "");
}
