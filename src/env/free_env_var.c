/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** free env var
*/

#include <stdlib.h>

#include "env.h"

void free_env_var(env_var_t *env_var)
{
    free(env_var->var);
    free(env_var->value);
    free(env_var);
}
