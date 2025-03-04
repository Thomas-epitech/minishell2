/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** handle execution
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtin_commands.h"
#include "execution.h"
#include "my.h"
#include "special_expressions.h"

static int get_builtin_command_index(const char *command)
{
    for (int i = 0; i < NB_BUILTIN_COMMANDS; i++)
        if (my_strcmp(builtin_commands[i].command, command) == 0)
            return i;
    return -1;
}

static char *get_binary_path(char **formatted_command, environment_t *envp)
{
    char *binary_path;

    if (formatted_command == NULL)
        return NULL;
    if (is_path(formatted_command[0])) {
        if (access(formatted_command[0], F_OK) != 0) {
            my_perror(formatted_command[0], "Command not found", true);
            return NULL;
        }
        return my_strdup(formatted_command[0]);
    }
    if (get_builtin_command_index(formatted_command[0]) != -1)
        return NULL;
    binary_path = get_binary(formatted_command[0], envp);
    if (binary_path == NULL) {
        mini_printf("%s: Command not found.\n", formatted_command[0]);
        return NULL;
    }
    return binary_path;
}

static int get_nb_args(char **formatted_command)
{
    int count = 0;

    if (formatted_command == NULL)
        return 0;
    for (int i = 0; formatted_command[i] != NULL; i++) {
        count++;
    }
    return count;
}

static int handle_builtin_commands(char **formatted_command,
    environment_t *envp, history_t *history)
{
    const int builtin_command_index =
        get_builtin_command_index(formatted_command[0]);
    const int nb_args = get_nb_args(formatted_command);

    if (builtin_command_index == -1)
        return EXIT_FAILURE;
    return builtin_commands[builtin_command_index].associated_function(
        formatted_command, nb_args, envp, history);
}

static int handle_external_commands(char **formatted_command,
    char *binary_path, environment_t *envp)
{
    if (formatted_command == NULL || binary_path == NULL)
        return EXIT_FAILURE;
    if (access(binary_path, X_OK) != 0) {
        my_perror(binary_path, strerror(errno), true);
        return EXIT_FAILURE;
    }
    return execute(binary_path, formatted_command, envp);
}

static void cleanup(char **formatted_command, char *binary_path,
    char *command_cpy, char *translated_command)
{
    free_double_ptr((void **) formatted_command);
    free(binary_path);
    free(command_cpy);
    free(translated_command);
}

int handle_execution(const char *command, environment_t *envp,
    history_t *history, special_expr_t **special_expr)
{
    char **formatted_command;
    char *binary_path;
    int exit_status;
    char *command_cpy = my_strdup(command);
    char *translated_command = handle_special_expr(command_cpy, special_expr);

    free(command_cpy);
    if (translated_command == NULL)
        return EXIT_FAILURE;
    command_cpy = my_strdup(translated_command);
    formatted_command = get_formatted_command(command_cpy);
    binary_path = get_binary_path(formatted_command, envp);
    if (binary_path != NULL)
        exit_status = handle_external_commands(formatted_command, binary_path,
            envp);
    else
        exit_status = handle_builtin_commands(formatted_command, envp,
            history);
    cleanup(formatted_command, binary_path, command_cpy, translated_command);
    return exit_status;
}
