/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** is path
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

bool is_path(const char *command)
{
    if (command == NULL)
        return false;
    for (int i = 0; command[i] != '\0'; i++)
        if (command[i] == '/')
            return true;
    return false;
}
