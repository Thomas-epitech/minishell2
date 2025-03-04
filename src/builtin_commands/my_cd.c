/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** change dir
*/

#include <builtin_commands.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "env.h"
#include "history.h"
#include "my.h"

static int change_dir(char *target_dir)
{
    if (chdir(target_dir) == -1) {
        my_putstr_error(target_dir);
        my_putstr_error(": ");
        my_putstr_error(strerror(errno));
        my_putstr_error(".\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static char *get_target_file(char **command, int nb_args, char *old_pwd,
    const environment_t *envp)
{
    env_var_t *home_dir;

    if (nb_args == 1) {
        home_dir = get_env_var(envp, HOME_ENV_VAR);
        if (home_dir == NULL) {
            my_putstr_error("No home directory.\n");
            return NULL;
        }
        return home_dir->value;
    }
    if (my_strcmp(command[1], "-") == 0)
        return old_pwd;
    return command[1];
}

int my_cd(char **command, const int nb_args,
    environment_t *envp, history_t *history)
{
    static char old_pwd[MAX_PATH_LENGTH];
    char tmp[MAX_PATH_LENGTH];
    char *target_file;

    if (command == NULL || envp == NULL || history == NULL)
        return EXIT_FAILURE;
    if (nb_args > 2) {
        my_putstr_error("cd: Too many arguments.\n");
        return EXIT_FAILURE;
    }
    getcwd(tmp, sizeof(old_pwd));
    target_file = get_target_file(command, nb_args, old_pwd, envp);
    if (target_file == NULL)
        return EXIT_FAILURE;
    if (change_dir(target_file) == EXIT_SUCCESS) {
        my_strcpy(old_pwd, tmp);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
