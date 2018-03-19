/*
** EPITECH PROJECT, 2017
** File Name : test_cpy.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_strcpy, simple_test)
{
	char *expected = "ezfheofnea";
	char str[18];

	my_strcpy(str, expected);
	cr_assert_str_eq(str, expected);
}

Test(my_strncpy, simple_test)
{
	char *expected = "ezfheofnea";
	char str[18];

	my_strncpy(str, expected, 700);
	cr_assert_str_eq(str, expected);
	my_strncpy(str, expected, 4);
	cr_assert_str_eq(str, "ezfh");
}
