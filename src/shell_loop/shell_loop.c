/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** shell loop
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "execution.h"
#include "history.h"
#include "my.h"
#include "shell_loop.h"
#include "special_expressions.h"


static void cleanup(char *input, special_expr_t **special_expressions)
{
    free(input);
    free_special_expr(special_expressions);
}

static void print_prompt(void)
{
    if (isatty(0))
        mini_printf("$> ");
}

static void handle_sigint([[maybe_unused]] int signal)
{
    mini_printf("\n");
    print_prompt();
}

static char *get_input(void)
{
    char *input = NULL;
    size_t input_size = 0;
    int input_len;

    signal(SIGINT, handle_sigint);
    print_prompt();
    if (getline(&input, &input_size, stdin) == -1)
        return NULL;
    input_len = my_strlen(input);
    if (input[input_len - 1] == '\n')
        input[input_len - 1] = '\0';
    return input;
}

static bool is_empty_command(const char *command)
{
    for (int i = 0; command[i] != '\0'; i++)
        if (command[i] != ' ' && command[i] != '\t')
            return false;
    return true;
}

int shell_loop(environment_t *envp, history_t *hist)
{
    char *input = get_input();
    special_expr_t **special_expressions = NULL;

    while (input != NULL && my_strcmp(input, "exit") != 0) {
        special_expressions = get_special_expr(envp, hist);
        if (special_expressions == NULL || my_strlen(input) == 0 ||
            is_empty_command(input)) {
            cleanup(input, special_expressions);
            input = get_input();
            continue;
        }
        add_history_record(hist, input,
            handle_execution(input, envp, hist, special_expressions));
        cleanup(input, special_expressions);
        input = get_input();
    }
    free(input);
    return *hist->records == NULL ? 0 : (*hist->records)->exit_status;
}
