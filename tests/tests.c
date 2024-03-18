/*
** EPITECH PROJECT, 2023
** test
** File description:
** tstvnkr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/project.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test("bin_name", it_displays_velocity, .init = redirect_all_std)
{
}

Test("bin_name", "test_name", .init = redirect_all_std)
{
}
