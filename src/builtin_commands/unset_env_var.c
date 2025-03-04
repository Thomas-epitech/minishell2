/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** set env var
*/

#include <stdlib.h>

#include "env.h"
#include "history.h"
#include "my.h"

int unset_env_var(char **command, const int nb_args, environment_t *envp,
    const history_t *history)
{
    if (command == NULL || nb_args == 0 || envp == NULL || history == NULL)
        return EXIT_FAILURE;
    if (nb_args < 2) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return EXIT_FAILURE;
    }
    for (int i = 1; i < nb_args; i++)
        delete_env_var(envp, command[i]);
    return 0;
}
