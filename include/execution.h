/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** execution header
*/

#ifndef EXECUTION_H
    #define EXECUTION_H
    #include <stdbool.h>

    #include "env.h"
    #include "history.h"
    #include "special_expressions.h"

    #define PATH_ENV_VAR "PATH"

int check_for_builtin_commands(char **formatted_command, environment_t *envp,
    history_t *history);
int execute(const char *executable_path, char **args, const environment_t
    *envp);
char *get_binary(char *command, const environment_t *envp);
char **get_formatted_command(char *command);
int handle_execution(const char *command, environment_t *envp,
    history_t *history, special_expr_t **special_expressions);
bool is_path(char *command);

#endif //EXECUTION_H
