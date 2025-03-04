/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** get binary
*/

#include <execution.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "env.h"
#include "my.h"

char *get_expected_path(const char *path_var, const char *command)
{
    char *path = malloc(sizeof(char) *
        (my_strlen(path_var) + my_strlen(command) + 2));

    if (path == NULL)
        return NULL;
    my_strcpy(path, path_var);
    my_strcat(path, "/");
    my_strcat(path, command);
    return path;
}

char *parse_path(char *path, char *command)
{
    char *token = strtok(path, ":");
    char *expected_path;

    while (token != NULL) {
        expected_path = get_expected_path(token, command);
        if (expected_path == NULL)
            return NULL;
        if (access(expected_path, F_OK) == 0)
            return expected_path;
        free(expected_path);
        token = strtok(NULL, ":");
    }
    return NULL;
}

char *get_binary(char *command, const environment_t *envp)
{
    const env_var_t *path_var = get_env_var(envp, PATH_ENV_VAR);
    char *path_value;
    char *binary_path;

    if (path_var == NULL)
        return NULL;
    path_value = my_strdup(path_var->value);
    binary_path = parse_path(path_value, command);
    free(path_value);
    return binary_path;
}
