/*
** EPITECH PROJECT, 2017
** File Name : tests_strcmp.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_strcmp, simple_test)
{
	cr_assert(my_strcmp("Hello __ lala", "Hello __ lala") == 0);
	cr_assert(my_strcmp("Hello __ lala", "He_ lala") != 0);
	cr_assert(my_strcmp("", "") == 0);
}

Test(my_strncmp, simple_test)
{
	cr_assert(my_strncmp("Hello __ lala", "Hello __ lala", 90) == 0);
	cr_assert(my_strncmp("Hello __ lala", "He_ lala", 2) == 0);
	cr_assert(my_strncmp("Hello __ lala", "He_ lala", 9) != 0);
	cr_assert(my_strncmp("", "", 3) == 0);
}

Test(my_str_isaplhanum, simple_test)
{
	cr_assert(my_str_isalphanum("fieohpfiuhoifezfpq654328832") == 1);
	cr_assert(my_str_isalphanum("fieohpfiuhoife:zfpq654328832") == 0);
}

Test(my_strlen, simple_test)
{
	cr_assert(my_strlen("") == 0);
	cr_assert(my_strlen("123456789") == 9);
}
