/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** check for built-in commands
*/

#include <stdlib.h>

#include "builtin_commands.h"
#include "env.h"
#include "my.h"

static int get_nb_args(char **formatted_command)
{
    int count = 0;

    for (int i = 0; formatted_command[i] != NULL; i++)
        count++;
    return count;
}

int check_for_builtin_commands(char **formatted_command,
    environment_t *envp, history_t *history)
{
    int nb_args;

    if (formatted_command == NULL || envp == NULL)
        return -1;
    nb_args = get_nb_args(formatted_command);
    for (int i = 0; i < NB_BUILTIN_COMMANDS; i++) {
        if (my_strcmp(formatted_command[0],
            builtin_commands[i].command) == 0) {
            return builtin_commands[i]. associated_function(formatted_command,
                nb_args, envp, history);
        }
    }
    return -1;
}
