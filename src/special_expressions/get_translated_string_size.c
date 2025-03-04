/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** handle special expressions
*/

#include <string.h>

#include "my.h"
#include "special_expressions.h"

static int get_translated_token_size(char *token,
    special_expr_t **special_expressions)
{
    special_expr_t *special_expr =
        find_special_expr(token, special_expressions);

    if (special_expr == NULL)
        return my_strlen(token);
    if (special_expr->substitution == NULL) {
        mini_printf("%s", special_expr->error_message);
        return -1;
    }
    return my_strlen(special_expr->substitution) +
        (my_strlen(token) - my_strlen(special_expr->original_expr));
}

int get_translated_string_size(char *command,
    special_expr_t **special_expressions)
{
    int size = 0;
    char *token = strtok(command, " \t");
    int token_size = 0;

    while (token != NULL) {
        token_size = get_translated_token_size(token, special_expressions);
        if (token_size == -1)
            return -1;
        size += token_size + (size == 0 ? 0 : 1);
        token = strtok(NULL, " \t");
    }
    return size;
}
