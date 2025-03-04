/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** print history
*/


#include <stdlib.h>

#include "env.h"
#include "history.h"
#include "my.h"

void print_each_records(const history_record_t *current_record,
    const int record_index)
{
    if (current_record->next != NULL)
        print_each_records(current_record->next, record_index - 1);
    mini_printf("  %d  %s\n", record_index, current_record->line);
}

int print_history(char **command, const int nb_args, environment_t *envp,
    history_t *history)
{
    history_record_t *current;

    if (command == NULL || nb_args == 0 || envp == NULL ||
        history == NULL || history->records == NULL) {
        return EXIT_FAILURE;
    }
    current = *history->records;
    if (current == NULL)
        return 0;
    print_each_records(current, history->nb_records);
    return 0;
}
