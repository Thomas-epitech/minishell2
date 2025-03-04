/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** built-in commands header
*/

#ifndef BUILTIN_COMMANDS_H
    #define BUILTIN_COMMANDS_H

    #define NB_BUILTIN_COMMANDS 5

    #define MAX_PATH_LENGTH 4096

    #include "env.h"
    #include "history.h"
int my_cd(char **command, int nb_args, environment_t *envp,
    history_t *history);
int display_env(char **command, int nb_args, environment_t *envp,
    history_t *history);
int set_env_var(char **command, int nb_args, environment_t *envp,
    history_t *history);
int unset_env_var(char **command, int nb_args, environment_t *envp,
    history_t *history);

typedef struct {
    char *command;
    int (*associated_function)(char **command, int nb_args,
        environment_t *envp, history_t *history);
} builtin_command_t;

static const builtin_command_t builtin_commands[] = {
    {"cd", &my_cd},
    {"env", &display_env},
    {"setenv", &set_env_var},
    {"unsetenv", &unset_env_var},
    {"history", &print_history}
};
#endif //BUILTIN_COMMANDS_H
