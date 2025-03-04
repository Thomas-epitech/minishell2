/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** execution tests
*/

#include <criterion/criterion.h>

#include "env.h"
#include "execution.h"

// get_binary() TESTS

environment_t *env;

void env_init(void)
{
    env = malloc(sizeof(environment_t));
    env->nb_var = 1;
    *env->variables = malloc(sizeof(env_var_t));
    (*env->variables)->var = "PATH";
    (*env->variables)->value = "/usr/local/sbin:/usr/local/bin:/usr/bin:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl";
    (*env->variables)->next = NULL;
}

TestSuite(get_binary, .init = env_init);

Test(get_binary, command)
{
    cr_assert_str_eq(get_binary("ls", env), "/usr/bin/ls");
}

Test(get_binary, another_command)
{
    cr_assert_str_eq(get_binary("pwd", env), "/usr/bin/pwd");
}

// get_formatted_command() TESTS

Test(get_formatted_command, basic_command)
{
    char *command = "setenv var val";
    char **formatted_command = get_formatted_command(strdup(command));

    cr_assert_not_null(formatted_command);
    cr_assert_str_eq(formatted_command[0], "setenv");
    cr_assert_str_eq(formatted_command[1], "var");
    cr_assert_str_eq(formatted_command[2], "val");
}

Test(get_formatted_command, empty_command)
{
    char *command = "";
    char **formatted_command = get_formatted_command(strdup(command));

    cr_assert_null(formatted_command);
}

// is_path() TESTS


Test(is_path, empty_string)
{
    cr_assert_not(is_path(""));
}

Test(is_path, slash_at_beginning)
{
    cr_assert(is_path("/home"));
}

Test(is_path, slash_at_end)
{
    cr_assert(is_path("../"));
}

Test(is_path, slash_in_midde)
{
    cr_assert(is_path("../.."));
}

Test(is_path, no_slash)
{
    cr_assert_not(is_path("file"));
}

Test(is_path, null_string)
{
    cr_assert_not(is_path(NULL));
}
