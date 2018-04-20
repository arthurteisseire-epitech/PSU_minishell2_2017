/*
** EPITECH PROJECT, 2017
** File Name : tests_level_count.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "btree.h"

Test(level_count, simple_test)
{
	btree_t *root = btree_create_node("0");

	root->left = btree_create_node("1");
	root->right = btree_create_node("2");
	root->right->right = btree_create_node("3");
	cr_assert(btree_level_count(root) == 3);
}

Test(level_count, advanced_test)
{
	btree_t *root = btree_create_node("0");

	root->left = btree_create_node("1");
	root->left->left = btree_create_node("1");
	root->left->right = btree_create_node("1");
	root->right = btree_create_node("2");
	root->right->right = btree_create_node("3");
	root->right->right->right = btree_create_node("3");
	cr_assert(btree_level_count(root) == 4);
}
