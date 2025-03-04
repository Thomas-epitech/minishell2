/*
** EPITECH PROJECT, 2025
** lib
** File description:
** special expressions header
*/

#ifndef SPECIAL_EXPRESSIONS_H
    #define SPECIAL_EXPRESSIONS_H

    #define NB_SPECIAL_EXPRESSIONS 3

    #define HOME_ENV_ERR "No $home variable set.\n"
    #define LAST_EXIT_ERR "Cannot access to last exit.\n"
    #define LAST_CMD_ERR "0: Event not found.\n"


    #include "env.h"
    #include "history.h"

typedef struct {
    char *original_expr;
    char *substitution;
    char *error_message;
} special_expr_t;

special_expr_t *find_special_expr(const char *expression,
    special_expr_t **special_expressions);
void free_special_expr(special_expr_t **special_expressions);
special_expr_t **get_special_expr(const environment_t *envp,
    const history_t *history);
int get_translated_string_size(char *command,
    special_expr_t **special_expressions);
char *handle_special_expr(char *command, special_expr_t **special_expressions);
#endif //SPECIAL_EXPRESSIONS_H
