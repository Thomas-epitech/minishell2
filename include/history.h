/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** history header
*/

#ifndef HISTORY_H
    #define HISTORY_H

    #include "env.h"

typedef struct history_record {
    char *line;
    int exit_status;
    struct history_record *next;
} history_record_t;

typedef struct {
    history_record_t **records;
    int nb_records;
} history_t;

history_t *create_history(void);
void add_history_record(history_t *history, const char *command,
    int return_value);
void free_history(history_t *history);
int print_history(char **command, int nb_args, environment_t *envp,
    history_t *history);
#endif //HISTORY_H
