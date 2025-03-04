/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** check env var syntax
*/

#include <stdbool.h>
#include <stddef.h>

#include "my.h"

static bool is_valid_env_char(const char c)
{
    return is_letter(c) || is_digit(c) || c == '_' || c == '.';
}

bool check_env_var_syntax(const char *var)
{
    if (var == NULL)
        return false;
    if (!is_letter(var[0]) && var[0] != '_') {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return false;
    }
    for (int i = 0; var[i] != '\0'; i++) {
        if (!is_valid_env_char(var[i])) {
            my_putstr_error("setenv: Variable name must contain alphanumeric "
                "characters.\n");
            return false;
        }
    }
    return true;
}
