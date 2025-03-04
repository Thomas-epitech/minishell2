/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** get formatted command
*/

#include <stdlib.h>
#include <string.h>

#include "my.h"

static int get_command_len(const char *command)
{
    int count = 0;
    char *cmd_dup = NULL;
    const char *token = NULL;

    if (command == NULL)
        return 0;
    cmd_dup = my_strdup(command);
    token = strtok(cmd_dup, " \t");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t");
    }
    free(cmd_dup);
    return count;
}

char **get_formatted_command(char *command)
{
    int command_len = 0;
    char **formatted_command = NULL;
    const char *token;

    command_len = get_command_len(command);
    if (command_len == 0)
        return NULL;
    formatted_command = malloc(sizeof(char *) * (command_len + 1));
    token = strtok(command, " \t");
    if (formatted_command == NULL)
        return NULL;
    for (int i = 0; token != NULL; i++) {
        formatted_command[i] = my_strdup(token);
        if (formatted_command[i] == NULL)
            return NULL;
        formatted_command[i + 1] = NULL;
        token = strtok(NULL, " \t");
    }
    return formatted_command;
}
