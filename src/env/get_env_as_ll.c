/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** get env as linked list
*/

#include <stdlib.h>
#include <string.h>

#include "my.h"
#include "env.h"

environment_t *get_env_as_ll(char **envp)
{
    environment_t *env = create_env();
    char *tmp = NULL;
    const char *var = NULL;
    const char *val = NULL;

    if (envp == NULL || env == NULL)
        return NULL;
    for (int i = 0; envp[i] != NULL; i++) {
        tmp = my_strdup(envp[i]);
        if (tmp == NULL) {
            free_env(env);
            return NULL;
        }
        var = strtok(tmp, "=");
        val = strtok(NULL, "\n");
        add_env_var(env, var, val);
        free(tmp);
    }
    return env;
}
