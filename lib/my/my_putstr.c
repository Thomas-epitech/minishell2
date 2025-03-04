/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my putstr
*/

#include <unistd.h>

#include "my.h"

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
