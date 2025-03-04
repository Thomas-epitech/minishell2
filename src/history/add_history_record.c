/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** add history record
*/

#include <stdlib.h>

#include "history.h"
#include "my.h"

static history_record_t *create_new_record(const char *command, const int
    return_value)
{
    history_record_t *record = malloc(sizeof(history_record_t));

    if (record == NULL)
        return NULL;
    record->line = my_strdup(command);
    record->exit_status = return_value;
    record->next = NULL;
    return record;
}

void add_history_record(history_t *history, const char *command,
    const int return_value)
{
    history_record_t *new_record;
    history_record_t *previous_record;

    if (history == NULL || command == NULL)
        return;
    new_record = create_new_record(command, return_value);
    if (new_record == NULL)
        return;
    previous_record = *history->records;
    new_record->next = previous_record;
    *history->records = new_record;
    history->nb_records++;
}
