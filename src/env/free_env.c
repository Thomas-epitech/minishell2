/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** free env
*/

#include <stdlib.h>

#include "env.h"

static void free_variables(env_var_t *variable)
{
    if (variable->next != NULL)
        free_variables(variable->next);
    free_env_var(variable);
}

void free_env(environment_t *env)
{
    if (env == NULL || env->variables == NULL)
        return;
    if (*env->variables != NULL)
        free_variables(*env->variables);
    free(env->variables);
    free(env);
}
