/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** get env var
*/

#include <stddef.h>

#include "env.h"
#include "my.h"

env_var_t *get_env_var(const environment_t *env, const char *name)
{
    env_var_t *current;

    if (env == NULL || name == NULL)
        return NULL;
    current = *env->variables;
    while (current != NULL) {
        if (my_strcmp(name, current->var) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}
