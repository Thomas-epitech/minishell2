/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** execute
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "env.h"
#include "my.h"
#include "sigint_handling.h"
#include "signal_messages.h"

static void handle_signal(const int status)
{
    int sig;

    if (!WIFSIGNALED(status) || interrupted)
        return;
    sig = WTERMSIG(status);
    my_putstr_error(get_signal_message(sig));
    if (WCOREDUMP(status))
        my_putstr_error(" (core dumped)\n");
    else
        my_putstr_error("\n");
}

static int get_exit_status(const int status)
{
    if (interrupted)
        return EXIT_FAILURE;
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status))
        return WTERMSIG(status) + 128;
    return -1;
}

static void handle_sigint([[maybe_unused]] int sig)
{
    kill(child_pid, SIGINT);
    interrupted = true;
    mini_printf("\n");
}

static void print_execve_error(const char *executable_path)
{
    if (errno == ENOEXEC) {
        my_perror(executable_path, strerror(errno), false);
        my_putstr_error(" Binary file not executable.\n");
    } else
        my_perror(executable_path, strerror(errno), true);
}

int execute(const char *executable_path, char **args, const environment_t
    *envp)
{
    char **envp_array;
    int status;

    if (executable_path == NULL || args == NULL || envp == NULL)
        return EXIT_FAILURE;
    interrupted = false;
    envp_array = get_env_as_array(envp);
    child_pid = fork();
    if (child_pid == -1)
        return -1;
    signal(SIGINT, handle_sigint);
    if (child_pid == 0) {
        execve(executable_path, args, envp_array);
        print_execve_error(executable_path);
        exit(EXIT_FAILURE);
    }
    waitpid(child_pid, &status, 0);
    handle_signal(status);
    free_double_ptr((void **) envp_array);
    return get_exit_status(status);
}
