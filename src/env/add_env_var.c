/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** add env var
*/


#include <stdlib.h>

#include "env.h"
#include "my.h"

static env_var_t *create_new_var(const char *var, const char *value)
{
    env_var_t *new_var = malloc(sizeof(env_var_t));

    if (new_var == NULL)
        return NULL;
    new_var->var = my_strdup(var);
    new_var->value = my_strdup(value);
    new_var->next = NULL;
    return new_var;
}

void add_env_var(environment_t *environment, const char *var,
    const char *value)
{
    env_var_t *current;

    if (environment == NULL || var == NULL || value == NULL)
        return;
    current = *environment->variables;
    if (current == NULL) {
        *environment->variables = create_new_var(var, value);
        environment->nb_var++;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = create_new_var(var, value);
    environment->nb_var++;
}
