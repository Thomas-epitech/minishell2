/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** get special expressions
*/

#include <stdlib.h>

#include "env.h"
#include "history.h"
#include "my.h"
#include "special_expressions.h"

static char *get_home_directory(const environment_t *envp)
{
    const env_var_t *home_var = get_env_var(envp, HOME_ENV_VAR);

    if (home_var == NULL)
        return NULL;
    return home_var->value;
}

static history_record_t *get_last_history_record(const history_t *history)
{
    if (history == NULL || history->records == NULL)
        return NULL;
    return *history->records;
}

static void fill_expressions_array(special_expr_t **special_expressions,
    char *home_directory, const history_record_t *last_record)
{
    char *last_exit_status_str = my_itoa(last_record == NULL ? 0 :
        last_record->exit_status);
    const special_expr_t expressions[] = {
        {"~", home_directory, HOME_ENV_ERR},
        {"$?", last_exit_status_str, LAST_EXIT_ERR},
        {"!!", last_record == NULL ? NULL : last_record->line, LAST_CMD_ERR}
    };

    for (int i = 0; i < NB_SPECIAL_EXPRESSIONS; i++) {
        special_expressions[i]->original_expr =
            my_strdup(expressions[i].original_expr);
        special_expressions[i]->substitution = expressions[i].substitution ==
            NULL ? NULL : my_strdup(expressions[i].substitution);
        special_expressions[i]->error_message =
            my_strdup(expressions[i].error_message);
    }
    special_expressions[NB_SPECIAL_EXPRESSIONS] = NULL;
    free(last_exit_status_str);
}

special_expr_t **get_special_expr(const environment_t *envp,
    const history_t *history)
{
    char *home_directory = get_home_directory(envp);
    const history_record_t *last_history_record =
        get_last_history_record(history);
    special_expr_t **special_expressions =
        malloc(sizeof(special_expr_t *) * (NB_SPECIAL_EXPRESSIONS + 1));

    if (special_expressions == NULL)
        return NULL;
    for (int i = 0; i < NB_SPECIAL_EXPRESSIONS; i++)
        special_expressions[i] = malloc(sizeof(special_expr_t));
    fill_expressions_array(special_expressions, home_directory,
        last_history_record);
    return special_expressions;
}
