/*
** EPITECH PROJECT, 2017
** File Name : tests_strcat.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_strcat, simple_test)
{
	char str[20] = "Hello";

	my_strcat(str, " world!\n");
	cr_assert_str_eq(str, "Hello world!\n");
}

Test(my_strncat, simple_test)
{
	char str[20] = "Hello";

	my_strncat(str, " world!\n", 3);
	cr_assert_str_eq(str, "Hello wo");
}
