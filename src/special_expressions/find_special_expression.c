/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** find special expressions
*/

#include <stddef.h>

#include "my.h"
#include "special_expressions.h"

special_expr_t *find_special_expr(const char *expression,
    special_expr_t **special_expressions)
{
    char *original;

    for (int i = 0; special_expressions[i] != NULL; i++) {
        original = special_expressions[i]->original_expr;
        if (my_strncmp(original, expression, my_strlen(original)) == 0)
            return special_expressions[i];
    }
    return NULL;
}
