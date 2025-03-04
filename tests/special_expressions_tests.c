/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** special expressions tests
*/

#include <criterion/criterion.h>

#include "my.h"
#include "special_expressions.h"

special_expr_t **init(void)
{
    special_expr_t **special_expr = malloc(sizeof(special_expr_t *) * (NB_SPECIAL_EXPRESSIONS + 1));
    const special_expr_t expressions[] = {
        {"~", "homedir", HOME_ENV_ERR},
        {"$?", "last_exit", LAST_EXIT_ERR},
        {"!!", "last_record", LAST_CMD_ERR}
    };

    for (int i = 0; i < NB_SPECIAL_EXPRESSIONS; i++) {
        special_expr[i] = malloc(sizeof(special_expr_t));
        special_expr[i]->original_expr = my_strdup(expressions[i].original_expr);
        special_expr[i]->substitution = my_strdup(expressions[i].substitution);
        special_expr[i]->error_message = my_strdup(expressions[i].error_message);
    }
    special_expr[NB_SPECIAL_EXPRESSIONS] = NULL;
    return special_expr;
}

Test(special_expressions, no_special_expression)
{
    special_expr_t **expr = init();
    char *command = "This is a command";
    char *result = handle_special_expr(my_strdup(command), expr);

    cr_assert_str_eq(command, result);
    free(result);
}

Test(special_expressions, special_expression_not_at_the_begining)
{
    special_expr_t **expr = init();
    char *command = "cd /~/";
    char *result = handle_special_expr(my_strdup(command), expr);

    cr_assert_str_eq(command, result);
    free(result);
    free_special_expr(expr);
}

Test(special_expressions, one_special_expression)
{
    special_expr_t **expr = init();
    char *command = "cd ~/Downloads";
    char *result = handle_special_expr(my_strdup(command), expr);

    cr_assert_str_eq("cd homedir/Downloads", result);
    free(result);
    free_special_expr(expr);
}
