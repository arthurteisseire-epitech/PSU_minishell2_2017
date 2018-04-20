/*
** EPITECH PROJECT, 2017
** File Name : tests_my_strstr.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_strstr, simple_test)
{
	char const *haystack = "lalalalala Hello World!";
	char const *needle = "Hello";

	cr_assert_str_eq(my_strstr(haystack, needle), "Hello World!");
}

Test(my_strstr, null_test)
{
	char const *haystack = "lalalalala Hello World!";
	char const *needle = "Hellooooooooooooo";

	cr_assert_eq(my_strstr(haystack, needle), NULL);
}
