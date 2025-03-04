/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** test history
*/

#include <criterion/criterion.h>

#include "history.h"

// Normal uses

Test(history, create_history)
{
    const history_t *history = create_history();

    cr_assert_not_null(history);
    cr_assert_not_null(history->records);
    cr_assert_null(*history->records);
    cr_assert_eq(history->nb_records, 0);
}

Test(history, add_one_record)
{
    history_t *history = create_history();

    cr_assert_not_null(history);
    add_history_record(history, "ls -l", 0);
    cr_assert_eq(history->nb_records, 1);
    cr_assert_str_eq((*history->records)->line, "ls -l");
    cr_assert_eq((*history->records)->exit_status, 0);
    cr_assert_null((*history->records)->next);
}

Test(history, add_multiple_records)
{
    history_t* history = create_history();
    history_record_t *current_record;

    cr_assert_not_null(history);
    add_history_record(history, "ls -l", 0);
    add_history_record(history, "cd not_a_dir", 1);
    add_history_record(history, "./send_sig 11", 139);
    current_record = *history->records;
    cr_assert_not_null(current_record);
    cr_assert_str_eq(current_record->line, "./send_sig 11");
    cr_assert_eq(current_record->exit_status, 139);
    cr_assert_not_null(current_record->next);
    current_record = current_record->next;
    cr_assert_str_eq(current_record->line, "cd not_a_dir");
    cr_assert_eq(current_record->exit_status, 1);
    cr_assert_not_null(current_record->next);
    current_record = current_record->next;
    cr_assert_str_eq(current_record->line, "ls -l");
    cr_assert_eq(current_record->exit_status, 0);
    cr_assert_null(current_record->next);
}

Test(history, free_empty_history)
{
    history_t* history = create_history();

    free_history(history);
}

Test(history, free_history)
{
    history_t* history = create_history();

    add_history_record(history, "ls -l", 0);
    add_history_record(history, "cd not_a_dir", 1);
    free_history(history);
}

// Error handling

Test(history, add_with_null_history)
{
    add_history_record(NULL, "ls -l", 0);
}

Test(history, add_with_null_command)
{
    history_t* history = create_history();

    cr_assert_not_null(history);
    add_history_record(history, NULL, 0);
}

Test(history, free_with_null_history)
{
    free_history(NULL);
}
