/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my_perror
*/

#include <errno.h>
#include <string.h>

#include "my.h"

void my_perror(const char *message, const char *error, const bool line_break)
{
    my_putstr_error(message);
    my_putstr_error(": ");
    my_putstr_error(error);
    my_putstr_error(".");
    if (line_break)
        my_putstr_error("\n");
}
