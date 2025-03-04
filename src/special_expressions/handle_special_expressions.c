/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** handle special expressions
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "my.h"
#include "special_expressions.h"

static void append_to_str(char *dest, char *src, bool *first_append,
    const int n)
{
    if (*first_append) {
        my_strncpy(dest, src, n);
        *first_append = false;
    } else
        my_strncat(dest, src, n);
}

static void append_special_expr(char *token, char *translated_string,
    const special_expr_t *special_expr, bool *first_append)
{
    int substitution_len;
    int original_expr_len;

    if (token == NULL || translated_string == NULL || special_expr == NULL)
        return;
    substitution_len = my_strlen(special_expr->substitution);
    original_expr_len = my_strlen(special_expr->original_expr);
    append_to_str(translated_string, special_expr->substitution,
        first_append, substitution_len);
    append_to_str(translated_string, token + original_expr_len,
        first_append, my_strlen(token) - original_expr_len);
}

static void fill_translated_string(char *command, char *translated_string,
    special_expr_t **special_expressions)
{
    special_expr_t *special_expr;
    char *token = strtok(command, " \t");
    bool first_append = true;

    while (token != NULL) {
        special_expr = find_special_expr(token, special_expressions);
        if (special_expr == NULL)
            append_to_str(translated_string, token, &first_append,
                my_strlen(token));
        else
            append_special_expr(token, translated_string, special_expr,
                &first_append);
        token = strtok(NULL, " \t");
        if (token != NULL)
            append_to_str(translated_string, " ", &first_append, 1);
    }
}

char *handle_special_expr(char *command, special_expr_t **special_expressions)
{
    char *translated_string = NULL;
    int str_len;
    char *command_cpy = my_strdup(command);

    if (command == NULL || special_expressions == NULL)
        return NULL;
    str_len = get_translated_string_size(command_cpy, special_expressions);
    if (str_len == -1) {
        free(command_cpy);
        return NULL;
    }
    translated_string = malloc(sizeof(char) * (str_len + 1));
    fill_translated_string(command, translated_string, special_expressions);
    free(command_cpy);
    return translated_string;
}
