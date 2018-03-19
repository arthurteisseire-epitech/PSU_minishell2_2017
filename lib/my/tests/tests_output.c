/*
** EPITECH PROJECT, 2017
** File Name : tests_output.c
** File description:
** By Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void);

Test(my_putchar, simple_test, .init = redirect_all_std)
{
	my_putchar('l');
	cr_assert_stdout_eq_str("l");
}

Test(my_putstr, simple_test, .init = redirect_all_std)
{
	char *str = "fezfez";

	my_putstr(str);
	cr_assert_stdout_eq_str(str);
}

Test(my_puterror, simple_test, .init = redirect_all_std)
{
	char *str = "zaoihzaifn";

	my_puterror(str);
	cr_assert_stderr_eq_str(str);
}

Test(my_put_nbr, simple_test, .init = redirect_all_std)
{
	my_put_nbr(986096);
	cr_assert_stdout_eq_str("986096");
}
