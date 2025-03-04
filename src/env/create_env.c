/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** create env
*/

#include <stdlib.h>

#include "env.h"

environment_t *create_env(void)
{
    environment_t *environment = malloc(sizeof(environment_t));

    if (environment == NULL)
        return NULL;
    environment->nb_var = 0;
    environment->variables = malloc(sizeof(env_var_t *));
    if (environment->variables == NULL) {
        free(environment);
        return NULL;
    }
    *environment->variables = NULL;
    return environment;
}
