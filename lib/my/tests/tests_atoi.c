/*
** EPITECH PROJECT, 2017
** File Name : tests_atoi.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(nb_len, simple_test)
{
	cr_assert(nb_len(67654) == 5);
	cr_assert(nb_len(-67654) == 5);
	cr_assert(nb_len(0) == 1);
}

Test(my_atoi, simple_test)
{
	cr_assert(my_atoi("67654") == 67654);
	cr_assert(my_atoi("-67654") == -67654);
	cr_assert(my_atoi("-0") == 0);
}

Test(my_itoa, simple_test)
{
	cr_assert(my_itoa(67654), "67654");
	cr_assert(my_itoa(-67654), "-67654");
	cr_assert_str_eq(my_itoa(0), "0");
}
