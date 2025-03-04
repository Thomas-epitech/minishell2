/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** get env as array
*/

#include <my.h>
#include <stdlib.h>

#include "env.h"

static char *get_formatted_env_var(const env_var_t *var)
{
    const int var_size = my_strlen(var->var) + my_strlen(var->value) + 2;
    char *formatted_var = malloc(sizeof(char) * var_size);

    if (formatted_var == 0)
        return NULL;
    for (int i = 0; i < var_size; i++)
        formatted_var[i] = '\0';
    my_strcat(formatted_var, var->var);
    my_strcat(formatted_var, "=");
    my_strcat(formatted_var, var->value);
    return formatted_var;
}

char **get_env_as_array(const environment_t *env)
{
    char **env_array;
    env_var_t *current;
    char *var;

    if (env == NULL || env->variables == NULL)
        return NULL;
    env_array = malloc(sizeof(char *) * (env->nb_var + 1));
    if (env_array == NULL)
        return NULL;
    current = *env->variables;
    for (int i = 0; current != NULL; i++) {
        var = get_formatted_env_var(current);
        if (var == NULL)
            return NULL;
        env_array[i] = var;
        current = current->next;
    }
    env_array[env->nb_var] = NULL;
    return env_array;
}
