/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** main
*/

#include <signal.h>

#include "env.h"
#include "history.h"
#include "shell_loop.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv, char **envp)
{
    environment_t *my_envp = get_env_as_ll(envp);
    history_t *history = create_history();
    const int last_exit_status = shell_loop(my_envp, history);

    free_env(my_envp);
    free_history(history);
    return last_exit_status;
}
