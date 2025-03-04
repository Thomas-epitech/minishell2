/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** test env
*/

#include <criterion/criterion.h>
#include "env.h"

// Normal uses

Test(env, env_creation)
{
    const environment_t *env = create_env();

    cr_assert_eq(env->nb_var, 0);
    cr_assert_not_null(env->variables);
    cr_assert_null(*env->variables);
}

Test(env, add_one_variable)
{
    environment_t* env = create_env();
    env_var_t **variables;

    add_env_var(env, "variable", "value");
    variables = env->variables;
    cr_assert_str_eq((*variables)->var, "variable");
    cr_assert_str_eq((*variables)->value, "value");
    cr_assert_null((*variables)->next);
}

Test(env, add_variables)
{
    environment_t *env = create_env();
    env_var_t *current;

    add_env_var(env, "variable", "value");
    add_env_var(env, "abc", "def");
    add_env_var(env, "123", "456");
    cr_assert_eq(env->nb_var, 3);
    current = *env->variables;
    cr_assert_str_eq(current->var, "variable");
    cr_assert_str_eq(current->value, "value");
    current = current->next;
    cr_assert_str_eq(current->var, "abc");
    cr_assert_str_eq(current->value, "def");
    current = current->next;
    cr_assert_str_eq(current->var, "123");
    cr_assert_str_eq(current->value, "456");
    cr_assert_null(current->next);
}

Test(env, remove_one_variable)
{
    environment_t *env = create_env();

    add_env_var(env, "PATH", "/usr/bin");
    cr_assert_str_eq((*env->variables)->var, "PATH");
    cr_assert_str_eq((*env->variables)->value, "/usr/bin");
    cr_assert_null((*env->variables)->next);
    delete_env_var(env, "PATH");
    cr_assert_null(*env->variables);
}

Test(env, remove_multiple_variables)
{
    environment_t *env = create_env();
    env_var_t *current;

    add_env_var(env, "var1", "val1");
    add_env_var(env, "var2", "val2");
    add_env_var(env, "var3", "val3");
    add_env_var(env, "var4", "val4");
    add_env_var(env, "var5", "val5");
    delete_env_var(env, "var2");
    delete_env_var(env, "var1");
    delete_env_var(env, "var5");
    current = *env->variables;
    cr_assert_str_eq(current->var, "var3");
    cr_assert_str_eq(current->value, "val3");
    cr_assert_not_null(current->next);
    current = current->next;
    cr_assert_str_eq(current->var, "var4");
    cr_assert_str_eq(current->value, "val4");
    cr_assert_null(current->next);
}


Test(env, get_first_variable)
{
    environment_t* env = create_env();
    env_var_t *result;

    add_env_var(env, "var1", "val1");
    add_env_var(env, "var2", "val2");
    add_env_var(env, "var3", "val3");
    add_env_var(env, "var4", "val4");
    add_env_var(env, "var5", "val5");
    result = get_env_var(env, "var1");
    cr_assert_not_null(result);
    cr_assert_str_eq(result->var, "var1");
    cr_assert_str_eq(result->value, "val1");
}

Test(env, get_middle_variable)
{
    environment_t* env = create_env();
    env_var_t *result;

    add_env_var(env, "var1", "val1");
    add_env_var(env, "var2", "val2");
    add_env_var(env, "var3", "val3");
    add_env_var(env, "var4", "val4");
    add_env_var(env, "var5", "val5");
    result = get_env_var(env, "var3");
    cr_assert_not_null(result);
    cr_assert_str_eq(result->var, "var3");
    cr_assert_str_eq(result->value, "val3");
}

Test(env, get_last_variable)
{
    environment_t* env = create_env();
    env_var_t *result;

    add_env_var(env, "var1", "val1");
    add_env_var(env, "var2", "val2");
    add_env_var(env, "var3", "val3");
    add_env_var(env, "var4", "val4");
    add_env_var(env, "var5", "val5");
    result = get_env_var(env, "var5");
    cr_assert_not_null(result);
    cr_assert_str_eq(result->var, "var5");
    cr_assert_str_eq(result->value, "val5");
}

Test(env, array_to_linked_list)
{
    environment_t *env;
    env_var_t *current;
    char *env_array[] = {
        "var1=val1",
        "var2=val2",
        "var3=val3",
        "var4=val4",
        "var5=val5",
        NULL
    };

    env = get_env_as_ll(env_array);
    current = *env->variables;
    cr_assert_not_null(current);
    cr_assert_str_eq(current->var, "var1");
    cr_assert_str_eq(current->value, "val1");
    cr_assert_not_null(current->next);
    current = current->next;
    cr_assert_str_eq(current->var, "var2");
    cr_assert_str_eq(current->value, "val2");
    cr_assert_not_null(current->next);
    current = current->next;
    cr_assert_str_eq(current->var, "var3");
    cr_assert_str_eq(current->value, "val3");
    cr_assert_not_null(current->next);
    current = current->next;
    cr_assert_str_eq(current->var, "var4");
    cr_assert_str_eq(current->value, "val4");
    cr_assert_not_null(current->next);
    current = current->next;
    cr_assert_str_eq(current->var, "var5");
    cr_assert_str_eq(current->value, "val5");
    cr_assert_null(current->next);
}

Test(env, linked_list_to_array)
{
    environment_t *env = create_env();
    char **env_array;

    add_env_var(env, "var1", "val1");
    add_env_var(env, "var2", "val2");
    add_env_var(env, "var3", "val3");
    add_env_var(env, "var4", "val4");
    add_env_var(env, "var5", "val5");
    env_array = get_env_as_array(env);
    cr_assert_not_null(env_array);
    cr_assert_str_eq(env_array[0], "var1=val1");
    cr_assert_str_eq(env_array[1], "var2=val2");
    cr_assert_str_eq(env_array[2], "var3=val3");
    cr_assert_str_eq(env_array[3], "var4=val4");
    cr_assert_str_eq(env_array[4], "var5=val5");
}

Test(env, free_empty_env)
{
    environment_t *env = create_env();

    free_env(env);
}

Test(env, free_env_one_var)
{
    environment_t *env = create_env();

    add_env_var(env, "var1", "val1");
    free_env(env);
}

Test(env, free_env_multiple_vars)
{
    environment_t *env = create_env();

    add_env_var(env, "var1", "val1");
    add_env_var(env, "var2", "val2");
    add_env_var(env, "var3", "val3");
    add_env_var(env, "var4", "val4");
    add_env_var(env, "var5", "val5");
    free_env(env);
}

Test(env, syntax_check_basic)
{
    cr_assert(check_env_var_syntax("VARIABLE"));
}

Test(env, syntax_digit_at_beginning)
{
    cr_assert_not(check_env_var_syntax("1TEST"));
}

Test(env, syntax_underscore_at_beginning)
{
    cr_assert(check_env_var_syntax("_VAR"));
}

Test(env, syntax_period_in_the_middle)
{
    cr_assert(check_env_var_syntax("VAR.IABLE"));
}

Test(env, syntax_period_in_the_beginning)
{
    cr_assert_not(check_env_var_syntax(".VARIABLE"));
}

Test(env, syntax_invalid_character)
{
    cr_assert_not(check_env_var_syntax("a.b@c.fr"));
}

// Error handling

Test(env, add_with_null_env)
{
    add_env_var(NULL, "var", "val");
}

Test(env, add_with_null_var)
{
    environment_t *env = create_env();

    add_env_var(env, NULL, "val");
    cr_assert_null(*env->variables);
}

Test(env, add_with_null_val)
{
    environment_t *env = create_env();

    add_env_var(env, "var", NULL);
    cr_assert_null(*env->variables);
}

Test(env, delete_with_null_env)
{
    delete_env_var(NULL, "var");
}

Test(env, delete_with_null_var)
{
    environment_t *env = create_env();

    delete_env_var(env, NULL);
}

Test(env, delete_non_existent_var)
{
    environment_t *env = create_env();
    env_var_t *current;

    add_env_var(env, "var1", "val1");
    add_env_var(env, "var2", "val2");
    delete_env_var(env, "var3");
    current = *env->variables;
    cr_assert_str_eq(current->var, "var1");
    cr_assert_str_eq(current->value, "val1");
    cr_assert_not_null(current->next);
    current = current->next;
    cr_assert_str_eq(current->var, "var2");
    cr_assert_str_eq(current->value, "val2");
    cr_assert_null(current->next);
}

Test(env, get_with_null_env)
{
    cr_assert_null(get_env_var(NULL, "var"));
}

Test(env, get_with_null_var)
{
    const environment_t *env = create_env();

    cr_assert_null(get_env_var(env, NULL));
}

Test(env, get_with_non_existent_var)
{
    environment_t* env = create_env();

    add_env_var(env, "var1", "val1");
    add_env_var(env, "var2", "val2");
    add_env_var(env, "var3", "val3");
    add_env_var(env, "var4", "val4");
    add_env_var(env, "var5", "val5");
    cr_assert_null(get_env_var(env, "var6"));
}

Test(env, array_to_linked_list_null_env)
{
    cr_assert_null(get_env_as_ll(NULL));
}

Test(env, linked_list_to_array_null_env)
{
    cr_assert_null(get_env_as_array(NULL));
}

Test(env, free_with_null_env)
{
    free_env(NULL);
}
