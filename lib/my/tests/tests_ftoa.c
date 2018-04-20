/*
** EPITECH PROJECT, 2017
** File Name : tests_atoi.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_ftoa, get_decimal)
{
	cr_assert_eq(get_decimal(1.2, 1), 2);
	cr_assert_eq(get_decimal(6765.56, 2), 56);
}

Test(my_ftoa, positive)
{
	cr_assert_str_eq(my_ftoa(1.2, 1), "1.2");
	cr_assert_str_eq(my_ftoa(6765.56, 2), "6765.56");
}

Test(my_ftoa, negative)
{
	cr_assert_str_eq(my_ftoa(-1.2, 1), "-1.2");
	cr_assert_str_eq(my_ftoa(-6765.56, 2), "-6765.56");
}
