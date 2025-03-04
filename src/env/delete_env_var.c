/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** delete env var
*/

#include <stdlib.h>

#include "my.h"
#include "env.h"

static void free_next_var(env_var_t *env_var)
{
    env_var_t *tmp;

    if (env_var == NULL || env_var->next == NULL)
        return;
    tmp = env_var->next;
    env_var->next = tmp->next;
    free_env_var(tmp);
}

void delete_env_var(environment_t *environment, const char *var)
{
    env_var_t *current;

    if (environment == NULL || var == NULL)
        return;
    current = *environment->variables;
    if (current == NULL)
        return;
    if (my_strcmp(current->var, var) == 0) {
        *environment->variables = current->next;
        free_env_var(current);
    }
    while (current->next != NULL) {
        if (my_strcmp(current->next->var, var) == 0) {
            free_next_var(current);
            environment->nb_var--;
            break;
        }
        current = current->next;
    }
}
