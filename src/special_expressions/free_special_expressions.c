/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** free special expressions
*/

#include <stdlib.h>

#include "special_expressions.h"

void free_special_expr(special_expr_t **special_expressions)
{
    if (special_expressions == NULL)
        return;
    for (int i = 0; i < NB_SPECIAL_EXPRESSIONS; i++) {
        free(special_expressions[i]->original_expr);
        free(special_expressions[i]->substitution);
        free(special_expressions[i]->error_message);
        free(special_expressions[i]);
    }
    free(special_expressions);
}
