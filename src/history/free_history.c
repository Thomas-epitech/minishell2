/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** delete history
*/

#include <stdlib.h>

#include "history.h"

static void free_records(history_record_t *current_record)
{
    if (current_record->next != NULL)
        free_records(current_record->next);
    free(current_record->line);
    free(current_record);
}

void free_history(history_t *history)
{
    if (history == NULL || history->records == NULL)
        return;
    if (*history->records != NULL)
        free_records(*history->records);
    free(history->records);
    free(history);
}
