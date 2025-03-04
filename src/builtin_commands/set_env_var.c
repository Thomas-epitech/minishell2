/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** set env var
*/

#include <stdlib.h>

#include "builtin_commands.h"
#include "env.h"
#include "my.h"

static int add_var(environment_t *envp, const char *var, const char *value)
{
    env_var_t *target_var = get_env_var(envp, var);

    if (!check_env_var_syntax(var))
        return EXIT_FAILURE;
    if (target_var == NULL) {
        add_env_var(envp, var, value == NULL ? "" : value);
        return 0;
    }
    free(target_var->value);
    target_var->value = my_strdup(value == NULL ? "" : value);
    return 0;
}

int set_env_var(char **command, const int nb_args, environment_t *envp,
    history_t *history)
{
    if (command == NULL || envp == NULL || nb_args == 0 || history == NULL)
        return EXIT_FAILURE;
    if (nb_args == 1) {
        display_env(command, nb_args, envp, history);
        return 0;
    }
    if (nb_args > 3) {
        my_putstr_error("setenv: Too many arguments.\n");
        return EXIT_FAILURE;
    }
    return add_var(envp, command[1], nb_args > 2 ? command[2] : NULL);
}
