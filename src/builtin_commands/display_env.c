/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** display env
*/

#include <stdlib.h>

#include "env.h"
#include "history.h"
#include "my.h"

int display_env(char **command, const int nb_args, const environment_t *envp,
    const history_t *history)
{
    const env_var_t *current;

    if (command == NULL || nb_args == 0 || envp == NULL || history == NULL)
        return EXIT_FAILURE;
    current = *envp->variables;
    while (current != NULL) {
        mini_printf("%s=%s\n", current->var, current->value);
        current = current->next;
    }
    return 0;
}
