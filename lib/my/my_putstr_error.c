/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my_putstr_error
*/

#include <unistd.h>

#include "my.h"

void my_putstr_error(const char *str)
{
    write(2, str, my_strlen(str));
}
