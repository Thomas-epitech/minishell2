/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my env header
*/

#ifndef MY_ENV_H
    #define MY_ENV_H

    #define HOME_ENV_VAR "HOME"

    #include <stdbool.h>

typedef struct env_var {
    char *var;
    char *value;
    struct env_var *next;
} env_var_t;

typedef struct {
    int nb_var;
    env_var_t **variables;
} environment_t;

void add_env_var(environment_t *environment, const char *var,
    const char *value);
bool check_env_var_syntax(const char *var);
environment_t *create_env(void);
void delete_env_var(environment_t *environment, const char *var);
void free_env(environment_t *env);
void free_env_var(env_var_t *env_var);
char **get_env_as_array(const environment_t *env);
environment_t *get_env_as_ll(char **envp);
env_var_t *get_env_var(const environment_t *env, const char *name);
#endif //MY_ENV_H
