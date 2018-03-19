/*
** EPITECH PROJECT, 2017
** File Name : tests_base.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void);

Test(my_putnbr_base, binary, .init = redirect_all_std)
{
	my_putnbr_base(57, "01");
	cr_assert_stdout_eq_str("111001");
}

Test(my_putnbr_base, octal, .init = redirect_all_std)
{
	my_putnbr_base(57, "01234567");
	cr_assert_stdout_eq_str("71");
}

Test(my_putnbr_base, hexa, .init = redirect_all_std)
{
	my_putnbr_base(576789, "0123456789ABCDEF");
	cr_assert_stdout_eq_str("8CD15");
}
