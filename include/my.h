/*
** EPITECH PROJECT, 2025
** lib
** File description:
** lib header
*/

#ifndef MY_H
    #define MY_H

    #include <stdbool.h>

void free_double_ptr(void **ptr);
bool is_digit(char c);
bool is_letter(char c);
int mini_printf(const char *format, ...);
int my_getnbr(char const *str);
int my_intlen(int nb);
char *my_itoa(int nb);
void my_perror(const char *message, const char *error, bool line_break);
double my_pow(double x, double y);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(const char *str);
void my_putstr_error(const char *str);
double my_sqrt(double x);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *str);
int my_strlen(const char *str);
char *my_strncat(char *dest, const char *src, int n);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strncpy(char *dest, const char *src, int n);
char *my_str_to_lowercase(const char *str);
#endif //MY_H
