/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** create history
*/

#include <stdlib.h>

#include "history.h"

history_t *create_history(void)
{
    history_t *history = malloc(sizeof(history_t));

    if (history == NULL)
        return NULL;
    history->nb_records = 0;
    history->records = malloc(sizeof(history_record_t *));
    if (history->records == NULL) {
        free(history);
        return NULL;
    }
    *history->records = NULL;
    return history;
}
